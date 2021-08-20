#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "bibliotecas.h"
#include "interface.h"


HBITMAP hfisioImage, hodonImage, hpsicImage;

HWND hb1, hb2, hb3, hb4, hb5, hnome, hcpf, hcod, hcurso, hbairro, hrua, hnum, hs, hs1, hs2, hs3, hs4, hs5, hs6, hs7, hs8, hlista, hdia, hmes, hano, harea;


void carrega_imagem(){

	hfisioImage = (HBITMAP) LoadImageW(NULL, L"fisioterapia.bmp", IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	hodonImage = (HBITMAP) LoadImageW(NULL, L"odontologia.bmp", IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	hpsicImage = (HBITMAP) LoadImageW(NULL, L"psicologia.bmp", IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
}

void destroi_janelas(){

	DestroyWindow(hb1);
	DestroyWindow(hb2);
	DestroyWindow(hb3);
	DestroyWindow(hb4);
	DestroyWindow(hb5);
	DestroyWindow(hs);
	DestroyWindow(hs1);
	DestroyWindow(hs2);
	DestroyWindow(hs3);
	DestroyWindow(hs4);
	DestroyWindow(hs5);
	DestroyWindow(hs6);
	DestroyWindow(hs7);
	DestroyWindow(hs8);
	DestroyWindow(hnome);
	DestroyWindow(hcpf);
	DestroyWindow(hcod);
	DestroyWindow(hdia);
	DestroyWindow(hmes);
	DestroyWindow(hano);
	DestroyWindow(hcurso);
	DestroyWindow(hbairro);
	DestroyWindow(hrua);
	DestroyWindow(hnum);
	DestroyWindow(harea);
	DestroyWindow(hlista);
}

void janela_login(HWND janela){
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 100, 450, 150, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"USUARIO :", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 140, 150, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 450, 140, 150, 25, janela, NULL, NULL, NULL);
	hs2 = CreateWindowW(L"static", L"SENHA     :", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 180, 150, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 450, 180, 150, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"ENTRAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 330, 360, 200, 50, janela, (HMENU) ENTRAR, NULL, NULL);
}

int confere_senha(HWND janela){
	
	char nome[10], cod[5];
	int x = 1;
	
	GetWindowText(hnome, nome, 10);
	GetWindowText(hcod, cod, 5);
	
	if(strcmp(nome, "") == 0 || strcmp(cod, "") == 0)
	{
		MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
	}
	else if(strcmp(nome, "projeto") == 0 && strcmp(cod, "123") == 0)
	{
		x = 0;
	}
	else
	{
		MessageBoxW(janela, L"Usuario e/ou senha incorreto(s)!", L"ERRO", MB_OK | MB_ICONERROR);
	}
	
	return x;
}

void janela_principal(HWND janela){

    hb1 = CreateWindowW(L"button", L"\nALUNO", WS_VISIBLE | WS_CHILD, 350, 100, 200, 50, janela, (HMENU) MENU_ALUNO, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"\nPACIENTE", WS_VISIBLE | WS_CHILD, 350, 160, 200, 50, janela, (HMENU) MENU_PACIENTE, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"\nSUPERVISOR", WS_VISIBLE | WS_CHILD, 350, 220, 200, 50, janela, (HMENU) MENU_SUPERVISOR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"\nAGENDAMENTO", WS_VISIBLE | WS_CHILD, 350, 280, 200, 50, janela, (HMENU) MENU_AGENDAMENTO, NULL, NULL);
    hb5 = CreateWindowW(L"button", L"\nATENDIMENTO", WS_VISIBLE | WS_CHILD, 350, 340, 200, 50, janela, (HMENU) MENU_ATENDIMENTO, NULL, NULL);
}


// --------------------------------------- JANELAS ALUNO ---------------------------------------

void janela_menu_aluno(HWND janela){

    hb1 = CreateWindowW(L"button", L"CADASTRAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) ALUNO_CADASTRAR, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR ALUNOS", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) ALUNO_LISTAR, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"EDITAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) ALUNO_EDITAR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"EXCLUIR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 270, 200, 50, janela, (HMENU) ALUNO_EXCLUIR, NULL, NULL);
    hb5 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_MENU, NULL, NULL);
}

void aluno_cadastro_janela(HWND janela){

    hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 50, 750, 270, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"INSIRA NOME           :", WS_VISIBLE | WS_CHILD, 100, 85, 200, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 85, 450, 25, janela, NULL, NULL, NULL);

	hs2 = CreateWindowW(L"static", L"INSIRA CPF              :", WS_VISIBLE | WS_CHILD, 100, 145, 200, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 145, 200, 25, janela, NULL, NULL, NULL);

	hs3 = CreateWindowW(L"static", L"INSIRA CURSO         :", WS_VISIBLE | WS_CHILD, 100, 205, 200, 25, janela, NULL, NULL, NULL);
	hcurso = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 205, 450, 25, janela, NULL, NULL, NULL);

	hs4 = CreateWindowW(L"static", L"INSIRA MATRICULA  :", WS_VISIBLE | WS_CHILD, 100, 265, 200, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 265, 200, 25, janela, NULL, NULL, NULL);

    hb1 = CreateWindowW(L"button", L"CADASTRAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) A_CADASTRAR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_ALUNO, NULL, NULL);
}

