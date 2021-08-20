#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "define_constants.h"
#include "aluno.h"


L_ALUNO *criar_lista_aluno(){

	L_ALUNO *head = (L_ALUNO*) malloc(sizeof(L_ALUNO));

	if(head != NULL)
	{
		(*head) = NULL;
	}
	else
	{
		printf("SEM MEMORIA DISPONIVEL\n\n");
	}

	return head;
}

void inserir_aluno(ALUNO *novo, L_ALUNO *head){

	if((*head) == NULL)
	{
		(*head) = novo;
		novo->prox = NULL;
	}
	else
	{
		ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));
		ALUNO *ant = (ALUNO*) malloc(sizeof(ALUNO));

		if(aux != NULL && ant != NULL)
		{
			aux = (*head);

			while(aux != NULL && strcmp(novo->dados.nome, aux->dados.nome) == 1)
			{
				ant = aux;
				aux = aux->prox;
			}

			if(aux == (*head))
			{
				novo->prox = (*head);
				(*head) = novo;
			}
			else
			{
				novo->prox = ant->prox;
				ant->prox = novo;
			}
		}
	}
}

int cadastros_aluno(ALUNO *aluno, L_ALUNO *head, HWND janela){

	unsigned int x = 1;

	ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));

	if(aux != NULL)
	{
		aux = (*head);

		while(aux != NULL)
		{
			if(aluno->dados.cod == aux->dados.cod || strcmp(aluno->dados.cpf, aux->dados.cpf) == 0)
			{
				x = 0;
				break;
			}

			aux = aux->prox;
		}

		if(x == 0)
		{
			MessageBoxW(janela, L"MATRICULA E/OU CPF JA CADASTRADO(S) PARA OUTRO ALUNO!", L"ALUNO NAO CADASTRADO", MB_OK | MB_ICONERROR);
		}
	}

	aux = NULL;
	free(aux);

	return x;
}

void dados_aluno(ALUNO *aluno, HWND hnome, HWND hcpf, HWND hcurso, HWND hcod){
	
	char cod[15];
	
	GetWindowText(hnome, aluno->dados.nome, 50);
    GetWindowText(hcurso, aluno->dados.curso, 50);
    GetWindowText(hcpf, aluno->dados.cpf, 15);
    GetWindowText(hcod, cod, 15);

    aluno->dados.cod = atoi(cod);
}

void cadastrar_aluno(L_ALUNO *head, HWND jnl,  HWND hnome, HWND hcpf, HWND hcurso, HWND hcod){

	ALUNO *novo = (ALUNO*) malloc(sizeof(ALUNO));

    char cod[15];

	if(novo != NULL)
	{
		dados_aluno(novo, hnome, hcpf, hcurso, hcod);
		GetWindowText(hcod, cod, 15);

        if(strcmp(novo->dados.nome, "") == 0 || strcmp(novo->dados.curso, "") == 0 || strcmp(novo->dados.cpf, "") == 0 || strcmp(cod, "") == 0)
        {
            MessageBoxW(jnl, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
        }
        else if(novo->dados.cod == 0 || novo->dados.cpf == 0)
        {
        	MessageBoxW(jnl, L"Insira apenas numeros em matricula e cpf", L"ERRO", MB_OK | MB_ICONERROR);
		}
        else if(cadastros_aluno(novo, head, jnl) != 0)
		{
			inserir_aluno(novo, head);
			MessageBoxW(jnl, L"Aluno Cadastrado!", L"Cadastro", MB_OK | MB_ICONINFORMATION);
		}
	}

	novo = NULL;
	free(novo);
}

ALUNO *busca_aluno(int cod, L_ALUNO *head, HWND janela){
	
	int x = 0;
	
	ALUNO *lista = (ALUNO*) malloc(sizeof(ALUNO));
	ALUNO *ant = (ALUNO*) malloc(sizeof(ALUNO));
	ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));

	if(lista != NULL && ant != NULL && aux != NULL)
	{
		lista = (*head);

		while(lista != NULL)
		{
			if(lista->dados.cod == cod)
			{
				aux = lista;

				if(lista == (*head))
				{
					(*head) = lista->prox;
				}
				else
				{
					ant->prox = lista->prox;
				}
				
				x++;
				
				break;
			}

			ant = lista;
			lista = lista->prox;
		}
	}

	if(x == 0)
	{
		MessageBoxW(janela, L"ALUNO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
		aux = NULL;
	}

	return aux;
}

void lista_aluno(L_ALUNO *head, char *lista){

	char cod[11], pos[10];
	int i = 1;
	
	ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			sprintf(pos, "%d", i);
		    sprintf(cod, "%d", aux->dados.cod);
		    
			strcat(lista, "\r\n");
			strcat(lista, "\t\tALUNO ");
			strcat(lista, pos);
		    strcat(lista, "\r\n");
		    strcat(lista, "\r\n");
		    strcat(lista, "\tNOME: ");
		    strcat(lista, aux->dados.nome);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCPF: ");
		    strcat(lista, aux->dados.cpf);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCURSO: ");
		    strcat(lista, aux->dados.curso);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tMATRICULA: ");
		    strcat(lista, cod);
		    strcat(lista, "\r\n");
		    strcat(lista, "\r\n");
			strcat(lista, "-------------------------------------------------------------------------------------");
			
			aux = aux->prox;
			i++;
		}
	}
	
	if(i == 1)
	{
		strcpy(lista,"\r\n\r\n\r\n\tLISTA VAZIA!");
	}
}

void exclui_aluno(L_ALUNO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));
	
	if(aluno != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		aluno = busca_aluno(cod, head, janela);
	}
	
	aluno = NULL;
	free(aluno);
}

void libera_lista_aluno(L_ALUNO *head){

    ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));

    if(aux != NULL)
    {
	    while((*head) != NULL)
	    {
	        aux = (*head);
	        (*head) = (*head)->prox;
	        free(aux);
	    }
	}

    free(head);
}
