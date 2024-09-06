#include <stdio.h>
#include <stdlib.h>

int main () {
    int *i, j;
    float *notas;
    char *nome;

    //coloque na variável *i o valor 10 de duas formas distintas
    i = (int*)malloc(sizeof(int));
    *i = 10; //primeira forma
    printf("%d", i);
    j = 10;
    i = &j;
    printf("%d", i);

    //carregue na variável ’notas’ 5 valores distintos de notas
    notas = (float*)malloc(5 * sizeof(float));
    printf("Insira 5 notas distintas entre 1 a 10: ");
    for(int k = 0; k < 5; k++) {
        printf("Nota %d: \n", k + 1);
        scanf("%f", &notas[k]);
    }

    printf("Notas armazenadas: ");
    for(int k = 0; k < 5; k++) {
        printf("%.1f", notas[k]);
    }
    printf("\n");

    //carregue na variável ’nome’ o seu primeiro e ultimo nome usando somente minusculas
    nome = (char*)malloc(100 * sizeof(char));
    printf("Insira seu primeiro e ultimo nome com letras minusculas: ");
    fgets(nome, 100, stdin);
    
    
    return 0;
}