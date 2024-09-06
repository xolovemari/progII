//l linhas com c vasos
//m linhas x n vasos cada lote

#include <stdio.h>
#include <stdlib.h>

int **alocacao(int L, int C) {
    int **plantacao = (int**)malloc(L * sizeof(int*));
    if(!plantacao) {
        printf("Erro ao alocar memoria.");
        return NULL;
    }
    for(int i = 0; i < L; i++) {
        *(plantacao + i) = (int*)malloc(C * sizeof(int));
        if(!(*(plantacao + i))) {
            printf("Erro ao alocar memoria.");
            for(int j = 0; j < i; j++) {
                free(plantacao[j]);
            }
            free(plantacao);
            return NULL;
        }
    }
    return plantacao;
}

int numMaximo(int **plantacao, int M, int N, int L, int C) {
    int count = 0;
    int lotesVert = L / M;
    int lotesHoriz = C / N;

    for(int i = 0; i < lotesVert; i++) {
        for(int j = 0; j < lotesHoriz; j++) {
            int countAtual = 0;
            for(int x = 0; x < M; x++) {
                    for(int y = 0; y < N; y++) {
                        countAtual += plantacao[i * M + x][j * N + y];
                    }
                }
                if(countAtual > count) 
                    count = countAtual;
        }
    }
    return count;
}

int main ( ) {

    int L, C, M, N, **plantacao;
    int i, j;

    printf("Informe o numero de vasos por linhas e colunas respectivamente: ");
    scanf("%d %d", &L, &C);
    if(L < 1 || C < 1) {
        printf("Valor invalido, tente novamente.");
        return -1;
    }

    printf("Informe o tamanho dos lotes por linhas e colunas respectivamente: ");
    scanf("%d %d", &M, &N);
    if(M < 1 || N < 1 || M > L || N > C) {
        printf("Valor invalido, tente novamente.");
        return -1;
    }
    
    plantacao = alocacao(L, C);
    if(!plantacao) 
        return -1;

    for(i = 0; i < L; i++) {
        for(j = 0; j < C; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", *(plantacao + i) + j);
        }
    }
    int max = numMaximo(plantacao, M, N, L, C);

    printf("%d", max);

    for(int i = 0; i < L; i++) {
        free(plantacao[i]);
    }
    free(plantacao);

    return 0;
}