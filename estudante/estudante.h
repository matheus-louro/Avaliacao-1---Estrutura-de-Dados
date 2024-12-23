/***************************************************************

Projeto: Avaliação 1 - Sistema Aurora
Arquivo: estudante.h - declarações das funções de estudante.c e a estrutura ESTUDANTE
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

typedef struct s
{
    int matricula;
    char nome[15];
    char sobrenome[20];
    char curso[20];
    float mensalidade;
} ESTUDANTE;

int cadastrar_estudante(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados, int tamanho_estudantes);
void buscar_estudante_nome(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados);
void buscar_estudante_matricula(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados);
void listar_estudante_curso(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados);
void listar_estudante_mensalidade(ESTUDANTE vetor_estudantes[], int cont_estudantes_cadastrados);
void limpar_buffer_entrada();