void lista_aluno_janela(HWND janela, L_ALUNO *head){

	char lista[100000];

	hs2 = CreateWindowW(L"static", L"ALUNOS", WS_VISIBLE | WS_CHILD | SS_CENTER, 350, 70, 200, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);

	lista_aluno(head, lista);

 	SetWindowText(hlista, lista);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) VOLTAR_ALUNO, NULL, NULL);
}

void aluno_edita_janela(HWND janela){
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE MATRICULA DO ALUNO QUE DESEJA EDITAR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) ALUNO_PROCURA, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_ALUNO, NULL, NULL);
}

void edita_aluno_janela(HWND janela, ALUNO *aluno){
	
	char cod[15];

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 50, 750, 270, janela, NULL, NULL, NULL);
	
	hs1 = CreateWindowW(L"static", L"NOME           :", WS_VISIBLE | WS_CHILD, 100, 85, 200, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 85, 450, 25, janela, NULL, NULL, NULL);
	SetWindowText(hnome, aluno->dados.nome);
	
	hs2 = CreateWindowW(L"static", L"CPF              :", WS_VISIBLE | WS_CHILD, 100, 145, 200, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 145, 200, 25, janela, NULL, NULL, NULL);
	SetWindowText(hcpf, aluno->dados.cpf);
	
	hs3 = CreateWindowW(L"static", L"CURSO         :", WS_VISIBLE | WS_CHILD, 100, 205, 200, 25, janela, NULL, NULL, NULL);
	hcurso = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 205, 450, 25, janela, NULL, NULL, NULL);
	SetWindowText(hcurso, aluno->dados.curso);
	
	hs4 = CreateWindowW(L"static", L"MATRICULA  :", WS_VISIBLE | WS_CHILD, 100, 265, 200, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 300, 265, 200, 25, janela, NULL, NULL, NULL);
	sprintf(cod, "%d", aluno->dados.cod);
	SetWindowText(hcod, cod);
	
	hb1 = CreateWindowW(L"button", L"ATUALIZAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) ATUALIZA_ALUNO, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_AL_EDITA, NULL, NULL);
}

void aluno_edita_procura(L_ALUNO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));
	
	if(aluno != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		aluno = procura_aluno(cod, head, janela);
		
		if(aluno != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_aluno_janela(janela, aluno);
		}
	}
}

void aluno_atualiza(L_ALUNO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));
	
	if(aluno != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		aluno = procura_aluno(cod, head, janela);
		
		if(aluno != NULL)
		{
			dados_aluno(aluno, hnome, hcpf, hcurso, hcod);
		}
	}
	
	MessageBoxW(janela, L"Aluno atualizado!", L"ATUALIZACAO", MB_OK | MB_ICONINFORMATION);
}

void aluno_exclui_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE MATRICULA DO ALUNO QUE DESEJA EXCLUIR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) ALUNO_PROCURA2, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_ALUNO, NULL, NULL);
}

void aluno_exclui_procura(L_ALUNO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	ALUNO *aluno = (ALUNO*) malloc(sizeof(ALUNO));
	
	if(aluno != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		aluno = procura_aluno(cod, head, janela);
		
		if(aluno != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_aluno_janela(janela, aluno);
			DestroyWindow(hb1);
			hb1 = CreateWindowW(L"button", L"EXCLUIR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) EXCLUI_ALUNO, NULL, NULL);
		}
	}
}


// --------------------------------------- JANELAS PACIENTE ---------------------------------------

void janela_menu_paciente(HWND janela){

    hb1 = CreateWindowW(L"button", L"CADASTRAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) PACIENTE_CADASTRAR, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR PACIENTES", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) PACIENTE_LISTAR, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"EDITAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) PACIENTE_EDITAR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"EXCLUIR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 270, 200, 50, janela, (HMENU) PACIENTE_EXCLUIR, NULL, NULL);
    hb5 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_MENU, NULL, NULL);
}

