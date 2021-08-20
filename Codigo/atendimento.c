#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "atendimento.h"
#include "bibliotecas.h"


L_ATENDIMENTO *criar_lista_atendimento(){

	L_ATENDIMENTO *head = (L_ATENDIMENTO*) malloc(sizeof(L_ATENDIMENTO));

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

void inserir_atendimento(ATENDIMENTO *novo, L_ATENDIMENTO *head){

	unsigned int i;

	i = 0;

	if((*head) == NULL)
	{
		(*head) = novo;
		novo->prox = NULL;
	}
	else
	{
		ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
		ATENDIMENTO *ant = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

		if(aux != NULL && ant != NULL)
		{
			aux = (*head);

			while(aux != NULL && novo->dados.cod > aux->dados.cod)
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

ALUNO *procura_aluno(int cod, L_ALUNO *head_aluno, HWND janela){

	unsigned int count = 0;

	ALUNO *aux = (ALUNO*) malloc(sizeof(ALUNO));

	if(aux != NULL)
	{
		aux = (*head_aluno);

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
			MessageBoxW(janela, L"ALUNO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
			aux = NULL;
		}
	}

	return aux;
}

SUPERVISOR *procura_supervisor(int cod, L_SUPERVISOR *head_supervisor, HWND janela){

	unsigned int count = 0;

	SUPERVISOR *aux = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

	if(aux != NULL)
	{
		aux = (*head_supervisor);

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
			MessageBoxW(janela, L"SUPERVISOR NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
			aux = NULL;
		}
	}

	return aux;
}

AGENDAMENTO *procura_agendamento(int cod, L_AGENDAMENTO *head_agendamento, HWND janela){

	unsigned int count = 0;

	AGENDAMENTO *aux = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

	if(aux != NULL)
	{
		aux = (*head_agendamento);

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
			MessageBoxW(janela, L"AGENDAMENTO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
			aux = NULL;
		}
	}

	return aux;
}

ATENDIMENTO *procura_atendimento(int cod, L_ATENDIMENTO *head_atendimento, HWND janela){
	
	unsigned int count = 0;

	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

	if(aux != NULL)
	{
		aux = (*head_atendimento);

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
			MessageBoxW(janela, L"ATENDIMENTO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
			aux = NULL;
		}
	}

	return aux;
}

int cadastros_atendimento(ATENDIMENTO *atendimento, L_ATENDIMENTO *head, HWND janela){

	unsigned int pos, x = 1;
	
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

	if(aux != NULL)
	{
		aux = (*head);

		while(aux != NULL)
		{
			if(atendimento->dados.agendamento_cod == aux->dados.agendamento_cod)
			{
				MessageBoxW(janela, L"CODIGO DO  AGENDAMENTO JA CADASTRADO PARA OUTRO ATENDIMENTO!", L"ERRO", MB_OK | MB_ICONINFORMATION);
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

void cadastrar_atendimento(L_ATENDIMENTO *head, L_AGENDAMENTO *head_agendamento, L_SUPERVISOR *head_supervisor, L_ALUNO *head_aluno, HWND jnl, HWND hcod, HWND hnum, HWND hcpf, int cod){

	ATENDIMENTO *novo = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	AGENDAMENTO *agendamento = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));
	
	
	char coda[15], cods[15], mat[15]; 
	
	if(novo != NULL && agendamento != NULL && supervisor != NULL && aluno != NULL)
	{
		
        GetWindowText(hcod, coda, 15);
        GetWindowText(hnum, cods, 15);
        GetWindowText(hcpf, mat, 15);
		
		novo->dados.cod = cod;
        novo->dados.agendamento_cod = atoi(coda);
        novo->dados.supervisor_cod = atoi(cods);
        novo->dados.aluno_cod = atoi(mat);

		
        if(strcmp(coda, "") == 0 || strcmp(cods, "") == 0 || strcmp(mat, "") == 0)
        {
            MessageBoxW(jnl, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
        }
        else
        {
			agendamento = procura_agendamento(novo->dados.agendamento_cod, head_agendamento, jnl);
		
			if(agendamento != NULL)
			{
				strcpy(novo->dados.area, agendamento->dados.area);
				strcpy(novo->dados.paciente_nome, agendamento->dados.paciente_nome);
				novo->dados.paciente_cod = agendamento->dados.paciente_cod;
		
				novo->dados.data.dia = agendamento->dados.data.dia;
				novo->dados.data.mes = agendamento->dados.data.mes;
				novo->dados.data.ano = agendamento->dados.data.ano;
		
				supervisor = procura_supervisor(novo->dados.supervisor_cod, head_supervisor, jnl);
		
				if(supervisor != NULL)
				{
					strcpy(novo->dados.supervisor_nome, supervisor->dados.nome);
		
					aluno = procura_aluno(novo->dados.aluno_cod, head_aluno, jnl);
		
					if(aluno != NULL)
					{
						strcpy(novo->dados.aluno_nome, aluno->dados.nome);
						
						if(cadastros_atendimento(novo, head, jnl) != 0)
						{
							inserir_atendimento(novo, head);
							MessageBoxW(jnl, L"Atendimento Cadastrado!", L"Cadastro", MB_OK | MB_ICONINFORMATION);
							exclui_agendamento(head_agendamento, jnl, hcod);
						}
					}
				}
			}
		}
	}

	novo = NULL;
	free(novo);
}

ATENDIMENTO *busca_atendimento(int cod, L_ATENDIMENTO *head, HWND janela){
	
	int x = 0;
	
	ATENDIMENTO *lista = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	ATENDIMENTO *ant = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

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
		MessageBoxW(janela, L"ATENDIMENTO NAO CADASTRADO!", L"ERRO", MB_OK | MB_ICONERROR);
		aux = NULL;
	}

	return aux;
}

void lista_A(ATENDIMENTO *aux, char *lista, int i){
	
	char cod[11], codag[15], codp[15], cods[15], coda[15], dia[3], mes[3], ano[5], pos[10];
	
	sprintf(pos, "%d", i);
    sprintf(cod, "%d", aux->dados.cod);
    sprintf(codag, "%d", aux->dados.agendamento_cod);
    sprintf(codp, "%d", aux->dados.paciente_cod);
    sprintf(cods, "%d", aux->dados.supervisor_cod);
    sprintf(coda, "%d", aux->dados.aluno_cod);
    sprintf(dia, "%d", aux->dados.data.dia);
    sprintf(mes, "%d", aux->dados.data.mes);
    sprintf(ano, "%d", aux->dados.data.ano);
    
	strcat(lista, "\r\n");
	strcat(lista, "\t\tATENDIMENTO ");
	strcat(lista, pos);
    strcat(lista, "\r\n");
    strcat(lista, "\r\n");
    strcat(lista, "\tCODIGO DO ATENDIMENTO: ");
    strcat(lista, cod);
    strcat(lista, "\r\n");
    strcat(lista, "\tCODIGO DO AGENDAMENTO: ");
    strcat(lista, codag);
    strcat(lista, "\r\n");
    strcat(lista, "\tAREA DO ATENDIMENTO: ");
    strcat(lista, aux->dados.area);
    strcat(lista, "\r\n");
    strcat(lista, "\tNOME DO PACIENTE: ");
    strcat(lista, aux->dados.paciente_nome);
    strcat(lista, "\r\n");
    strcat(lista, "\tCODIGO DO PACIENTE: ");
    strcat(lista, codp);
    strcat(lista, "\r\n");
    strcat(lista, "\tNOME DO SUPERVISOR: ");
    strcat(lista, aux->dados.supervisor_nome);
    strcat(lista, "\r\n");
    strcat(lista, "\tCODIGO DO SUPERVISOR: ");
    strcat(lista, cods);
    strcat(lista, "\r\n");
    strcat(lista, "\tNOME DO ALUNO: ");
    strcat(lista, aux->dados.aluno_nome);
    strcat(lista, "\r\n");
    strcat(lista, "\tMATRICULA DO ALUNO: ");
    strcat(lista, coda);
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
}

void lista_atendimento(L_ATENDIMENTO *head, char *lista){
		
	int i = 1;
	
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			lista_A(aux, lista, i);
			aux = aux->prox;
			i++;
		}
	}
}

void lista_atendimento_area(char area[], L_ATENDIMENTO *head, char *lista){

	int i = 1;
	
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		maiuscula(area);
		
		while(aux != NULL)
		{
			if(strcmp(area, aux->dados.area) == 0)
			{
				lista_A(aux, lista, i);
				i++;
			}
			
			aux = aux->prox;
		}
	}
	
	if(i == 1)
	{
		strcpy(lista,"\r\n\r\n\r\n\tSEM ATENDIMENTOS CADASTRADOS PARA ESTA AREA!");
	}
}

void lista_atendimento_aluno(int cod, L_ATENDIMENTO *head, char *lista){

	int i = 1;
	
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			if(aux->dados.aluno_cod == cod)
			{
				lista_A(aux, lista, i);
				i++;
			}
			
			aux = aux->prox;
		}
	}
	
	if(i == 1)
	{
		strcpy(lista,"\r\n\r\n\r\n\tSEM ATENDIMENTOS CADASTRADOS PARA ESTE ALUNO!");
	}
}

void lista_atendimento_paciente(int cod, L_ATENDIMENTO *head, char *lista){
	
	int i = 1;
	
	ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	
	if(aux != NULL)
	{
		aux = (*head);
		strcpy(lista, "");
		
		while(aux != NULL)
		{
			if(aux->dados.paciente_cod == cod)
			{
				lista_A(aux, lista, i);
				i++;
			}
			
			aux = aux->prox;
		}
	}
	
	
	if(i == 1)
	{
		strcpy(lista,"\r\n\r\n\r\n\tSEM ATENDIMENTOS CADASTRADOS PARA ESTE PACIENTE!");
	}
}

void exclui_atendimento(L_ATENDIMENTO *head, L_AGENDAMENTO *head_agendamento, HWND janela, HWND hnum){

	char cdg[15];
	int cod;
	
	ATENDIMENTO *atendimento = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	AGENDAMENTO *agendamento = (AGENDAMENTO*) calloc(1, sizeof(AGENDAMENTO));
	
	
	if(atendimento != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		atendimento = busca_atendimento(cod, head, janela);

		strcpy(agendamento->dados.paciente_nome, atendimento->dados.paciente_nome);
		strcpy(agendamento->dados.area, atendimento->dados.area);
		agendamento->dados.paciente_cod = atendimento->dados.paciente_cod;
		agendamento->dados.cod = atendimento->dados.agendamento_cod;
		agendamento->dados.data.dia = atendimento->dados.data.dia;
		agendamento->dados.data.mes = atendimento->dados.data.mes;
		agendamento->dados.data.ano = atendimento->dados.data.ano;
		inserir_agendamento(agendamento, head_agendamento);
	}
	
	agendamento = NULL;
	atendimento = NULL;
	
	free(atendimento);
	free(agendamento);
}

void libera_lista_atendimento(L_ATENDIMENTO *head){

    ATENDIMENTO *aux = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

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
