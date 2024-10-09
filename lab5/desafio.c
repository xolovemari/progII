#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main ( ) {

    int A, C, h, m, s, tempoTotal, menorTempo = 99999;
    FILE *arq;
    char nome[MAX], atleta[MAX], vencedor[MAX];

    printf("Informe o nome do arquivo texto: ");
    gets(nome);

    arq = fopen(nome, "r");
    if(arq == NULL) {
        puts("Erro na abertura do arquivo.");
        return -1;
    }

    fscanf(arq, "%d %d", &A, &C);
    if(A < 1 || C < 1) {
        printf("Valores invalidos.");
        fclose(arq);
        return -1;
    }

    for(int i = 0; i < A; i++) {
        fscanf(arq, "%s", atleta);
        tempoTotal = 0;
        for(int j = 0; j < C; j++) {
            fscanf(arq, "%d %d %d", &h, &m, &s);
            tempoTotal += h * 3600 + m * 60 + s;            
        }
        if(tempoTotal < menorTempo) {
            menorTempo = tempoTotal;
            strcpy(vencedor, atleta);
        }
    }

    printf("%s %d", vencedor, menorTempo);
    fclose(arq);
}