void paciente_cadastro_janela(HWND janela){

    hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 60, 750, 260, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"INSIRA NOME                             :", WS_VISIBLE | WS_CHILD, 100, 90, 250, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 90, 400, 25, janela, NULL, NULL, NULL);

	hs2 = CreateWindowW(L"static", L"INSIRA CPF                                 :", WS_VISIBLE | WS_CHILD, 100, 120, 250, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 120, 400, 25, janela, NULL, NULL, NULL);

	hs3 = CreateWindowW(L"static", L"INSIRA DATA DE NASCIMENTO  :", WS_VISIBLE | WS_CHILD, 100, 150, 250, 25, janela, NULL, NULL, NULL);
	hs4 = CreateWindowW(L"static", L"/         /", WS_VISIBLE | WS_CHILD, 385, 152, 100, 25, janela, NULL, NULL, NULL);
	hdia = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 150, 30, 25, janela, NULL, NULL, NULL);
	hmes = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 392, 150, 30, 25, janela, NULL, NULL, NULL);
	hano = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 432, 150, 50, 25, janela, NULL, NULL, NULL);
	
	hs5 = CreateWindowW(L"static", L"INSIRA ENDERECO  :", WS_VISIBLE | WS_CHILD, 100, 180, 250, 25, janela, NULL, NULL, NULL);

	hs6 = CreateWindowW(L"static", L"\tBAIRRO      :", WS_VISIBLE | WS_CHILD, 100, 210, 250, 25, janela, NULL, NULL, NULL);
	hbairro = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER| ES_WANTRETURN, 350, 210, 400, 25, janela, NULL, NULL, NULL);

	hs7 = CreateWindowW(L"static", L"\tRUA            :", WS_VISIBLE | WS_CHILD, 100, 240, 250, 25, janela, NULL, NULL, NULL);
	hrua = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER| ES_WANTRETURN, 350, 240, 400, 25, janela, NULL, NULL, NULL);

	hs8 = CreateWindowW(L"static", L"\tNUMERO    :", WS_VISIBLE | WS_CHILD, 100, 270, 250, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 270, 200, 25, janela, NULL, NULL, NULL);

    hb1 = CreateWindowW(L"button", L"CADASTRAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) P_CADASTRAR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_PACIENTE, NULL, NULL);
}

void lista_paciente_janela(HWND janela, L_PACIENTE *head){

	char lista[100000];

	hs2 = CreateWindowW(L"static", L"PACIENTES", WS_VISIBLE | WS_CHILD | SS_CENTER, 350, 70, 200, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);

	lista_paciente(head, lista);

 	SetWindowText(hlista, lista);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) VOLTAR_PACIENTE, NULL, NULL);
}

void paciente_edita_janela(HWND janela){
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO PACIENTE QUE DESEJA EDITAR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hb5 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) PACIENTE_PROCURA, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_PACIENTE, NULL, NULL);
}

void edita_paciente_janela(HWND janela, PACIENTE *paciente){
	
	char dia[3], mes[3], ano[5], num[6];
	
    hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 60, 750, 260, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"NOME                             :", WS_VISIBLE | WS_CHILD, 100, 90, 250, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 90, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hnome, paciente->dados.nome);

	hs2 = CreateWindowW(L"static", L"CPF                                 :", WS_VISIBLE | WS_CHILD, 100, 120, 250, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 120, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hcpf, paciente->dados.cpf);

	hs3 = CreateWindowW(L"static", L"DATA DE NASCIMENTO  :", WS_VISIBLE | WS_CHILD, 100, 150, 250, 25, janela, NULL, NULL, NULL);
	hs4 = CreateWindowW(L"static", L"/         /", WS_VISIBLE | WS_CHILD, 385, 152, 100, 25, janela, NULL, NULL, NULL);
	hdia = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 150, 30, 25, janela, NULL, NULL, NULL);
	sprintf(dia, "%d", paciente->dados.datanascimento.dia);
	SetWindowText(hdia, dia);
	
	hmes = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 392, 150, 30, 25, janela, NULL, NULL, NULL);
	sprintf(mes, "%d", paciente->dados.datanascimento.mes);
	SetWindowText(hmes, mes);
	
	hano = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 432, 150, 50, 25, janela, NULL, NULL, NULL);
	sprintf(ano, "%d", paciente->dados.datanascimento.ano);
	SetWindowText(hano, ano);
	
	hs5 = CreateWindowW(L"static", L"ENDERECO  :", WS_VISIBLE | WS_CHILD, 100, 180, 250, 25, janela, NULL, NULL, NULL);

	hs6 = CreateWindowW(L"static", L"\tBAIRRO      :", WS_VISIBLE | WS_CHILD, 100, 210, 250, 25, janela, NULL, NULL, NULL);
	hbairro = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER| ES_WANTRETURN, 350, 210, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hbairro, paciente->dados.end.bairro);

	hs7 = CreateWindowW(L"static", L"\tRUA            :", WS_VISIBLE | WS_CHILD, 100, 240, 250, 25, janela, NULL, NULL, NULL);
	hrua = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER| ES_WANTRETURN, 350, 240, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hrua, paciente->dados.end.rua);
	
	hs8 = CreateWindowW(L"static", L"\tNUMERO    :", WS_VISIBLE | WS_CHILD, 100, 270, 250, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 350, 270, 200, 25, janela, NULL, NULL, NULL);
	sprintf(num, "%d", paciente->dados.end.num);
	SetWindowText(hnum, num);
	
    hb1 = CreateWindowW(L"button", L"ATUALIZAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) ATUALIZA_PACIENTE, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_P_EDITA, NULL, NULL);
}

void paciente_edita_procura(L_PACIENTE *head, HWND janela, HWND hb5){
	
	char cdg[15];
	int cod;
	
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	if(paciente != NULL)
	{
		GetWindowText(hb5, cdg, 15);
        cod = atoi(cdg);
        
		paciente = procura_paciente(cod, head, janela);
		
		if(paciente != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_paciente_janela(janela, paciente);
		}
	}
}

