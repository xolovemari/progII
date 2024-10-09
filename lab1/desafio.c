#include <stdio.h>
#include <stdlib.h>

int max_index (int N, int *str) {
    int indice = 0;

    for(int i = 1; i < N; i++) {
        if(*(str + i) > *(str + indice))
            indice = i;
    }
    return indice;
}

int main ( ) {

    int N, *str;

    printf("Informe um inteiro: ");
    scanf("%d", &N);

    str = (int *)malloc(N * sizeof(int));

    printf("Informe %d numeros: ", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", (str + i));
    }

    printf("%d", max_index(N, str));

    return 0;
}