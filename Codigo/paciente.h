#ifndef PACIENTE_H
#define PACIENTE_H


struct Data{
	int dia,mes,ano;
};

struct Endereco{
	int num;
	char rua[50], bairro[50];
};

struct CadastroPaciente{
	int cod;
	char nome[50], curso[50], cpf[15];
	struct Data datanascimento;
	struct Endereco end;
};

typedef struct Paciente *L_PACIENTE;

struct Paciente{
	struct CadastroPaciente dados;
	struct Paciente *prox;
};

typedef struct Paciente PACIENTE;


L_PACIENTE *criar_lista_paciente();
void inserir_paciente(PACIENTE *paciente, L_PACIENTE *head);
int cadastros_paciente(PACIENTE *paciente, L_PACIENTE *head, HWND janela);
void cadastrar_paciente(L_PACIENTE *head, HWND jnl, HWND hnome, HWND hcpf, HWND hdia, HWND hmes, HWND hano, HWND hbairro, HWND hrua, HWND hnum, int cod);
void dados_paciente(PACIENTE *paciente, HWND hnome, HWND hcpf, HWND hdia, HWND hmes, HWND hano, HWND hbairro, HWND hrua, HWND hnum);
PACIENTE *busca_paciente(int cod, L_PACIENTE *head, HWND janela);
void lista_paciente(L_PACIENTE *head, char *lista);
void exclui_paciente(L_PACIENTE *head, HWND janela, HWND hnum);
void libera_lista_paciente(L_PACIENTE *head);

#endif