void paciente_atualiza(L_PACIENTE *head, HWND janela, HWND hb5){
	
	char cdg[15];
	int cod;
	
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	if(paciente != NULL)
	{
		GetWindowText(hb5, cdg, 15);
        cod = atoi(cdg);
        
		paciente = procura_paciente(cod, head, janela);
		
		if(paciente != NULL)
		{
			dados_paciente(paciente, hnome, hcpf, hdia, hmes, hano, hbairro, hrua, hnum);
		}
	}
	
	MessageBoxW(janela, L"Paciente atualizado!", L"ATUALIZACAO", MB_OK | MB_ICONINFORMATION);
}

void paciente_exclui_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO PACIENTE QUE DESEJA EXCLUIR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hb5 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) PACIENTE_PROCURA2, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_PACIENTE, NULL, NULL);
}

void paciente_exclui_procura(L_PACIENTE *head, HWND janela, HWND hb5){
	
	char cdg[15];
	int cod;
	
	PACIENTE *paciente = (PACIENTE*) malloc(sizeof(PACIENTE));
	
	if(paciente != NULL)
	{
		GetWindowText(hb5, cdg, 15);
        cod = atoi(cdg);
        
		paciente = procura_paciente(cod, head, janela);
		
		if(paciente != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_paciente_janela(janela, paciente);
			DestroyWindow(hb1);
			hb1 = CreateWindowW(L"button", L"EXCLUIR PACIENTE ", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) EXCLUI_PACIENTE, NULL, NULL);
		}
	}
}


// --------------------------------------- JANELAS SUPERVISOR ---------------------------------------

void janela_menu_supervisor(HWND janela){

    hb1 = CreateWindowW(L"button", L"CADASTRAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) SUPERVISOR_CADASTRAR, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR SUPERVISORES", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) SUPERVISOR_LISTAR, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"EDITAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) SUPERVISOR_EDITAR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"EXCLUIR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 270, 200, 50, janela, (HMENU) SUPERVISOR_EXCLUIR, NULL, NULL);
    hb5 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_MENU, NULL, NULL);
}

void supervisor_cadastro_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 70, 720, 220, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"INSIRA NOME     :", WS_VISIBLE | WS_CHILD, 110, 105, 200, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 105, 400, 25, janela, NULL, NULL, NULL);

	hs2 = CreateWindowW(L"static", L"INSIRA CODIGO  :", WS_VISIBLE | WS_CHILD, 110, 165, 200, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 165, 200, 25, janela, NULL, NULL, NULL);

	hs3 = CreateWindowW(L"static", L"INSIRA CURSO   :", WS_VISIBLE | WS_CHILD, 110, 225, 200, 25, janela, NULL, NULL, NULL);
	hcurso = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 225, 400, 25, janela, NULL, NULL, NULL);

    hb1 = CreateWindowW(L"button", L"CADASTRAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) S_CADASTRAR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_SUPERVISOR, NULL, NULL);
}

void lista_supervisor_janela(HWND janela, L_SUPERVISOR *head){

	char lista[100000];

	hs2 = CreateWindowW(L"static", L"SUPERVISORES", WS_VISIBLE | WS_CHILD | SS_CENTER, 350, 70, 200, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);

	lista_supervisor(head, lista);

 	SetWindowText(hlista, lista);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) VOLTAR_SUPERVISOR, NULL, NULL);
}

void supervisor_edita_janela(HWND janela){
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO SUPERVISOR QUE DESEJA EDITAR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) SUPERVISOR_PROCURA, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_SUPERVISOR, NULL, NULL);
}

void edita_supervisor_janela(HWND janela, SUPERVISOR *supervisor){
	
	char cod[15];
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 70, 720, 220, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"NOME    :", WS_VISIBLE | WS_CHILD, 110, 105, 200, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 105, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hnome, supervisor->dados.nome);
	
	hs2 = CreateWindowW(L"static", L"CODIGO  :", WS_VISIBLE | WS_CHILD, 110, 165, 200, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 165, 200, 25, janela, NULL, NULL, NULL);
	sprintf(cod, "%d", supervisor->dados.cod);
	SetWindowText(hcod, cod);
	
	
	hs3 = CreateWindowW(L"static", L"CURSO   :", WS_VISIBLE | WS_CHILD, 110, 225, 200, 25, janela, NULL, NULL, NULL);
	hcurso = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 310, 225, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hcurso, supervisor->dados.curso);

    hb1 = CreateWindowW(L"button", L"ATUALIZAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) ATUALIZA_SUPERVISOR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_S_EDITA, NULL, NULL);
}

void supervisor_edita_procura(L_SUPERVISOR *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	if(supervisor != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		supervisor = procura_supervisor(cod, head, janela);
		
		if(supervisor != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_supervisor_janela(janela, supervisor);
		}
	}
}

void supervisor_atualiza(L_SUPERVISOR *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	if(supervisor != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		supervisor = procura_supervisor(cod, head, janela);
		
		if(supervisor != NULL)
		{
			dados_supervisor(supervisor, hnome, hcurso, hcod);
		}
	}
	
	MessageBoxW(janela, L"Supervisor atualizado!", L"ATUALIZACAO", MB_OK | MB_ICONINFORMATION);
}

