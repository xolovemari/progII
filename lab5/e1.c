#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct {
    char nome[MAX];
    float p1, p2, trabalho;
} avaliacoes;

int main ( ) {
    FILE *arq;
    avaliacoes aluno;
    int tam;
    char nome[MAX];

    printf("Informe o nome do arquivo: ");
    fgets(nome, MAX, stdin);
    nome[strlen(nome) - 1] = '\0';

    arq = fopen(nome, "w");
    if(arq == NULL) {
        return -1;
    }

    printf("Informe o tamanho da turma: ");
    scanf("%d", &tam);

    for(int i = 0; i < tam; i++) {
        printf("%d - Nome do aluno: ", i + 1);
        scanf("%s", aluno.nome);
        printf("P1: ");
        scanf("%f", &aluno.p1);
        printf("P2: ");
        scanf("%f", &aluno.p2);
        printf("Trabalho: ");
        scanf("%f", &aluno.trabalho);
        printf("\n");

        fprintf(arq, "%s %.2f %.2f %.2f\n", aluno.nome, aluno.p1, aluno.p2, aluno.trabalho);

    }

    fclose(arq);

    return 0;
}