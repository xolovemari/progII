#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 81

int main (int argc, char *argv[ ]) {
    if(argc != 3)
        return 1;

    FILE *arq;
    char linha[MAX];
    int count = 0;

    arq = fopen(argv[2], "r");
    if(arq == NULL)
        return -1;
    
    while(fgets(linha, MAX, arq) != NULL) {
        count++;

        if(strstr(linha, argv[1]) != NULL) {
            printf("%d %s", count, linha);
        }
    }

    fclose(arq);

    return 0;
}