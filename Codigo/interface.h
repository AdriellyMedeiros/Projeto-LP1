#ifndef INTERFACE_H
#define INTERFACE_H


void janela_login(HWND janela);
int confere_senha(HWND janela);
void janela_principal(HWND janela);

void janela_menu_aluno(HWND janela);
void aluno_cadastro_janela(HWND janela);
void aluno_edita_janela(HWND janela);
void lista_aluno_janela(HWND janela, L_ALUNO *head);
void aluno_edita_procura(L_ALUNO *head, HWND janela, HWND hnum);
void edita_aluno_janela(HWND janela, ALUNO *aluno);
void aluno_atualiza(L_ALUNO *head, HWND janela, HWND hnum);
void aluno_exclui_janela(HWND janela);
void aluno_exclui_procura(L_ALUNO *head, HWND janela, HWND hnum);


void janela_menu_paciente(HWND janela);
void paciente_cadastro_janela(HWND janela);
void paciente_edita_janela(HWND janela);
void lista_paciente_janela(HWND janela, L_PACIENTE *head);
void paciente_edita_procura(L_PACIENTE *head, HWND janela, HWND hb5);
void edita_paciente_janela(HWND janela, PACIENTE *paciente);
void paciente_atualiza(L_PACIENTE *head, HWND janela, HWND hb5);
void paciente_exclui_janela(HWND janela);
void paciente_exclui_procura(L_PACIENTE *head, HWND janela, HWND hb5);


void janela_menu_supervisor(HWND janela);
void supervisor_cadastro_janela(HWND janela);
void supervisor_edita_janela(HWND jnl);
void lista_supervisor_janela(HWND janela, L_SUPERVISOR *head);
void supervisor_edita_procura(L_SUPERVISOR *head, HWND janela, HWND hnum);
void edita_supervisor_janela(HWND janela, SUPERVISOR *supervisor);
void supervisor_atualiza(L_SUPERVISOR *head, HWND janela, HWND hnum);
void supervisor_exclui_janela(HWND janela);
void supervisor_exclui_procura(L_SUPERVISOR *head, HWND janela, HWND hnum);


void janela_menu_agendamento(HWND janela);
void agendamento_cadastro_janela(HWND janela);
void lista_agendamento_janela(HWND janela, L_AGENDAMENTO *head);
void exclui_agendamento_janela(HWND janela, AGENDAMENTO *agendamento);
void agendamento_exclui_janela(HWND janela);
void agendamento_exclui_procura(L_AGENDAMENTO *head, HWND janela, HWND hnum);


void janela_menu_atendimento(HWND janela);
void atendimento_cadastro_janela(HWND janela);
void janela_lista_atendimento(HWND janela);
void lista_todos_janela(HWND janela, L_ATENDIMENTO *head);
void lista_al_janela(HWND janela);
void lista_al(HWND janela, L_ATENDIMENTO *head, char num[]);
void lista_p_janela(HWND janela);
void lista_p(HWND janela, L_ATENDIMENTO *head, char num[]);
void janela_lista_area(HWND janela);
void lista_psico(HWND janela, L_ATENDIMENTO *head);
void lista_odonto(HWND janela, L_ATENDIMENTO *head);
void lista_fisio(HWND janela, L_ATENDIMENTO *head);
int lista_vazia_atendimento(L_ATENDIMENTO *head, HWND janela);
void exclui_atendimento_janela(HWND janela, ATENDIMENTO *atendimento);
void atendimento_exclui_janela(HWND janela);
void atendimento_exclui_procura(L_ATENDIMENTO *head, HWND janela, HWND hnum);

void carrega_imagem();
void destroi_janelas();

#endif
