#ifndef ARQUIVO_FUNCOES_H
#define ARQUIVO_FUNCOES_H

#include "bibliotecas.h"


void inicializa_arquivos(L_ALUNO *head_aluno, L_PACIENTE *head_paciente, L_SUPERVISOR *head_supervisor, L_AGENDAMENTO *head_agendamento, 
							L_ATENDIMENTO *head_atendimento,  int *codp, int *codag, int *codat);
							
void atualiza_arquivos(L_ALUNO *head_aluno, L_PACIENTE *head_paciente, L_SUPERVISOR *head_supervisor, L_AGENDAMENTO *head_agendamento, 
							L_ATENDIMENTO *head_atendimento);


#endif
