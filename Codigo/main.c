#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "bibliotecas.h"
#include "interface.h"



/*
	UNIVERSIDADE ESTADUAL DA PARAIBA
	
	
	COMPONENTE CURRICULAR: Laboratorio de programacao I	
	PROFESSOR: Danilo Abreu
	ALUNA: Adrielly de Medeiros Santos
	
	
	PROGRAMA: Clinica
	INTERFACE: windows.h

*/



int codp = 1000, codag = 1000, codat = 1000;

const char ClassName[] = "janela_classe";

HWND hb1, hb2, hb3, hb4, hb5, hnome, hcpf, hcod, hcurso, hbairro, hrua, hnum, hs, hs1, hs2, hs3, hs4, hs5, hs6, hs7, hs8, hlista, hdia, hmes, hano, harea;


LRESULT CALLBACK WndProc(HWND janela, UINT msg, WPARAM wparam, LPARAM lParam){	
	
	int esc;
	char num[10];

	L_ALUNO *head_aluno = criar_lista_aluno();
	L_PACIENTE *head_paciente = criar_lista_paciente();
	L_SUPERVISOR *head_supervisor = criar_lista_supervisor();
	L_AGENDAMENTO *head_agendamento = criar_lista_agendamento();
	L_ATENDIMENTO *head_atendimento = criar_lista_atendimento();
	
	inicializa_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento, &codp, &codag, &codat);
	

    switch(msg)
    {
        case WM_CREATE: carrega_imagem();
                        janela_login(janela);
                        break;

        case WM_COMMAND:
        	
            switch(wparam)
            {	
            	case ENTRAR: if(confere_senha(janela) == 0)
            				 {
            				 	destroi_janelas();
            				 	janela_principal(janela);
							 }
							 break;
							 
// --------------------------------------- BOTOES ALUNO ---------------------------------------							 
            	
                case MENU_ALUNO: destroi_janelas();
                                 janela_menu_aluno(janela);
                                 break;

                case ALUNO_CADASTRAR: destroi_janelas();
                                      aluno_cadastro_janela(janela);
                                      break;

                case A_CADASTRAR: cadastrar_aluno(head_aluno, janela, hnome, hcpf, hcurso, hcod);
                				  atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
                				  break;

				case ALUNO_LISTAR: destroi_janelas();
								   lista_aluno_janela(janela, head_aluno);
								   break;

                case ALUNO_EDITAR: destroi_janelas();
                				   aluno_edita_janela(janela);
								   break;
								   
				case ALUNO_PROCURA: GetWindowText(hnum, num, 10);
									if(strcmp(num, "") == 0)
									{
										MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
									}
									else
									{
										aluno_edita_procura(head_aluno, janela, hnum);
									}
									break;
									
				case ATUALIZA_ALUNO: aluno_atualiza(head_aluno, janela, hnum);
									 atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
									 break;

                case ALUNO_EXCLUIR: destroi_janelas();
                					aluno_exclui_janela(janela);
									break;
				
				case ALUNO_PROCURA2: GetWindowText(hnum, num, 10);
									 if(strcmp(num, "") == 0)
									 {
										MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
									 }
									 else
									 {
										aluno_exclui_procura(head_aluno, janela, hnum);
									 }
									 
								 	 break;
								 	 
				case EXCLUI_ALUNO: esc = MessageBoxW(NULL, L"Tem certeza?", L"EXCLUIR ALUNO", MB_YESNO | MB_ICONEXCLAMATION);
			                       if(esc == IDYES)
			                       {	
			                           exclui_aluno(head_aluno, janela, hnum);
			                           destroi_janelas();
			                           aluno_exclui_janela(janela);
			                           atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
			                       }
								   break;

                case VOLTAR_ALUNO: destroi_janelas();
                				   janela_menu_aluno(janela);
								   break;
								   
				case VOLTAR_AL_EDITA: destroi_janelas();
									  aluno_edita_janela(janela);
									  break;
									  
				case VOLTAR_AL_EXCLUI: destroi_janelas();
									   aluno_exclui_janela(janela);
									   break;
									  
// --------------------------------------- BOTOES PACIENTE ---------------------------------------

				case MENU_PACIENTE: destroi_janelas();
                               		janela_menu_paciente(janela);
                                    break;

				case PACIENTE_CADASTRAR: destroi_janelas();
										 paciente_cadastro_janela(janela);
										 break;

				case P_CADASTRAR: cadastrar_paciente(head_paciente, janela, hnome, hcpf, hdia, hmes, hano, hbairro, hrua, hnum, codp);
								  atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
					   			  break;

				case PACIENTE_LISTAR: destroi_janelas();
								   	  lista_paciente_janela(janela, head_paciente);
								   	  break;

                case PACIENTE_EDITAR: destroi_janelas();
                					  paciente_edita_janela(janela);
					                  break;
					                  
				case PACIENTE_PROCURA: GetWindowText(hb5, num, 10);
									   if(strcmp(num, "") == 0)
									   {
									 		MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
									   }
 									   else
									   {
											paciente_edita_procura(head_paciente, janela, hb5);
									   }
									   break;
									   
				case ATUALIZA_PACIENTE: paciente_atualiza(head_paciente, janela, hb5);
									 	atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
									 	break;

                case PACIENTE_EXCLUIR: destroi_janelas();
                					   paciente_exclui_janela(janela);
					                   break;
					                   
				case PACIENTE_PROCURA2: GetWindowText(hb5, num, 10);
										if(strcmp(num, "") == 0)
										{
											MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
										}
										else
										{
											paciente_exclui_procura(head_paciente, janela, hb5);
										}
								 		break;
								 	 
				case EXCLUI_PACIENTE: esc = MessageBoxW(NULL, L"Tem certeza?", L"EXCLUIR PACIENTE", MB_YESNO | MB_ICONEXCLAMATION);
			                       	  if(esc == IDYES)
			                       	  {	
				                           exclui_paciente(head_paciente, janela, hb5);
				                           destroi_janelas();
				                           paciente_exclui_janela(janela);
				                           atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
			                          }
								   	  break;
				

                case VOLTAR_PACIENTE: destroi_janelas();
                		  			  janela_menu_paciente(janela);
					                  break;
				
				case VOLTAR_P_EDITA: destroi_janelas();
									 paciente_edita_janela(janela);
									 break;
									  
				case VOLTAR_P_EXCLUI: destroi_janelas();
									  paciente_exclui_janela(janela);
									  break;

// --------------------------------------- BOTOES SUPERVISOR ---------------------------------------

				case MENU_SUPERVISOR: destroi_janelas();
                              		  janela_menu_supervisor(janela);
                                	  break;


				case SUPERVISOR_CADASTRAR: destroi_janelas();
										   supervisor_cadastro_janela(janela);
                                     	   break;

                case S_CADASTRAR: cadastrar_supervisor(head_supervisor, janela, hnome, hcurso, hcod);
								  atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
					   			  break;

				case SUPERVISOR_LISTAR: destroi_janelas();
								   		lista_supervisor_janela(janela, head_supervisor);
								   		break;

                case SUPERVISOR_EDITAR: destroi_janelas();
                						supervisor_edita_janela(janela);
						                break;
				
				case SUPERVISOR_PROCURA: GetWindowText(hnum, num, 10);
										 if(strcmp(num, "") == 0)
										 {
											MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
										 }
										 else
										 {
											supervisor_edita_procura(head_supervisor, janela, hnum);
										 }
									     break;
				
				case ATUALIZA_SUPERVISOR: supervisor_atualiza(head_supervisor, janela, hnum);
									 	  atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
									 	  break;
				
                case SUPERVISOR_EXCLUIR: destroi_janelas();
                						 supervisor_exclui_janela(janela);
						                 break;
						                 
				case SUPERVISOR_PROCURA2: GetWindowText(hnum, num, 10);
										  if(strcmp(num, "") == 0)
										  {
												MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
										  }
										  else
										  {
												supervisor_exclui_procura(head_supervisor, janela, hnum);
										  }
								 		  break;
								 	 
				case EXCLUI_SUPERVISOR: esc = MessageBoxW(NULL, L"Tem certeza?", L"EXCLUIR SUPERVISOR", MB_YESNO | MB_ICONEXCLAMATION);
			                       		if(esc == IDYES)
			                       	  	{	
				                        	exclui_supervisor(head_supervisor, janela, hnum);
				                        	destroi_janelas();
				                        	supervisor_exclui_janela(janela);
				                        	atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
			                          	}
								   	  	break;

                case VOLTAR_SUPERVISOR: destroi_janelas();
                				    	janela_menu_supervisor(janela);
										break;
										
				case VOLTAR_S_EDITA: destroi_janelas();
									 supervisor_edita_janela(janela);
									 break;
				
				case VOLTAR_S_EXCLUI: destroi_janelas();
									  supervisor_exclui_janela(janela);
									  break;
				

// --------------------------------------- BOTOES AGENDAMENTO ---------------------------------------

				case MENU_AGENDAMENTO: destroi_janelas();
                           		       janela_menu_agendamento(janela);
                                	   break;


				case AGENDAMENTO_CADASTRAR: destroi_janelas();
											agendamento_cadastro_janela(janela);
                                     		break;
                                     		
                case AG_CADASTRAR: cadastrar_agendamento(head_agendamento, head_paciente, janela, hcod, harea, hdia, hmes, hano, codag);
                				   atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
                				   break;

				case AGENDAMENTO_LISTAR: destroi_janelas();
                						 lista_agendamento_janela(janela, head_agendamento);
								   		 break;

                case AGENDAMENTO_EXCLUIR: destroi_janelas();
                						  agendamento_exclui_janela(janela);
										  break;
				
				case AGENDAMENTO_PROCURA: GetWindowText(hnum, num, 10);
										  if(strcmp(num, "") == 0)
										  {
												MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
										  }
										  else
										  {
												agendamento_exclui_procura(head_agendamento, janela, hnum);
										  }
								 		  break;
								 	 
				case EXCLUI_AGENDAMENTO: esc = MessageBoxW(NULL, L"Tem certeza?", L"EXCLUIR AGENDAMENTO", MB_YESNO | MB_ICONEXCLAMATION);
			                       		 if(esc == IDYES)
			                       	  	 {	
				                        	exclui_agendamento(head_agendamento, janela, hnum);
				                        	destroi_janelas();
				                        	agendamento_exclui_janela(janela);
				                        	atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
			                          	 }
								   	  	 break;

                case VOLTAR_AGENDAMENTO: destroi_janelas();
                						 janela_menu_agendamento(janela);
						                 break;
				
				case VOLTAR_AG_EXCLUI: destroi_janelas();
									   agendamento_exclui_janela(janela);
									   break;
				

// --------------------------------------- BOTOES ATENDIMENTO ---------------------------------------

				case MENU_ATENDIMENTO: destroi_janelas();
                                	   janela_menu_atendimento(janela);
                                       break;


				case ATENDIMENTO_CADASTRAR: destroi_janelas();
											atendimento_cadastro_janela(janela);
                                      		break;
                                      		
                case AT_CADASTRAR: cadastrar_atendimento(head_atendimento, head_agendamento, head_supervisor, head_aluno, janela, hcod, hnum, hcpf, codat);
                				   atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
                				   break;

				case ATENDIMENTO_LISTAR: destroi_janelas();
										 if(lista_vazia_atendimento(head_atendimento, janela) == 0)
								  		 {
										 	janela_lista_atendimento(janela);
								   		 }
						                 break;
				
				case LISTAR_TODOS: destroi_janelas();
								   lista_todos_janela(janela, head_atendimento);
								   break;
				
				case LISTAR_ALUNO: destroi_janelas();
								   lista_al_janela(janela);
								   break;
								   
				case LISTA_AL: GetWindowText(hnum, num, 10);
							   if(strcmp(num, "") == 0)
							   {
									MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
							   }
							   else
							   {
									destroi_janelas();
									lista_al(janela, head_atendimento, num);
							   }
							   break;
				
				case LISTAR_PACIENTE: destroi_janelas();
								   	  lista_p_janela(janela);
									  break;
									  
				case LISTA_P: GetWindowText(hnum, num, 10);
							  if(strcmp(num, "") == 0)
							  {
									MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
							  }
							  else
							  {
									destroi_janelas();
									lista_p(janela, head_atendimento, num);
							  }
							  break;
				
                case LISTAR_AREA: destroi_janelas();
								  janela_lista_area(janela);
				                  break;

                case PSICOLOGIA: destroi_janelas();
								 lista_psico(janela, head_atendimento);
								 break;

				case ODONTOLOGIA: destroi_janelas();
							   	  lista_odonto(janela, head_atendimento);
								  break;

				case FISIOTERAPIA: destroi_janelas();
								   lista_fisio(janela, head_atendimento);
								   break;

                case ATENDIMENTO_EXCLUIR: destroi_janelas();
                						  atendimento_exclui_janela(janela);
										  break;
				
				case ATENDIMENTO_PROCURA: GetWindowText(hnum, num, 10);
										  if(strcmp(num, "") == 0)
										  {
												MessageBoxW(janela, L"Existe(m) campo(s) em branco!", L"ERRO", MB_OK | MB_ICONERROR);
										  }
										  else
										  {
												atendimento_exclui_procura(head_atendimento, janela, hnum);
										  }
								 		  break;
								 	 
				case EXCLUI_ATENDIMENTO: esc = MessageBoxW(NULL, L"Tem certeza?", L"EXCLUIR ATENDIMENTO", MB_YESNO | MB_ICONEXCLAMATION);
			                       		 if(esc == IDYES)
			                       	  	 {	
				                        	exclui_atendimento(head_atendimento, head_agendamento, janela, hnum);
				                        	destroi_janelas();
				                        	atendimento_exclui_janela(janela);
				                        	atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
			                          	 }
								   	  	 break;

                case VOLTAR_LISTA: destroi_janelas();
                				   janela_lista_area(janela);
                				   break;

                case VOLTAR_ATENDIMENTO: destroi_janelas();
                						 janela_menu_atendimento(janela);
                						 break;
                
                case VOLTAR_AT_EXCLUI: destroi_janelas();
									   atendimento_exclui_janela(janela);
									   break;
                
				case VOLTAR_MENU: destroi_janelas();  // VOLTA AO MENU PRINCIPAL
                				  janela_principal(janela);
				                  break;
            }
            break;

        case WM_CLOSE: esc = MessageBoxW(NULL, L"Tem certeza que deseja sair?", L"Warning", MB_YESNO | MB_ICONEXCLAMATION);
                       if(esc == IDYES)
                       {
                            DestroyWindow(janela);
                            atualiza_arquivos(head_aluno, head_paciente, head_supervisor, head_agendamento, head_atendimento);
                       }
                       break;

        case WM_DESTROY: PostQuitMessage(0);
                         break;

        default:
             return DefWindowProc(janela, msg, wparam, lParam);
    }

    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmsLine, int nShowCmd){	

	WNDCLASSEX jnl;
    HWND janela;
    MSG msg;

	jnl.cbSize        = sizeof(WNDCLASSEX);
    jnl.style         = 0;
    jnl.cbClsExtra    = 0;
    jnl.cbWndExtra    = 0;
    jnl.lpszMenuName  = NULL;
    jnl.hInstance     = hInstance;
    jnl.hIcon         = LoadImageW(NULL, L"c2.ico", IMAGE_ICON, 36, 36, LR_LOADFROMFILE);
    jnl.hCursor       = LoadCursor(NULL, IDC_ARROW);
    jnl.hbrBackground = (HBRUSH)(COLOR_WINDOW-1);
    jnl.hIconSm       = LoadImageW(NULL, L"c2.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE);
    jnl.lpszClassName = ClassName;
    jnl.lpfnWndProc   = WndProc;


    if(RegisterClassEx(&jnl) == 0)
    {
        MessageBoxW(NULL, L"Window Registration Failed!", L"ERRO!", MB_ICONERROR | MB_OK);
        return 0;
	}

    janela = CreateWindowEx(0, ClassName, "UNIVERSIDADE ESTADUAL DA PARAÍBA - CLÍNICA", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 900, 550, NULL, NULL, NULL, NULL);

    if(janela == NULL)
    {
        MessageBoxW(NULL, L"Window Creation Failed!", L"ERRO!", MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(janela, nShowCmd);
    UpdateWindow(janela);

    while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
