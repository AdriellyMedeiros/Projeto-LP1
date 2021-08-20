#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "arquivo_funcoes.h"


void inicializa_arquivos(L_ALUNO *head_aluno, L_PACIENTE *head_paciente, L_SUPERVISOR *head_supervisor, L_AGENDAMENTO *head_agendamento, L_ATENDIMENTO *head_atendimento, int *codp, int *codag, int *codat){
	
	int maior = 10;
	
//	-------------------- INICIALIZA ALUNO --------------------
	
	FILE *arquivo_aluno;

	if((arquivo_aluno = fopen("aluno.txt", "a+b")) == NULL)
	{
		printf("ARQUIVO NAO PODE SER ABERTO!\n");
		system("pause");
	}
	else
	{
		while(!feof(arquivo_aluno))
		{
			ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));

			if(aluno != NULL)
			{
				fread(aluno, sizeof(ALUNO), 1, arquivo_aluno);

				if(feof(arquivo_aluno))
				{
					break;
				}
				else
				{
					inserir_aluno(aluno, head_aluno);
				}
			}

			aluno = NULL;
			free(aluno);
		}
	}

	fclose(arquivo_aluno);

//	-------------------- INICIALIZA PACIENTE --------------------

	FILE *arquivo_paciente;

	if((arquivo_paciente = fopen("paciente.txt", "a+b")) == NULL)
	{
		printf("ARQUIVO NAO PODE SER ABERTO!\n");
		system("pause");
	}
	else
	{
		while(!feof(arquivo_paciente))
		{
			PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));

			if(paciente != NULL)
			{
				fread(paciente, sizeof(PACIENTE), 1, arquivo_paciente);

				if(feof(arquivo_paciente))
				{
					break;
				}
				else
				{
					inserir_paciente(paciente, head_paciente);
					
					if(paciente->dados.cod > maior)
					{
						maior = paciente->dados.cod;
						*codp = paciente->dados.cod;
					}
				}
			}
			
			(*codp)++;
			paciente = NULL;
			free(paciente);
		}
	}

	fclose(arquivo_paciente);
	

//	-------------------- INICIALIZA SUPERVISOR --------------------

	FILE *arquivo_supervisor;

	if((arquivo_supervisor = fopen("supervisor.txt", "a+b")) == NULL)
	{
		printf("ARQUIVO NAO PODE SER ABERTO!\n");
		system("pause");
	}
	else
	{
		while(!feof(arquivo_supervisor))
		{
			SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

			if(supervisor != NULL)
			{
				fread(supervisor, sizeof(SUPERVISOR), 1, arquivo_supervisor);

				if(feof(arquivo_supervisor))
				{
					break;
				}
				else
				{
					inserir_supervisor(supervisor, head_supervisor);
				}
			}

			supervisor = NULL;
			free(supervisor);
		}
	}

	fclose(arquivo_supervisor);
	
	
	maior = 10;

//	-------------------- INICIALIZA AGENDAMENTO --------------------

	FILE *arquivo_agendamento;

	if((arquivo_agendamento = fopen("agendamento.txt", "a+b")) == NULL)
	{
		printf("ARQUIVO NAO PODE SER ABERTO!\n");
		system("pause");
	}
	else
	{
		while(!feof(arquivo_agendamento))
		{
			AGENDAMENTO *agendamento = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

			if(agendamento != NULL)
			{
				fread(agendamento, sizeof(AGENDAMENTO), 1, arquivo_agendamento);

				if(feof(arquivo_agendamento))
				{
					break;
				}
				else
				{
					inserir_agendamento(agendamento, head_agendamento);
					
					if(agendamento->dados.cod > maior)
					{
						maior = agendamento->dados.cod;
						*codag = agendamento->dados.cod;
					}
				}
			}
			
			(*codag)++;
			agendamento = NULL;
			free(agendamento);
		}
	}

	fclose(arquivo_agendamento);
	
	
	maior = 10;

