#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int main ( ) {
    char nome[MAX], linha[MAX];
    FILE *arq;
    int vogais[5] = {0, 0, 0, 0, 0};

    printf("Informe o nome do arquivo: ");
    fgets(nome, MAX, stdin);
    nome[strlen(nome) - 1] = '\0';

    arq = fopen(nome, "r");
    if(arq == NULL)
        return -1;

    while(fgets(linha, MAX, arq) != NULL) {
        for (int j = 0; linha[j] != '\0'; j++) {
            char c = linha[j];
            switch (c) {
                case 'a': case 'A': vogais[0]++; break;
                case 'e': case 'E': vogais[1]++; break;
                case 'i': case 'I': vogais[2]++; break;
                case 'o': case 'O': vogais[3]++; break;
                case 'u': case 'U': vogais[4]++; break;
            }
        }
    }

    // Exibe o resultado da contagem de vogais
    printf("Contagem de vogais:\n");
    printf("a: %d\n", vogais[0]);
    printf("e: %d\n", vogais[1]);
    printf("i: %d\n", vogais[2]);
    printf("o: %d\n", vogais[3]);
    printf("u: %d\n", vogais[4]);

    fclose(arq);

    return 0;
}