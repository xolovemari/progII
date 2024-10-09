#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int main ( ) {
    FILE *arq;
    char nome[MAX], token[MAX], palavra[MAX];
    int count = 0;

    printf("Arquivo de entrada: ");
    fgets(nome, MAX, stdin);
    nome[strlen(nome) - 1] = '\0';

    arq = fopen(nome, "r");
    if(arq == NULL)
        return -1;

    printf("Palavra a ser buscada: ");
    scanf("%s", token);

    while(fscanf(arq, "%s", palavra) == 1) {
        if(strcmp(palavra, token) == 0)
            count++;
    }

    printf("%d", count);

    fclose(arq);

    return 0;
}