#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "define_constants.h"
#include "supervisor.h"


L_SUPERVISOR *criar_lista_supervisor(){

	L_SUPERVISOR *head = (L_SUPERVISOR*) malloc(sizeof(L_SUPERVISOR));

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

void inserir_supervisor(SUPERVISOR *novo, L_SUPERVISOR *head){

	unsigned int i;

	i = 0;

	if((*head) == NULL)
	{
		(*head) = novo;
		novo->prox = NULL;
	}
	else
	{
		SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
		SUPERVISOR *ant = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

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

int cadastros_supervisor(SUPERVISOR *supervisor, L_SUPERVISOR *head, HWND jnl){

	unsigned int x = 1;

	SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

	if(aux != NULL)
	{
		aux = (*head);

		while(aux != NULL)
		{
			if(supervisor->dados.cod == aux->dados.cod)
			{
				x = 0;
				break;
			}

			aux = aux->prox;
		}

		if(x == 0)
		{
			MessageBoxW(jnl, L"CODIGO JA CADASTRADO PARA OUTRO SUPERVISOR!", L"SUPERVISOR NAO CADASTRADO", MB_OK | MB_ICONERROR);
		}
	}

	aux = NULL;
	free(aux);

	return x;
}

void dados_supervisor(SUPERVISOR *supervisor, HWND hnome, HWND hcurso, HWND hcod){
	
	char cod[15];
	
	GetWindowText(hnome, supervisor->dados.nome, 50);
    GetWindowText(hcurso, supervisor->dados.curso, 50);
    GetWindowText(hcod, cod, 15);

    supervisor->dados.cod = atoi(cod);
}

void cadastrar_supervisor(L_SUPERVISOR *head, HWND janela, HWND hnome, HWND hcurso, HWND hcod){

	SUPERVISOR *novo = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	char cod[15];
	
	if(novo != NULL)
	{
		dados_supervisor(novo, hnome, hcurso, hcod);
        GetWindowText(hcod, cod, 15);

        if(strcmp(novo->dados.nome, "") == 0 || strcmp(novo->dados.curso, "") == 0 || strcmp(cod, "") == 0)
        {
            MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
        }
        else if(novo->dados.cod == 0)
        {
        	MessageBoxW(janela, L"Insira apenas numeros em codigo", L"ERRO", MB_OK | MB_ICONERROR);
		}
        else if(cadastros_supervisor(novo, head, janela) != 0)
		{
			inserir_supervisor(novo, head);
			MessageBoxW(janela, L"Supervisor Cadastrado!", L"Cadastro", MB_OK | MB_ICONINFORMATION);
		}
	}

	novo = NULL;
	free(novo);
}

SUPERVISOR *busca_supervisor(int cod, L_SUPERVISOR *head, HWND janela){
	
	int x = 0;
	
	SUPERVISOR *lista = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	SUPERVISOR *ant = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

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
		MessageBoxW(janela, L"SUPERVISOR NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
		aux = NULL;
	}

	return aux;
}

void lista_supervisor(L_SUPERVISOR *head, char *lista){
		
	char cod[11], pos[10];
	int i = 1;
	
	SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			sprintf(pos, "%d", i);
		    sprintf(cod, "%d", aux->dados.cod);
		    
			strcat(lista, "\r\n");
			strcat(lista, "\t\tSUPERVISOR ");
			strcat(lista, pos);
		    strcat(lista, "\r\n");
		    strcat(lista, "\r\n");
		    strcat(lista, "\tNOME: ");
		    strcat(lista, aux->dados.nome);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCODIGO: ");
		    strcat(lista, cod);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCURSO: ");
		    strcat(lista, aux->dados.curso);
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

void exclui_supervisor(L_SUPERVISOR *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	if(supervisor != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		supervisor = busca_supervisor(cod, head, janela);
	}
	
	supervisor = NULL;
	free(supervisor);
}

void libera_lista_supervisor(L_SUPERVISOR *head){

    SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

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
