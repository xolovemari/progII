#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena (char *s1, char *s2) {
    int N = strlen(s1) + strlen(s2) + 1;
    char *s3 = (char *)malloc(N * sizeof(char));

    if(!s3) {
        printf("Erro ao alocar memoria.");
        return NULL;
    }

    int i = 0, j = 0;
    while(*(s1 + i) != '\0') {
        *(s3 + i) = *(s1 + i);
        i++;
    }

    while(*(s2 + j) != '\0') {
        *(s3 + (i + j)) = *(s2 + j);
        j++;
    }
    *(s3 + (i + j)) = '\0';

    return s3;
}

int main() {
    char str1[] = "Ola, ";
    char str2[] = "mundo!";

    char *resultado = concatena(str1, str2);

    if (resultado != NULL) {
        printf("String concatenada: %s\n", resultado);
        free(resultado);
    }

    return 0;
}