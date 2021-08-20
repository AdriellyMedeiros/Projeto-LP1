#ifndef ALUNO_H
#define ALUNO_H

#include <windows.h>


struct CadastroAluno{
	int cod;
	char nome[50], curso[50], cpf[15];
};

typedef struct Aluno *L_ALUNO;


struct Aluno{
	struct CadastroAluno dados;
	struct Aluno *prox;
};

typedef struct Aluno ALUNO;


L_ALUNO *criar_lista_aluno();
void inserir_aluno(ALUNO *aluno, L_ALUNO *head);
int cadastros_aluno(ALUNO *aluno, L_ALUNO *head, HWND janela);
void cadastrar_aluno(L_ALUNO *head, HWND jnl, HWND hnome, HWND hcpf, HWND hcurso, HWND hcod);
void dados_aluno(ALUNO *aluno, HWND hnome, HWND hcpf, HWND hcurso, HWND hcod);
ALUNO *busca_aluno(int cod, L_ALUNO *head, HWND janela);
void lista_aluno(L_ALUNO *head, char *lista);
void exclui_aluno(L_ALUNO *head, HWND janela, HWND hnum);
void libera_lista_aluno(L_ALUNO *head);

#endif
