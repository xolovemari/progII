#include <stdio.h>
#include <stdlib.h>

int **aloca_linhas(int lin) {
    return (int**)malloc(lin * sizeof(int*));
}

void aloca_colunas (int **matriz, int lin, int      col) {
    for(int i = 0; i < lin; i++) {
        *(matriz + i) = (int *)malloc(col * sizeof(int));
        if(!(*(matriz + i)))
            return;
        
    }

}

void le_dados(int **matriz, int lin, int col) {
    printf("Informe os elementos da matriz.");
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", *(matriz + i) + j);
        }
    }
}

void imprime_matriz(int **matriz, int lin, int col) {
        for(int i = 0; i < lin; i++)
            for(int j = 0; j < col; j++) 
                printf("Matriz[%d][%d]: [%d] ", i, j, *(*(matriz + i) + j));
}

void troca_linhas (int **matriz, int linha1, int linha2) {
    int *aux;

    aux = *(matriz + linha1);
    *(matriz + linha1) = *(matriz + linha2);
    *(matriz + linha2) = aux;
}

int main (void) {
    int **matriz;
    int lin, col;
    int linha1, linha2;

    puts("Qual o numero de linhas?");
    scanf("%d",&lin);
    matriz = aloca_linhas(lin);

    puts("Qual o numero de colunas?");
    scanf("%d",&col);
    printf("Alocando espaço para linhas.\n");
    aloca_colunas(matriz, lin, col);

    le_dados(matriz, lin, col);
    imprime_matriz(matriz, lin, col);

    puts("Qual a primeira linha a ser trocada?");
    scanf("%d",&linha1);
    puts("Qual a segunda linha a ser trocada?");
    scanf("%d",&linha2);
    troca_linhas(matriz, linha1, linha2);

    imprime_matriz(matriz, lin, col);

    return 0;
}