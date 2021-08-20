#ifndef SUPERVISOR_H
#define SUPERVISOR_H


struct CadastroSupervisor{
	int cod;
	char nome[50],curso[50];
};

typedef struct Supervisor *L_SUPERVISOR;

struct Supervisor{
	struct CadastroSupervisor dados;
	struct Supervisor *prox;
};

typedef struct Supervisor SUPERVISOR;


L_SUPERVISOR *criar_lista_supervisor();
void inserir_supervisor(SUPERVISOR *supervisor, L_SUPERVISOR *head);
int cadastros_supervisor(SUPERVISOR *supervisor, L_SUPERVISOR *head, HWND jnl);
void cadastrar_supervisor(L_SUPERVISOR *head, HWND janela, HWND hnome, HWND hcurso, HWND hcod);
void dados_supervisor(SUPERVISOR *supervisor, HWND hnome, HWND hcurso, HWND hcod);
SUPERVISOR *busca_supervisor(int cod, L_SUPERVISOR *head, HWND janela);
void lista_supervisor(L_SUPERVISOR *head, char *lista);
void exclui_supervisor(L_SUPERVISOR *head, HWND janela, HWND hnum);
void libera_lista_supervisor(L_SUPERVISOR *head);

#endif
