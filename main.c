/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: main.c - Arquivo principal do programa
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <signal.h>
#include "estudante/estudante.h"
#include "menus/menu_templates.h"

int main()
{
    //Configura o idioma para portugues no terminal
    setlocale(LC_ALL, "Portuguese");
    //Configura a tela de encerramento para quando o usuário encerrar o programa com ctrl + c
    signal(SIGINT, tela_encerramento);

    //Variáveis de controle
    int tamanho_estudantes;
    int cont_estudantes_cadastrados = 0;
    int opcao = 0;
    int continuar_cadastro;

    menu_inicial();
    scanf("%d", &tamanho_estudantes);
    ESTUDANTE estudantes[tamanho_estudantes];

    do
    {
        limpar_buffer_entrada();
        menu_principal();
        scanf("%d", &opcao);

        switch (opcao)
        {
        // Menu de cadastro de estudantes
        case 1:
            do
            {
                if (cont_estudantes_cadastrados >= tamanho_estudantes)
                {
                    printf("\033[31mVocê atingiu o número máximo de cadastros!\033[0m\n");
                    break;
                }
                cadastrar_estudante(estudantes, cont_estudantes_cadastrados, tamanho_estudantes);
                cont_estudantes_cadastrados++;
                menu_continuar_cadastro();
                limpar_buffer_entrada();
                scanf("%d", &continuar_cadastro);
            } while(continuar_cadastro != 2);
            opcao = 0;
            break;
        //Menu de buscar por estudante pelo nome
        case 2:
            buscar_estudante_nome(estudantes, cont_estudantes_cadastrados);
            opcao = 0;
            break;
        //Menu de buscar por estudante pela matrícula
        case 3:
            buscar_estudante_matricula(estudantes, cont_estudantes_cadastrados);
            opcao = 0;
            break;
        //Menu de emissão de relatórios
        case 4:
            do
            {
                menu_relatorios();
                scanf("%d", &opcao);
                switch (opcao)
                {
                    case 1:
                        listar_estudante_curso(estudantes, cont_estudantes_cadastrados);
                        break;
                    case 2:
                        listar_estudante_mensalidade(estudantes, cont_estudantes_cadastrados);
                        break;
                    case 3:
                        break;
                    default:
                        menu_invalido();
                        break;
                }
            } while (opcao != 3);
            opcao = 0;
            break;
        case 5:
            break;
        default:
            menu_invalido();
            break;
        }
    } while (opcao != 5);

    tela_encerramento();
    return 0;
}