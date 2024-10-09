#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main ( ) {
    FILE *arq;
    Taluno aluno;

    arq = fopen("alunos.dat", "wb");
    if(arq == NULL)
        return -1;

    while(1) {
        printf("Informe o primeiro nome do aluno (ou pressione Enter para encerrar): ");
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
        aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; 
        if (strlen(aluno.nome) == 0) {
            break;
        }
        
        printf("Informe as três notas (P1, P2 e P3): ");
        scanf("%lf %lf %lf", &aluno.nota[0], &aluno.nota[1], &aluno.nota[2]);
        
        aluno.media = (aluno.nota[0] + aluno.nota[1] + aluno.nota[2]) / 3;
        
        fwrite(&aluno, sizeof(Taluno), 1, arq);

        getchar();
    }

    fclose(arq);

    return 0;
}