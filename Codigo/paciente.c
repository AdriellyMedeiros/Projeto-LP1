#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "define_constants.h"
#include "paciente.h"


L_PACIENTE *criar_lista_paciente(){

	L_PACIENTE *head = (L_PACIENTE*) malloc(sizeof(L_PACIENTE));

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

void inserir_paciente(PACIENTE *novo, L_PACIENTE *head){

	if((*head) == NULL)
	{
		(*head) = novo;
		novo->prox = NULL;
	}
	else
	{
		PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));
		PACIENTE *ant = (PACIENTE*) malloc(sizeof(PACIENTE));

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

int cadastros_paciente(PACIENTE *paciente, L_PACIENTE *head, HWND janela){

	unsigned int x = 1;

	PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));

	if(aux != NULL)
	{
		aux = (*head);

		while(aux != NULL)
		{
			if(strcmp(paciente->dados.cpf,aux->dados.cpf) == 0)
			{
				x = 0;
				break;
			}

			aux = aux->prox;
		}

		if(x == 0)
		{
			MessageBoxW(janela, L"CPF JA CADASTRADO PARA OUTRO PACIENTE!", L"PACIENTE NAO CADASTRADO", MB_OK | MB_ICONERROR);
		}
	}

	aux = NULL;
	free(aux);

	return x;
}

void dados_paciente(PACIENTE *paciente, HWND hnome, HWND hcpf, HWND hdia, HWND hmes, HWND hano, HWND hbairro, HWND hrua, HWND hnum){
	
	char dia[3], mes[3], ano[5], num[6];
	
	GetWindowText(hnome, paciente->dados.nome, 50);
    GetWindowText(hcpf, paciente->dados.cpf, 15);
    GetWindowText(hbairro, paciente->dados.end.bairro, 50);
    GetWindowText(hrua, paciente->dados.end.rua, 15);
    GetWindowText(hdia, dia, 3);
    GetWindowText(hmes, mes, 3);
    GetWindowText(hano, ano, 5);
    GetWindowText(hnum, num, 5);

    paciente->dados.datanascimento.dia = atoi(dia);
    paciente->dados.datanascimento.mes = atoi(mes);
    paciente->dados.datanascimento.ano = atoi(ano);
    paciente->dados.end.num = atoi(num);
}

void cadastrar_paciente(L_PACIENTE *head, HWND jnl,	HWND hnome, HWND hcpf, HWND hdia, HWND hmes, HWND hano, HWND hbairro, HWND hrua, HWND hnum, int cod){

	PACIENTE *novo = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	char dia[3], mes[3], ano[5], num[6];
	
	if(novo != NULL)
	{
		
		dados_paciente(novo, hnome, hcpf, hdia, hmes, hano, hbairro, hrua, hnum);
        GetWindowText(hdia, dia, 3);
        GetWindowText(hmes, mes, 3);
        GetWindowText(hano, ano, 5);
        GetWindowText(hnum, num, 5);
        novo->dados.cod = cod;

        if(strcmp(novo->dados.nome, "") == 0 || strcmp(novo->dados.cpf, "") == 0 || strcmp(dia, "") == 0 || strcmp(mes, "") == 0 || strcmp(ano, "") == 0
				|| strcmp(novo->dados.end.bairro, "") == 0 || strcmp(novo->dados.end.rua, "") == 0 || strcmp(num, "") == 0)
        {
            MessageBoxW(jnl, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
        }
        else if(novo->dados.cpf == 0)
        {
        	MessageBoxW(jnl, L"Insira apenas numeros em cpf", L"ERRO", MB_OK | MB_ICONERROR);
		}
        else if(cadastros_paciente(novo, head, jnl) != 0)
		{
			inserir_paciente(novo, head);
			MessageBoxW(jnl, L"Paciente Cadastrado!", L"Cadastro", MB_OK | MB_ICONINFORMATION);
		}
	}

	novo = NULL;
	free(novo);
}

PACIENTE *busca_paciente(int cod, L_PACIENTE *head, HWND janela){
	
	int x = 0;
	
	PACIENTE *lista = (PACIENTE*) malloc(sizeof(PACIENTE));
	PACIENTE *ant = (PACIENTE*) malloc(sizeof(PACIENTE));
	PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));

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
		MessageBoxW(janela, L"PACIENTE NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
		aux = NULL;
	}

	return aux;
}

void lista_paciente(L_PACIENTE *head, char *lista){

	char cod[11], num[3], id[3], dia[10], mes[10], ano[10], pos[10];
	int i = 1;
	
	PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			sprintf(pos, "%d", i);
		    sprintf(cod, "%d", aux->dados.cod);
		    sprintf(num, "%d", aux->dados.end.num);
		    sprintf(dia, "%d", aux->dados.datanascimento.dia);
		    sprintf(mes, "%d", aux->dados.datanascimento.mes);
		    sprintf(ano, "%d", aux->dados.datanascimento.ano);
		    
			strcat(lista, "\r\n");
			strcat(lista, "\t\tPACIENTE ");
			strcat(lista, pos);
		    strcat(lista, "\r\n");
		    strcat(lista, "\r\n");
		    strcat(lista, "\tNOME: ");
		    strcat(lista, aux->dados.nome);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCODIGO: ");
		    strcat(lista, cod);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCPF: ");
		    strcat(lista, aux->dados.cpf);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tDATA DE NASCIMENTO: ");
		    strcat(lista, dia);
		    strcat(lista, " / ");
		    strcat(lista, mes);
		    strcat(lista, " / ");
		    strcat(lista, ano);
		    strcat(lista, "\r\n");
			strcat(lista, "\tENDERECO:");
			strcat(lista, "\r\n");
		    strcat(lista, "\tBAIRRO: ");
		    strcat(lista, aux->dados.end.bairro);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tRUA: ");
		    strcat(lista, aux->dados.end.rua);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tNUMERO: ");
		    strcat(lista, num);
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

void exclui_paciente(L_PACIENTE *head, HWND janela, HWND hb5){
		
	char cdg[15];
	int cod;
	
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	if(paciente != NULL)
	{
		GetWindowText(hb5, cdg, 15);
        cod = atoi(cdg);
        
		paciente = busca_paciente(cod, head, janela);
	}
	
	paciente = NULL;
	free(paciente);
}

void libera_lista_paciente(L_PACIENTE *head){

    PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));

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