void supervisor_exclui_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO SUPERVISOR QUE DESEJA EXCLUIR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) SUPERVISOR_PROCURA2, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_SUPERVISOR, NULL, NULL);
}

void supervisor_exclui_procura(L_SUPERVISOR *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	SUPERVISOR *supervisor = (SUPERVISOR*) malloc(sizeof(SUPERVISOR));
	
	if(supervisor != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		supervisor = procura_supervisor(cod, head, janela);
		
		if(supervisor != NULL)
		{
			DestroyWindow(hs);
			DestroyWindow(hs1);
			DestroyWindow(hb1);
			DestroyWindow(hb2);
			edita_supervisor_janela(janela, supervisor);
			DestroyWindow(hb1);
			hb1 = CreateWindowW(L"button", L"EXCLUIR SUPERVISOR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) EXCLUI_SUPERVISOR, NULL, NULL);
		}
	}
}


// --------------------------------------- JANELAS AGENDAMENTO ---------------------------------------

void janela_menu_agendamento(HWND janela){

    hb1 = CreateWindowW(L"button", L"CADASTRAR AGENDAMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) AGENDAMENTO_CADASTRAR, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR AGENDAMENTOS", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) AGENDAMENTO_LISTAR, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"CANCELAR AGENDAMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) AGENDAMENTO_EXCLUIR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_MENU, NULL, NULL);
}

void agendamento_cadastro_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 150, 70, 600, 220, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"INSIRA CODIGO DO PACIENTE     :", WS_VISIBLE | WS_CHILD, 190, 105, 280, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 105, 215, 25, janela, NULL, NULL, NULL);

	hs2 = CreateWindowW(L"static", L"INSIRA AREA DO ATENDIMENTO :", WS_VISIBLE | WS_CHILD, 190, 165, 280, 25, janela, NULL, NULL, NULL);
	harea = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 165, 215, 25, janela, NULL, NULL, NULL);

	hs3 = CreateWindowW(L"static", L"INSIRA DATA DA CONSULTA        :", WS_VISIBLE | WS_CHILD, 190, 225, 280, 25, janela, NULL, NULL, NULL);
	hs4 = CreateWindowW(L"static", L"/         /", WS_VISIBLE | WS_CHILD, 535, 227, 100, 25, janela, NULL, NULL, NULL);
	hdia = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 225, 30, 25, janela, NULL, NULL, NULL);
	hmes = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 542, 225, 30, 25, janela, NULL, NULL, NULL);
	hano = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 582, 225, 50, 25, janela, NULL, NULL, NULL);

    hb1 = CreateWindowW(L"button", L"CADASTRAR AGENDAMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) AG_CADASTRAR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_AGENDAMENTO, NULL, NULL);
}

void lista_agendamento_janela(HWND janela, L_AGENDAMENTO *head){

	char lista[100000];

	hs2 = CreateWindowW(L"static", L"AGENDAMENTOS", WS_VISIBLE | WS_CHILD | SS_CENTER, 350, 70, 200, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);
	
	lista_agendamento(head, lista);

 	SetWindowText(hlista, lista);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) VOLTAR_AGENDAMENTO, NULL, NULL);
}

void exclui_agendamento_janela(HWND janela, AGENDAMENTO *agendamento){
	
	char dia[3], mes[3], ano[5], num[10], cod[10];
	
    hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 60, 750, 260, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"CODIGO DO AGENDAMENTO :", WS_VISIBLE | WS_CHILD, 100, 90, 250, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 90, 200, 25, janela, NULL, NULL, NULL);
	sprintf(num, "%d", agendamento->dados.cod);
	SetWindowText(hnum, num);
	
	hs2 = CreateWindowW(L"static", L"NOME DO PACIENTE              :", WS_VISIBLE | WS_CHILD, 100, 130, 250, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 130, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hnome, agendamento->dados.paciente_nome);

	hs3 = CreateWindowW(L"static", L"CODIGO DO PACIENTE           :", WS_VISIBLE | WS_CHILD, 100, 170, 250, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 170, 200, 25, janela, NULL, NULL, NULL);
	sprintf(cod, "%d", agendamento->dados.paciente_cod);
	SetWindowText(hcod, cod);
	
	hs4 = CreateWindowW(L"static", L"AREA DO ATENDIMENTO       :", WS_VISIBLE | WS_CHILD, 100, 210, 250, 25, janela, NULL, NULL, NULL);
	harea = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 210, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(harea, agendamento->dados.area);
	
	hs5 = CreateWindowW(L"static", L"DATA DO AGENDAMENTO      :", WS_VISIBLE | WS_CHILD, 100, 250, 250, 25, janela, NULL, NULL, NULL);
	hs6 = CreateWindowW(L"static", L"/         /", WS_VISIBLE | WS_CHILD, 385, 552, 100, 25, janela, NULL, NULL, NULL);
	hdia = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 250, 30, 25, janela, NULL, NULL, NULL);
	sprintf(dia, "%d", agendamento->dados.data.dia);
	SetWindowText(hdia, dia);
	
	hmes = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 392, 250, 30, 25, janela, NULL, NULL, NULL);
	sprintf(mes, "%d", agendamento->dados.data.mes);
	SetWindowText(hmes, mes);
	
	hano = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 432, 250, 50, 25, janela, NULL, NULL, NULL);
	sprintf(ano, "%d", agendamento->dados.data.ano);
	SetWindowText(hano, ano);
	

    hb1 = CreateWindowW(L"button", L"EXCLUIR AGENDAMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) EXCLUI_AGENDAMENTO, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_AG_EXCLUI, NULL, NULL);

}

