/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: menu_templates.c - funções void para aparência dos menus
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "menu_templates.h"

void menu_inicial()
{
    printf("\033[34m"); // Define a cor azul
    printf("===============================================\n");
    printf("                 SISTEMA AURORA                \n");
    printf("===============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    printf("Informe quantos alunos você irá cadastrar: ");
}

void menu_principal()
{
    printf("\n");
    printf("\033[34m"); // Define a cor azul
    printf("============================================\n");
    printf("               MENU PRINCIPAL               \n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    printf("[1] - Cadastrar estudante\n");
    printf("[2] - Buscar estudante pelo nome\n");
    printf("[3] - Buscar estudante pela matrícula\n");
    printf("[4] - Emitir relatórios\n");
    printf("[5] - Sair\n");
    printf("\033[34m============================================\033[0m\n");
    printf("Selecionar: ");
}

void menu_continuar_cadastro()
{
    printf("Deseja continuar o cadastro de estudantes?\n");
    printf("[1] Sim\n");
    printf("[2] Não\n");
    printf("Escolha uma opção: ");
}

void menu_relatorios()
{
    printf("\n");
    printf("\033[32m"); // Define a cor verde
    printf("============================================\n");
    printf("             EMISSÃO DE RELATÓRIOS          \n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    printf("[1] - Listar estudantes por curso\n");
    printf("[2] - Listar estudantes pelo valor da mensalidade\n");
    printf("[3] - Voltar\n");
    printf("============================================\n");
    printf("Selecionar: ");
}

void menu_invalido()
{
    printf("\n");
    printf("\033[31m"); // Define a cor vermelha
    printf("============================================\n");
    printf("!!! Opção inválida. Por favor, escolha uma opção válida do menu. !!!\n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
}

void tela_encerramento()
{
    printf("\n");
    printf("============================================\n");
    printf("Finalizando...\n");
    printf("Programa encerrado!\n");
    printf("============================================\n");
    exit(0);
}