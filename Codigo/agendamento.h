#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "paciente.h"


struct CadastroAgendamento{
	int cod, paciente_cod;
	char area[15], paciente_nome[50];
	struct Data data;
};

typedef struct Agendamento *L_AGENDAMENTO;

struct Agendamento{
	struct CadastroAgendamento dados;
	struct Agendamento *prox;
};

typedef struct Agendamento AGENDAMENTO;

L_AGENDAMENTO *criar_lista_agendamento();
void inserir_agendamento(AGENDAMENTO *agendamento, L_AGENDAMENTO *head);
PACIENTE *procura_paciente(int cod, L_PACIENTE *head_paciente, HWND janela);
int cadastros_agendamento(AGENDAMENTO *agendamento, L_AGENDAMENTO *head, HWND janela);
void cadastrar_agendamento(L_AGENDAMENTO *head, L_PACIENTE *head_paciente, HWND jnl, HWND hcod, HWND harea, HWND hdia, HWND hmes, HWND hano, int cod);
void maiuscula(char a[]);
AGENDAMENTO *busca_agendamento(int cod, L_AGENDAMENTO *head, HWND janela);
void lista_agendamento(L_AGENDAMENTO *head, char *lista);
void exclui_agendamento(L_AGENDAMENTO *head, HWND janela, HWND hnum);
void libera_lista_agendamento(L_AGENDAMENTO *head);

#endif