//	-------------------- INICIALIZA ATENDIMENTO --------------------

	FILE *arquivo_atendimento;

	if((arquivo_atendimento = fopen("atendimento.txt", "a+b")) == NULL)
	{
		printf("ARQUIVO NAO PODE SER ABERTO!\n");
		system("pause");
	}
	else
	{
		while(!feof(arquivo_atendimento))
		{
			ATENDIMENTO *atendimento = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

			if(atendimento != NULL)
			{
				fread(atendimento, sizeof(ATENDIMENTO), 1, arquivo_atendimento);

				if(feof(arquivo_atendimento))
				{
					break;
				}
				else
				{
					inserir_atendimento(atendimento, head_atendimento);
					
					if(atendimento->dados.cod > maior)
					{
						maior = atendimento->dados.cod;
						*codat = atendimento->dados.cod;
					}
				}
			}
			
			(*codat)++;
			atendimento = NULL;
			free(atendimento);
		}
	}

	fclose(arquivo_atendimento);
}

void atualiza_arquivos(L_ALUNO *head_aluno, L_PACIENTE *head_paciente, L_SUPERVISOR *head_supervisor, L_AGENDAMENTO *head_agendamento, L_ATENDIMENTO *head_atendimento){

//	-------------------- ATUALIZA ALUNO --------------------

	FILE *arquivo_aluno;
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));

	if(aluno != NULL)
	{
		if((arquivo_aluno = fopen("aluno.txt", "wb")) == NULL)
		{
			printf("ARQUIVO NAO PODE SER ABERTO!\n");
			system("pause");
		}
		else
		{
			aluno = (*head_aluno);

			while(aluno != NULL)
			{
				fwrite(aluno, sizeof(ALUNO), 1, arquivo_aluno);
				aluno = aluno->prox;
			}
		}
	}

	fclose(arquivo_aluno);
	libera_lista_aluno(head_aluno);
	free(aluno);

//	-------------------- ATUALIZA PACIENTE --------------------

	FILE *arquivo_paciente;
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));

	if(paciente != NULL)
	{
		if((arquivo_paciente = fopen("paciente.txt", "wb")) == NULL)
		{
			printf("ARQUIVO NAO PODE SER ABERTO!\n");
			system("pause");
		}
		else
		{
			paciente = (*head_paciente);

			while(paciente != NULL)
			{
				fwrite(paciente, sizeof(PACIENTE), 1, arquivo_paciente);
				paciente = paciente->prox;
			}
		}
	}

	fclose(arquivo_paciente);
	libera_lista_paciente(head_paciente);
	free(paciente);

//	-------------------- ATUALIZA SUPERVISOR --------------------

	FILE *arquivo_supervisor;
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));

	if(supervisor != NULL)
	{
		if((arquivo_supervisor = fopen("supervisor.txt", "wb")) == NULL)
		{
			printf("ARQUIVO NAO PODE SER ABERTO!\n");
			system("pause");
		}
		else
		{
			supervisor = (*head_supervisor);

			while(supervisor != NULL)
			{
				fwrite(supervisor, sizeof(SUPERVISOR), 1, arquivo_supervisor);
				supervisor = supervisor->prox;
			}
		}
	}

	fclose(arquivo_supervisor);
	libera_lista_supervisor(head_supervisor);
	free(supervisor);

//	-------------------- ATUALIZA AGENDAMENTO --------------------

	FILE *arquivo_agendamento;
	AGENDAMENTO *agendamento = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));

	if(agendamento != NULL)
	{
		if((arquivo_agendamento = fopen("agendamento.txt", "wb")) == NULL)
		{
			printf("ARQUIVO NAO PODE SER ABERTO!\n");
			system("pause");
		}
		else
		{
			agendamento = (*head_agendamento);

			while(agendamento != NULL)
			{
				fwrite(agendamento, sizeof(AGENDAMENTO), 1, arquivo_agendamento);
				agendamento = agendamento->prox;
			}
		}
	}

	fclose(arquivo_agendamento);
	libera_lista_agendamento(head_agendamento);
	free(agendamento);

//	-------------------- ATUALIZA ATENDIMENTO --------------------

	FILE *arquivo_atendimento;
	ATENDIMENTO *atendimento = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));

	if(atendimento != NULL)
	{
		if((arquivo_atendimento = fopen("atendimento.txt", "wb")) == NULL)
		{
			printf("ARQUIVO NAO PODE SER ABERTO!\n");
			system("pause");
		}
		else
		{
			atendimento = (*head_atendimento);

			while(atendimento != NULL)
			{
				fwrite(atendimento, sizeof(ATENDIMENTO), 1, arquivo_atendimento);
				atendimento = atendimento->prox;
			}
		}
	}

	fclose(arquivo_atendimento);
	libera_lista_atendimento(head_atendimento);
	free(atendimento);
}
