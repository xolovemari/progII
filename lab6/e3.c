#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main ( ) {
    FILE *arq;
    Taluno aluno;
    float countT = 0, countP = 0;
    float perc;

    arq = fopen("alunos.dat", "rb+");
    if(arq == NULL) {
        return -1;
    }

    while(fread(&aluno, 1, sizeof(Taluno), arq) == 1) {
        countT++;

        printf("Aluno: %s\nNota1: %.2lf - Nota2: %.2lf - Nota3: %.2lf\nMedia: %.2lf", aluno.nome, aluno.nota[0], aluno.nota[1], aluno.nota[2], aluno.media);
        
        float mediaP = (0.25 * aluno.nota[0] + 0.35 * aluno.nota[1] + 0.40 * aluno.nota[2]);
        
        if(aluno.media != mediaP) {
            countP++;
            aluno.media = mediaP;
            fseek(arq, -sizeof(Taluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Taluno), 1, arq);
        }
    }
    perc = (100 * countP) / countT;
    printf("Percentual: %.2f", perc);

    fseek(arq, 0, SEEK_SET);

    printf("\nDados atualizados dos alunos:\n");
    while (fread(&aluno, sizeof(Taluno), 1, arq) == 1) {
        printf("Aluno: %s\nNota1: %.2lf - Nota2: %.2lf - Nota3: %.2lf\nMédia: %.2lf\n\n", 
            aluno.nome, aluno.nota[0], aluno.nota[1], aluno.nota[2], aluno.media);
    }
    fclose(arq);

    return 0; 
}