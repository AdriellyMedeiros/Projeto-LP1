#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "aluno.h"
#include "paciente.h"
#include "supervisor.h"
#include "agendamento.h"


struct CadastroAtendimento{
	int cod, agendamento_cod, aluno_cod, supervisor_cod, paciente_cod;
	char area[15], aluno_nome[50], paciente_nome[50], supervisor_nome[50];
	struct Data data;
};

typedef struct Atendimento *L_ATENDIMENTO;

struct Atendimento{
	struct CadastroAtendimento dados;
	struct Atendimento *prox;
};

typedef struct Atendimento ATENDIMENTO;

L_ATENDIMENTO *criar_lista_atendimento();
void inserir_atendimento(ATENDIMENTO *atendamento, L_ATENDIMENTO *head);
ALUNO *procura_aluno(int cod, L_ALUNO *head_aluno, HWND janela);
SUPERVISOR *procura_supervisor(int cod, L_SUPERVISOR *arquivo_supervisor, HWND janela);
AGENDAMENTO *procura_agendamento(int cod, L_AGENDAMENTO *head_agendamento, HWND janela);
ATENDIMENTO *procura_atendimento(int cod, L_ATENDIMENTO *head_atendimento, HWND janela);
int cadastros_atendimento(ATENDIMENTO *atendimento, L_ATENDIMENTO *head, HWND janela);
void cadastrar_atendimento(L_ATENDIMENTO *head, L_AGENDAMENTO *head_agendamento, L_SUPERVISOR *head_supervisor, L_ALUNO *head_aluno, HWND jnl, HWND hcod, HWND hnum, HWND hcpf, int cod);
ATENDIMENTO *busca_atendimento(int cod, L_ATENDIMENTO *head, HWND janela);
void lista_A(ATENDIMENTO *aux, char *lista, int i);
void lista_atendimento(L_ATENDIMENTO *head, char *lista);
void lista_atendimento_area(char area[], L_ATENDIMENTO *head, char *lista);
void lista_atendimento_aluno(int cod, L_ATENDIMENTO *head, char *lista);
void lista_atendimento_paciente(int cod, L_ATENDIMENTO *head, char *lista);
void exclui_atendimento(L_ATENDIMENTO *head, L_AGENDAMENTO *head_agendamento, HWND janela, HWND hnum);
void libera_lista_atendimento(L_ATENDIMENTO *head);

#endif
