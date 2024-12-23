
/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: estudante.c - funções principais do menu
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "estudante.h"
#include "../ordenacao/ordenacao.h"
#include "../menus/menu_templates.h"

// Função para evitar bugs de entrada
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool string_valida(const char *s) {
    if (strlen(s) < 2){
        printf("\033[31mForneça mais que 2 caracteres!\033[0m\n");
        return false;
    }

    return true;
}

bool matricula_valida(int matricula, ESTUDANTE vetor_estudantes[], int estudantes_cadastrados) {    
    if (matricula < 100 || matricula > 150)
    {
        printf("\033[31mNúmero da matrícula inválido\033[0m\n");
        return false;
    }

    for (int i = 0; i < estudantes_cadastrados; i++) {
        if (vetor_estudantes[i].matricula == matricula)
        {
            printf("\033[31mNúmero de matrícula já existe\033[0m\n");
            return false;
        }
    }

    return true;
}

int cadastrar_estudante(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados, int tamanho_estudantes) 
{
    ESTUDANTE novo_estudante;

    printf("--------------------------------------------\n");
    printf(" Área de cadastro\n"); 
    printf("--------------------------------------------\n");

    //Entradas com uso do do-while para evitar valores que possam bugar a aplicação
    do
    {
        printf("Numero da matricula: ");
        scanf("%d", &novo_estudante.matricula);
    } while (!matricula_valida(novo_estudante.matricula, vetor_estudantes, cont_estudantes_cadastrados));
    
    do
    {
        printf("Primeiro Nome: ");
        scanf("%s", novo_estudante.nome);
    } while (!string_valida(novo_estudante.nome));
    
    do
    {
        printf("Sobrenome: ");
        scanf("%s", novo_estudante.sobrenome);
    } while (!string_valida(novo_estudante.sobrenome));

    do
    {
        printf("Curso: ");
        scanf("%s", novo_estudante.curso);
    } while (!string_valida(novo_estudante.curso));
    
    do
    {
        printf("mensalidade: ");
        scanf("%f", &novo_estudante.mensalidade);
    } while (&novo_estudante.mensalidade < 0);
    

    vetor_estudantes[cont_estudantes_cadastrados] = novo_estudante;
    
}

void buscar_estudante_nome(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados)
{
    if (cont_estudantes_cadastrados == 0)
    {
        printf("\033[31mNão há estudantes cadastrados!\033[0m\n");
        return;
    } 

    //Ordena o vetor de estudantes pelo nome usando o Merge sort
    merge_sort(vetor_estudantes, 0, cont_estudantes_cadastrados, NOME, CRESCENTE);

    char nome[20];
    printf("Digite o primeiro nome do aluno: ");
    limpar_buffer_entrada();
    scanf("%s", nome);

    //Utiliza busca binária para encontrar o estudante
    int l = 0, r = cont_estudantes_cadastrados;

    while (l <= r)
    {
        int meio = l + (r - l) / 2;
        if (strcmp(vetor_estudantes[meio].nome, nome) == 0)
        {
            printf("\n");
            printf("\033[36m");
            printf("============================================\n");
            printf(" Informações de %s %s\n", vetor_estudantes[meio].nome, vetor_estudantes[meio].sobrenome); 
            printf("============================================\n");
            printf("\033[0m");
            printf(" - Matrícula:                 %d\n", vetor_estudantes[meio].matricula);
            printf(" - Nome:                      %s\n", vetor_estudantes[meio].nome);
            printf(" - Sobrenome:                 %s\n", vetor_estudantes[meio].sobrenome);
            printf(" - Curso:                     %s\n", vetor_estudantes[meio].curso);
            printf(" - Mensalidade:               R$%.2f\n", vetor_estudantes[meio].mensalidade);
            printf("\033[36m ============================================\033[0m\n");
            return;
        }
        if (strcmp(vetor_estudantes[meio].nome, nome) < 0)
            l = meio + 1;
        else
            r = meio - 1;
    }
    //Caso não encontre o estudante
    printf("\033[31mInformação não localizada!\033[0m\n");
} 