void agendamento_exclui_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO AGENDAMENTO QUE DESEJA EXCLUIR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"PROCURAR AGENDAMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) AGENDAMENTO_PROCURA, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_AGENDAMENTO, NULL, NULL);
}

void agendamento_exclui_procura(L_AGENDAMENTO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	AGENDAMENTO *agendamento = (AGENDAMENTO*) malloc(sizeof(AGENDAMENTO));
	
	if(agendamento != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		agendamento = procura_agendamento(cod, head, janela);
		
		if(agendamento != NULL)
		{
			destroi_janelas();
			exclui_agendamento_janela(janela, agendamento);
		}
	}
}


// --------------------------------------- JANELAS ATENDIMENTO ---------------------------------------

void janela_menu_atendimento(HWND janela){

    hb1 = CreateWindowW(L"button", L"CADASTRAR ATENDIMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) ATENDIMENTO_CADASTRAR, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR ATENDIMENTOS", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) ATENDIMENTO_LISTAR, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"CANCELAR ATENDIMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) ATENDIMENTO_EXCLUIR, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_MENU, NULL, NULL);
}

void atendimento_cadastro_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 150, 70, 600, 220, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"INSIRA CODIGO DO AGENDAMENTO :", WS_VISIBLE | WS_CHILD, 190, 105, 280, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 105, 215, 25, janela, NULL, NULL, NULL);

	hs2 = CreateWindowW(L"static", L"INSIRA CODIGO  DO SUPERVISOR    :", WS_VISIBLE | WS_CHILD, 190, 165, 280, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 165, 215, 25, janela, NULL, NULL, NULL);

	hs4 = CreateWindowW(L"static", L"INSIRA MATRICULA DO ALUNO         :", WS_VISIBLE | WS_CHILD, 190, 225, 280, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_WANTRETURN, 500, 225, 215, 25, janela, NULL, NULL, NULL);

    hb1 = CreateWindowW(L"button", L"CADASTRAR ATENDIMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 360, 200, 50, janela, (HMENU) AT_CADASTRAR, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_ATENDIMENTO, NULL, NULL);
}

void janela_lista_atendimento(HWND janela){

    hb1 = CreateWindowW(L"button", L"LISTAR TODOS", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) LISTAR_TODOS, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"LISTAR POR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) LISTAR_ALUNO, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"LISTAR POR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) LISTAR_PACIENTE, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"LISTAR POR AREA", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 270, 200, 50, janela, (HMENU) LISTAR_AREA, NULL, NULL);
	hb5 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) VOLTAR_ATENDIMENTO, NULL, NULL);
}

void lista_todos_janela(HWND janela, L_ATENDIMENTO *head){

	char lista[100000];

	hs2 = CreateWindowW(L"static", L"ATENDIMENTOS", WS_VISIBLE | WS_CHILD | SS_CENTER, 350, 70, 200, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);

	lista_atendimento(head, lista);

 	SetWindowText(hlista, lista);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) ATENDIMENTO_LISTAR, NULL, NULL);
}

void lista_al_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE MATRICULA DO ALUNO QUE DESEJA LISTAR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"LISTAR ALUNO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) LISTA_AL, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) ATENDIMENTO_LISTAR, NULL, NULL);
}

void lista_al(HWND janela, L_ATENDIMENTO *head, char num[]){
	
	char lista[100000];
	int cod;
	
	cod = atoi(num);

	hs = CreateWindowW(L"static", L"ATENDIMENTOS", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 60, 200, 25, janela, NULL, NULL, NULL);
	hs1 = CreateWindowW(L"static", L"ALUNO MATRICULA: ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 90, 200, 25, janela, NULL, NULL, NULL);
	hs2 = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 410, 90, 200, 25, janela, NULL, NULL, NULL);
	SetWindowText(hs2, num);
	
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 135, 650, 230, janela, NULL, NULL, NULL);

	lista_atendimento_aluno(cod, head, lista);

 	SetWindowText(hlista, lista);
	hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 375, 200, 50, janela, (HMENU) LISTAR_ALUNO, NULL, NULL);
}

void lista_p_janela(HWND janela){
	
	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO PACIENTE QUE DESEJA LISTAR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);

	hb1 = CreateWindowW(L"button", L"LISTAR PACIENTE", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) LISTA_P, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) ATENDIMENTO_LISTAR, NULL, NULL);
}

void lista_p(HWND janela, L_ATENDIMENTO *head, char num[]){
	
	char lista[100000];
	int cod;
	
	cod = atoi(num);

	hs = CreateWindowW(L"static", L"ATENDIMENTOS", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 300, 60, 200, 25, janela, NULL, NULL, NULL);
	hs1 = CreateWindowW(L"static", L"PACIENTE CODIGO: ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 200, 90, 200, 25, janela, NULL, NULL, NULL);
	hs2 = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 410, 90, 200, 25, janela, NULL, NULL, NULL);
	SetWindowText(hs2, num);
	
	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 120, 650, 230, janela, NULL, NULL, NULL);

	lista_atendimento_paciente(cod, head, lista);

 	SetWindowText(hlista, lista);
	hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) LISTAR_PACIENTE, NULL, NULL);
}

