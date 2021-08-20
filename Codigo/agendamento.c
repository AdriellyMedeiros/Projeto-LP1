#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "agendamento.h"
#include "paciente.h"


L_AGENDAMENTO *criar_lista_agendamento(){

	L_AGENDAMENTO *head = (L_AGENDAMENTO*) malloc(sizeof(L_AGENDAMENTO));

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

void inserir_agendamento(AGENDAMENTO *novo, L_AGENDAMENTO *head){

	unsigned int i;

	i = 0;

	if((*head) == NULL)
	{
		(*head) = novo;
		novo->prox = NULL;
	}
	else
	{
		AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
		AGENDAMENTO *ant = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

		if(aux != NULL && ant != NULL)
		{
			aux = (*head);

			while(aux != NULL && strcmp(novo->dados.paciente_nome, aux->dados.paciente_nome) == 1)
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

PACIENTE *procura_paciente(int cod, L_PACIENTE *head_paciente, HWND janela){

	unsigned int count = 0;

	PACIENTE *aux = (PACIENTE*) malloc(sizeof(PACIENTE));

	if(aux != NULL)
	{
		aux = (*head_paciente);

		while(aux != NULL)
		{
			if(aux->dados.cod == cod)
			{
				count++;
				break;
			}
			
			aux = aux->prox;
		}

		if(count == 0)
		{
			MessageBoxW(janela, L"PACIENTE NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
			aux = NULL;
		}
	}

	return aux;
}

int cadastros_agendamento(AGENDAMENTO *agendamento, L_AGENDAMENTO *head, HWND janela){

	unsigned int x = 1;

	AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

	if(aux != NULL)
	{
		aux = (*head);

		while(aux != NULL)
		{
			if(agendamento->dados.paciente_cod == aux->dados.paciente_cod && strcmp(agendamento->dados.area, aux->dados.area) == 0)
			{
				MessageBoxW(janela, L"UM PACIENTE NAO PODE TER MAIS DE UM AGENDAMENTO PARA A MESMA AREA!", L"AGENDAMENTO NAO CADASTRADO", MB_OK | MB_ICONERROR);				
				x = 0;
				
				break;
			}

			aux = aux->prox;
		}
	}

	aux = NULL;
	free(aux);

	return x;
}

void maiuscula(char a[]){
	
	int i;
	
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>=97 && a[i]<=122)
		{
			a[i] -= 32;
		}
	}
}

void cadastrar_agendamento(L_AGENDAMENTO *head, L_PACIENTE *head_paciente, HWND jnl, HWND hcod, HWND harea, HWND hdia, HWND hmes, HWND hano, int cod){
	
	
	AGENDAMENTO *novo = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	char dia[3], mes[3], ano[5], num[6], codg[15];
	
	if(novo != NULL && paciente != NULL)
	{
        GetWindowText(hcod, codg, 15);
    	GetWindowText(harea, novo->dados.area, 50);
        GetWindowText(hdia, dia, 3);
        GetWindowText(hmes, mes, 3);
        GetWindowText(hano, ano, 5);
		
		novo->dados.paciente_cod = atoi(codg);
        novo->dados.data.dia = atoi(dia);
        novo->dados.data.mes = atoi(mes);
        novo->dados.data.ano = atoi(ano);
		
		novo->dados.cod = cod;
		
		maiuscula(novo->dados.area);
		
		if(strcmp(novo->dados.area, "") == 0 || strcmp(dia, "") == 0 || strcmp(mes, "") == 0 || strcmp(ano, "") == 0 || strcmp(codg, "") == 0)
        {
            MessageBoxW(jnl, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
        }
        else if(strcmp(novo->dados.area, "FISIOTERAPIA") != 0 && strcmp(novo->dados.area, "ODONTOLOGIA") != 0 && strcmp(novo->dados.area, "PSICOLOGIA") != 0)
        {
        	MessageBoxW(jnl, L"AREAS DISPONIVEIS: \nFisioterapia, Odontologia ou Psicologia", L"ERRO", MB_OK | MB_ICONERROR);
		}
		else if(novo->dados.paciente_cod == 0)
        {
        	MessageBoxW(jnl, L"Insira apenas numeros no codigo do paciente", L"ERRO", MB_OK | MB_ICONERROR);
		}
		else
		{
			paciente = procura_paciente(novo->dados.paciente_cod, head_paciente, jnl);
	
			if(paciente != NULL)
			{
				strcpy(novo->dados.paciente_nome, paciente->dados.nome);
				
		        if(cadastros_agendamento(novo, head, jnl) != 0)
				{
					inserir_agendamento(novo, head);
					MessageBoxW(jnl, L"Agendamento Cadastrado!", L"Cadastro", MB_OK | MB_ICONINFORMATION);
				}
			}
		}
	}

	novo = NULL;
	free(novo);
}

AGENDAMENTO *busca_agendamento(int cod, L_AGENDAMENTO *head, HWND janela){
	
	int x = 0;
	
	AGENDAMENTO *lista = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	AGENDAMENTO *ant = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

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
		MessageBoxW(janela, L"AGENDAMENTO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
		aux = NULL;
	}

	return aux;
}

void lista_agendamento(L_AGENDAMENTO *head, char *lista){
	
	char cod[11], num[15], dia[3], mes[3], ano[5], pos[10];
	int i = 1;
	
	AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			sprintf(pos, "%d", i);
		    sprintf(cod, "%d", aux->dados.cod);
		    sprintf(num, "%d", aux->dados.paciente_cod);
		    sprintf(dia, "%d", aux->dados.data.dia);
		    sprintf(mes, "%d", aux->dados.data.mes);
		    sprintf(ano, "%d", aux->dados.data.ano);
		    
		    strcat(lista, "\r\n");
			strcat(lista, "\t\tAGENDAMENTO ");
			strcat(lista, pos);
		    strcat(lista, "\r\n");
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCODIGO DO AGENDAMENTO: ");
		    strcat(lista, cod);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tNOME DO PACIENTE: ");
		    strcat(lista, aux->dados.paciente_nome);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tCODIGO DO PACIENTE: ");
		    strcat(lista, num);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tAREA DO ATENDIMENTO: ");
		    strcat(lista, aux->dados.area);
		    strcat(lista, "\r\n");
		    strcat(lista, "\tDATA DA CONSULTA: ");
		    strcat(lista, dia);
		    strcat(lista, " / ");
		    strcat(lista, mes);
		    strcat(lista, " / ");
		    strcat(lista, ano);
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

void exclui_agendamento(L_AGENDAMENTO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	AGENDAMENTO *agendamento = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	
	if(agendamento != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		agendamento = busca_agendamento(cod, head, janela);
	}
	
	agendamento = NULL;
	free(agendamento);
}

void libera_lista_agendamento(L_AGENDAMENTO *head){

	AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

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