void buscar_estudante_matricula(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados)
{
    if (cont_estudantes_cadastrados == 0)
    {
        printf("\033[31mNão há estudantes cadastrados!\033[0m\n");
        return;
    } 

    //Ordena o vetor de estudantes pela matrícula usando o Selection Sort
    selection_sort(vetor_estudantes, cont_estudantes_cadastrados, MATRICULA, CRESCENTE);

    int matricula;
    printf("Digite a matrícula do aluno: ");
    limpar_buffer_entrada();
    scanf("%d", &matricula);

    //Utiliza busca binária para encontrar o estudante
    int l = 0, r = cont_estudantes_cadastrados;

    while (l <= r)
    {
        int meio = l + (r - l) / 2;
        if (vetor_estudantes[meio].matricula == matricula)
        {
            printf("\n");
            printf("\033[36m");
            printf("============================================\n");
            printf(" Informações de %s %s\n", vetor_estudantes[meio].nome, vetor_estudantes[meio].sobrenome); 
            printf("============================================\n");
            printf("\033[0m");
            printf(" - Matrícula:                 %d\n", vetor_estudantes[meio].matricula);
            printf(" - Nome:                      %s\n", vetor_estudantes[meio].nome);
            printf(" - Sobrenome:                 %s\n", vetor_estudantes[meio].sobrenome);
            printf(" - Curso:                     %s\n", vetor_estudantes[meio].curso);
            printf(" - Mensalidade:               R$%.2f\n", vetor_estudantes[meio].mensalidade);
            printf("\033[36m ============================================\033[0m\n");
            return;
        }
        if (vetor_estudantes[meio].matricula < matricula)
            l = meio + 1;
        else
            r = meio - 1;
    }
    //Caso não encontre o estudante
    printf("\033[31mInformação não localizada!\033[0m\n");
}

void listar_estudante_curso(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados)
{
    if (cont_estudantes_cadastrados == 0)
    {
        printf("\033[31mNão há estudantes cadastrados!\033[0m\n");
        return;
    } 

    char curso[20];
    printf("Digite o nome do curso: ");
    limpar_buffer_entrada();
    scanf("%s", curso);

    //Variável que verifica se o curso existe 
    int curso_cadastrado = 0;

    //Ordena o vetor de estudantes pelo nome usando o Merge sort
    merge_sort(vetor_estudantes, 0, cont_estudantes_cadastrados, NOME, CRESCENTE);

    for (int i = 0; i < cont_estudantes_cadastrados; i++)
    {
        if (strcmp(vetor_estudantes[i].curso, curso) == 0)
        {
            curso_cadastrado = 1;
            printf("\n");
            printf("\033[36m");
            printf("============================================\n");
            printf(" Informações de %s %s\n", vetor_estudantes[i].nome, vetor_estudantes[i].sobrenome); 
            printf("============================================\n");
            printf("\033[0m");
            printf(" - Matrícula:                 %d\n", vetor_estudantes[i].matricula);
            printf(" - Nome:                      %s\n", vetor_estudantes[i].nome);
            printf(" - Sobrenome:                 %s\n", vetor_estudantes[i].sobrenome);
            printf(" - Curso:                     %s\n", vetor_estudantes[i].curso);
            printf(" - Mensalidade:               R$%.2f\n", vetor_estudantes[i].mensalidade);
            printf("\033[36m ============================================\033[0m\n");
        }
    }

    if (!curso_cadastrado)
        printf("\033[31mNão há estudantes nesse curso!\033[0m\n");
    
    limpar_buffer_entrada();
}

void listar_estudante_mensalidade(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados)
{
    if (cont_estudantes_cadastrados == 0)
    {
        printf("\033[31mNão há estudantes cadastrados!\033[0m\n");
        return;
    } 

    int opcao;
    do
    {
        printf("[1] - Ordem crescente\n");
        printf("[2] - Ordem decrescente\n");
        printf("Selecionar: ");
        limpar_buffer_entrada();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            selection_sort(vetor_estudantes, cont_estudantes_cadastrados, MENSALIDADE, CRESCENTE);
            break;
        case 2:
            selection_sort(vetor_estudantes, cont_estudantes_cadastrados, MENSALIDADE, DESCRESCENTE);
            break;
        default:
            menu_invalido();
            break;
        }
    } while (opcao != 1 && opcao != 2);
    
    for (int i = 0; i < cont_estudantes_cadastrados; i++)
    {
        printf("\n");
        printf("\033[36m");
        printf("=====================================================\n");
        printf(" Informações de %s %s\n", vetor_estudantes[i].nome, vetor_estudantes[i].sobrenome); 
        printf("=====================================================\n");
        printf("\033[0m");
        printf(" - Matrícula:                 %d\n", vetor_estudantes[i].matricula);
        printf(" - Nome:                      %s\n", vetor_estudantes[i].nome);
        printf(" - Sobrenome:                 %s\n", vetor_estudantes[i].sobrenome);
        printf(" - Curso:                     %s\n", vetor_estudantes[i].curso);
        printf(" - Mensalidade:               R$%.2f\n", vetor_estudantes[i].mensalidade);
        printf("\033[36m ============================================\033[0m\n");
    }
    
    limpar_buffer_entrada();
}