void janela_lista_area(HWND janela){

    hb1 = CreateWindowW(L"button", L"PSICOLOGIA", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 90, 200, 50, janela, (HMENU) PSICOLOGIA, NULL, NULL);
    hb2 = CreateWindowW(L"button", L"ODONTOLOGIA", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 150, 200, 50, janela, (HMENU) ODONTOLOGIA, NULL, NULL);
    hb3 = CreateWindowW(L"button", L"FISIOTERAPIA", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 350, 210, 200, 50, janela, (HMENU) FISIOTERAPIA, NULL, NULL);
    hb4 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 360, 200, 50, janela, (HMENU) ATENDIMENTO_LISTAR, NULL, NULL);
}

void lista_psico(HWND janela, L_ATENDIMENTO *head){
	
	char lista[100000], area[15];

	hs1 = CreateWindowW(L"static", L"\nPSICOLOGIA :", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 70, 150, 50, janela, NULL, NULL, NULL);
    hs2 = CreateWindowW(L"static", L"psicologia.bmp", WS_VISIBLE | WS_CHILD | SS_BITMAP, 300, 70, 100, 100, janela, NULL, NULL, NULL);
    SendMessageW(hs2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hpsicImage);
	
	strcpy(area, "psicologia");
	lista_atendimento_area(area, head, lista);

	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 135, 650, 230, janela, NULL, NULL, NULL);
 	SetWindowText(hlista, lista);
    hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 375, 200, 50, janela, (HMENU) VOLTAR_LISTA, NULL, NULL);
}

void lista_odonto(HWND janela, L_ATENDIMENTO *head){
	
	char lista[100000], area[15];	
	
	hs1 = CreateWindowW(L"static", L"\nODONTOLOGIA :", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 70, 150, 50, janela, NULL, NULL, NULL);
    hs2 = CreateWindowW(L"static", L"odontologia.bmp", WS_VISIBLE | WS_CHILD | SS_BITMAP, 300, 70, 100, 100, janela, NULL, NULL, NULL);
    SendMessageW(hs2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hodonImage);
	
	strcpy(area, "odontologia");
	lista_atendimento_area(area, head, lista);

	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 135, 650, 230, janela, NULL, NULL, NULL);
 	SetWindowText(hlista, lista);
    hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 375, 200, 50, janela, (HMENU) VOLTAR_LISTA, NULL, NULL);
}

void lista_fisio(HWND janela, L_ATENDIMENTO *head){	
		
	char lista[100000], area[15];	
	
	hs1 = CreateWindowW(L"static", L"\nFISIOTERAPIA :", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 70, 150, 50, janela, NULL, NULL, NULL);
    hs2 = CreateWindowW(L"static", L"fisioterapia.bmp", WS_VISIBLE | WS_CHILD | SS_BITMAP, 300, 70, 200, 100, janela, NULL, NULL, NULL);
    SendMessageW(hs2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hfisioImage);
	
	strcpy(area, "fisioterapia");
	lista_atendimento_area(area, head, lista);

	hlista = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 100, 135, 650, 230, janela, NULL, NULL, NULL);
 	SetWindowText(hlista, lista);
    hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 375, 200, 50, janela, (HMENU) VOLTAR_LISTA, NULL, NULL);
}

int lista_vazia_atendimento(L_ATENDIMENTO *head, HWND janela){

	if((*head) == NULL)
	{
		hs = CreateWindowW(L"static", L"LISTA VAZIA", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 350, 200, 150, 25, janela, NULL, NULL, NULL);
		hb1 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 550, 360, 200, 50, janela, (HMENU) VOLTAR_ATENDIMENTO, NULL, NULL);
		return 1;
	}

	return 0;
}

