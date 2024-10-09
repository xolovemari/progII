#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct {
    char nome[MAX];
    float p1, p2, trabalho;
} avaliacoes;

int main ( ) {
    FILE *arqin, *arqout;
    char in[MAX], out[MAX], linha[MAX];
    avaliacoes aluno;

    printf("Arquivo de entrada: ");
    fgets(in, MAX, stdin);
    in[strlen(in) - 1] = '\0';

    arqin = fopen(in, "r");
    if(arqin == NULL)
        return -1;

    printf("Arquivo de saida: ");
    fgets(out, MAX, stdin);
    out[strlen(out) - 1] = '\0';

    arqout = fopen(out, "w");
    if(arqout == NULL) {
        fclose(arqin);
        return -1;
    }
    
    while(fscanf(arqin, "%s %f %f %f\n", aluno.nome, &aluno.p1, &aluno.p2, &aluno.trabalho) == 4) {
        
        float media = (((aluno.p1 + aluno.p2) / 2) * 0.8) + (aluno.trabalho * 0.2);
        
        fprintf(arqout, "%s: %.2f\n", aluno.nome, media);
    }
    

    fclose(arqin);
    fclose(arqout);

    return 0;
}