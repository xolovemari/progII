#include <stdio.h>

int max_index(int *v, int N) {
    int indice = 0;

    for(int i = 1; i < N; i++) {
        if(*(v + i) > *(v + indice))
            indice = i;
    }
    return indice;
}

int main ( ) {
    int N;

    printf("Insira um valor inteiro: ");
    scanf("%d", &N);

    int v[N];

    printf("Insira %d valores inteiros: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d", max_index(v, N));

    return 0;
}