void exclui_atendimento_janela(HWND janela, ATENDIMENTO *atendimento){
	
	char dia[3], mes[3], ano[5], num[10], cod[10], coda[10], cods[10], codp[10];
	
    hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER , 70, 58, 750, 330, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"CODIGO DO ATENDIMENTO :", WS_VISIBLE | WS_CHILD, 100, 75, 250, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 75, 200, 25, janela, NULL, NULL, NULL);
	sprintf(num, "%d", atendimento->dados.cod);
	SetWindowText(hnum, num);
	
	hs2 = CreateWindowW(L"static", L"CODIGO DO AGENDAMENTO :", WS_VISIBLE | WS_CHILD, 100, 105, 250, 25, janela, NULL, NULL, NULL);
	hb3 = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 105, 200, 25, janela, NULL, NULL, NULL);
	sprintf(coda, "%d", atendimento->dados.agendamento_cod);
	SetWindowText(hb3, coda);

	hs3 = CreateWindowW(L"static", L"AREA DO ATENDIMENTO       :", WS_VISIBLE | WS_CHILD, 100, 135, 250, 25, janela, NULL, NULL, NULL);
	harea = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 135, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(harea, atendimento->dados.area);
	
	hs4 = CreateWindowW(L"static", L"NOME DO PACIENTE              :", WS_VISIBLE | WS_CHILD, 100, 165, 250, 25, janela, NULL, NULL, NULL);
	hcurso = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 165, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hcurso, atendimento->dados.paciente_nome);

	hs5 = CreateWindowW(L"static", L"CODIGO DO PACIENTE           :", WS_VISIBLE | WS_CHILD, 100, 195, 250, 25, janela, NULL, NULL, NULL);
	hcpf = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 195, 200, 25, janela, NULL, NULL, NULL);
	sprintf(codp, "%d", atendimento->dados.paciente_cod);
	SetWindowText(hcpf, codp);
		
	hs6 = CreateWindowW(L"static", L"NOME DO SUPERVISOR              :", WS_VISIBLE | WS_CHILD, 100, 225, 250, 25, janela, NULL, NULL, NULL);
	hbairro = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 225, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hbairro, atendimento->dados.supervisor_nome);

	hs7 = CreateWindowW(L"static", L"CODIGO DO SUPERVISOR           :", WS_VISIBLE | WS_CHILD, 100, 255, 250, 25, janela, NULL, NULL, NULL);
	hrua = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 255, 200, 25, janela, NULL, NULL, NULL);
	sprintf(cods, "%d", atendimento->dados.supervisor_cod);
	SetWindowText(hrua, cods);
	
	hs8 = CreateWindowW(L"static", L"NOME DO ALUNO             :", WS_VISIBLE | WS_CHILD, 100, 285, 250, 25, janela, NULL, NULL, NULL);
	hnome = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 285, 400, 25, janela, NULL, NULL, NULL);
	SetWindowText(hnome, atendimento->dados.aluno_nome);

	hb4 = CreateWindowW(L"static", L"MATRICULA DO ALUNO           :", WS_VISIBLE | WS_CHILD, 100, 315, 250, 25, janela, NULL, NULL, NULL);
	hcod = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 315, 200, 25, janela, NULL, NULL, NULL);
	sprintf(cod, "%d", atendimento->dados.aluno_cod);
	SetWindowText(hcod, cod);
	
	hb5 = CreateWindowW(L"static", L"DATA DO AGENDAMENTO      :", WS_VISIBLE | WS_CHILD, 100, 345, 250, 25, janela, NULL, NULL, NULL);
	hlista = CreateWindowW(L"static", L"/         /", WS_VISIBLE | WS_CHILD, 385, 342, 100, 25, janela, NULL, NULL, NULL);
	hdia = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 350, 345, 30, 25, janela, NULL, NULL, NULL);
	sprintf(dia, "%d", atendimento->dados.data.dia);
	SetWindowText(hdia, dia);
	
	hmes = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 392, 345, 30, 25, janela, NULL, NULL, NULL);
	sprintf(mes, "%d", atendimento->dados.data.mes);
	SetWindowText(hmes, mes);
	
	hano = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 432, 345, 50, 25, janela, NULL, NULL, NULL);
	sprintf(ano, "%d", atendimento->dados.data.ano);
	SetWindowText(hano, ano);
	

    hb1 = CreateWindowW(L"button", L"EXCLUIR ATENDIMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 175, 400, 200, 50, janela, (HMENU) EXCLUI_ATENDIMENTO, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 475, 400, 200, 50, janela, (HMENU) VOLTAR_AT_EXCLUI, NULL, NULL);

}

void atendimento_exclui_janela(HWND janela){

	hs = CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 220, 70, 450, 200, janela, NULL, NULL, NULL);

	hs1 = CreateWindowW(L"static", L"DIGITE CODIGO DO ATENDIMENTO QUE DESEJA EXCLUIR:", WS_VISIBLE | WS_CHILD | SS_CENTER, 250, 110, 400, 25, janela, NULL, NULL, NULL);
	hnum = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 350, 160, 200, 25, janela, NULL, NULL, NULL);
	
	hb1 = CreateWindowW(L"button", L"PROCURAR ATENDIMENTO", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 190, 360, 200, 50, janela, (HMENU) ATENDIMENTO_PROCURA, NULL, NULL);
	hb2 = CreateWindowW(L"button", L"VOLTAR", WS_VISIBLE | WS_CHILD | WS_CLIPCHILDREN, 490, 360, 200, 50, janela, (HMENU) VOLTAR_ATENDIMENTO, NULL, NULL);
}

void atendimento_exclui_procura(L_ATENDIMENTO *head, HWND janela, HWND hnum){
	
	char cdg[15];
	int cod;
	
	ATENDIMENTO *atendimento = (ATENDIMENTO*) malloc(sizeof(ATENDIMENTO));
	
	if(atendimento != NULL)
	{
		GetWindowText(hnum, cdg, 15);
        cod = atoi(cdg);
        
		atendimento = procura_atendimento(cod, head, janela);
		
		if(atendimento != NULL)
		{
			destroi_janelas();
			exclui_atendimento_janela(janela, atendimento);
		}
	}
}
