/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: ordenacao.c - Implementação dos algoritmos de ordenação Selection Sort e Merge Sort
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <stdlib.h>
#include <string.h>
#include "../estudante/estudante.h"
#include "ordenacao.h"

void selection_sort(ESTUDANTE vetor_estudantes[], int n, CRITERIO criterio, ORDEM ordem) {
    for (int i = 0; i < n - 1; i++) {
        // Encontra o índice do elemento de acordo com o critério e ordem a partir de i
        int elemento = i;
        for (int j = i + 1; j < n; j++) {
            if (ordem == CRESCENTE)
            {
                if (criterio == MATRICULA)
                {
                    if (vetor_estudantes[j].matricula < vetor_estudantes[elemento].matricula) {
                        elemento = j;
                    }
                }

                if (criterio == NOME)
                {
                    if (strcmp(vetor_estudantes[j].nome, vetor_estudantes[elemento].nome) <= 0) {
                        elemento = j;
                    }
                }

                if (criterio == MENSALIDADE)
                {
                    if (vetor_estudantes[j].mensalidade < vetor_estudantes[elemento].mensalidade) {
                        elemento = j;
                    }
                }
            }

            if (ordem == DESCRESCENTE)
            {
                if (criterio == MATRICULA)
                {
                    if (vetor_estudantes[j].matricula > vetor_estudantes[elemento].matricula) {
                        elemento = j;
                    }
                }

                if (criterio == NOME)
                {
                    if (strcmp(vetor_estudantes[j].nome, vetor_estudantes[elemento].nome) >= 0) {
                        elemento = j;
                    }
                }

                if (criterio == MENSALIDADE)
                {
                    if (vetor_estudantes[j].mensalidade > vetor_estudantes[elemento].mensalidade) {
                        elemento = j;
                    }
                }
            }
            
        }
        // Troca o elemento encontrado com o elemento da posição i
        if (elemento != i) {
            ESTUDANTE temp = vetor_estudantes[i];
            vetor_estudantes[i] = vetor_estudantes[elemento];
            vetor_estudantes[elemento] = temp;
        }
    }
}

void merge(ESTUDANTE arr[], int left, int mid, int right, CRITERIO criterio, ORDEM ordem) {
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    // Cria arrays temporários
    ESTUDANTE *L = (ESTUDANTE *)malloc(n1 * sizeof(ESTUDANTE));
    ESTUDANTE *R = (ESTUDANTE *)malloc(n2 * sizeof(ESTUDANTE));

    // Copia dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mescla os subarrays temporários de volta em arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        int comparar = 0; // Variável para armazenar o resultado da comparação

        if (ordem == CRESCENTE)
        {
            if (criterio == MATRICULA)
                comparar = (L[i].matricula <= R[j].matricula);
            else if (criterio == MENSALIDADE) 
                comparar = (L[i].mensalidade <= R[j].mensalidade);
            else if (criterio == NOME) 
                comparar = (strcmp(L[i].nome, R[j].nome) <= 0);
        }
        if (ordem == DESCRESCENTE)
        {
            if (criterio == MATRICULA)
                comparar = (L[i].matricula >= R[j].matricula);
            else if (criterio == MENSALIDADE) 
                comparar = (L[i].mensalidade >= R[j].mensalidade);
            else if (criterio == NOME) 
                comparar = (strcmp(L[i].nome, R[j].nome) >= 0);
        }
        
        // Decide qual elemento será adicionado ao array final
        if (comparar)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Função principal do Merge Sort
void merge_sort(ESTUDANTE arr[], int left, int right, CRITERIO criterio, ORDEM ordem) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, criterio, ordem);
        merge_sort(arr, mid + 1, right, criterio, ordem);

        // Mescla as duas metades
        merge(arr, left, mid, right, criterio, ordem);
    }
}