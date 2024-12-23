/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: ordenacao.h - Declaração das funções merge sort, selection sort e os enums CRITERIO e ORDEM, que ajudam a reutilizarmos as funções
de ordenação para ordenar os estudantes em diferentes categorias e ordens
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

//Enums para auxiliar nos algoritmos de ordenação
typedef enum {
    MATRICULA = 1,
    NOME,
    MENSALIDADE
} CRITERIO;

typedef enum {
    CRESCENTE,
    DESCRESCENTE
} ORDEM;

void selection_sort(ESTUDANTE vetor_estudantes[], int n, CRITERIO criterio, ORDEM ordem);
void merge_sort(ESTUDANTE arr[], int left, int right, CRITERIO criterio, ORDEM ordem);