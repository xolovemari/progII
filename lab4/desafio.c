#include <stdio.h>
#include <string.h>
#define MAX 200

void inverteLinha(char *linhas) {
    int inicio = 0;
    int fim = strlen(linhas) - 1;

    if (linhas[fim] == '\n') { //tira o paragrafo se tiver para nao atrapalhar
        fim--;
    }

    while(inicio < fim) {
        char aux = linhas[inicio];
        linhas[inicio] = linhas[fim];
        linhas[fim] = aux;
        inicio++;
        fim--;
    }
}

int main (int argc, char *argv[ ]) {

    //Defesa da entrada de argumentos pela linha de comando
    if(argc != 3) {
        printf("Uso: %s arquivo.txt \"padrão\"\n", argv[0]);
        return 1;
    }

    //Dicionario de dados
    FILE *arq, *out;
    char linhas[MAX];

    //Abertura do arquivo 
    arq = fopen(argv[1], "r");
    if(arq == NULL) { //defesa
        printf("Erro ao abrir arquivo de entrada.");
        return -1;
    }

    out = fopen(argv[2], "w");
    if(out == NULL) { //defesa
        printf("Erro ao abrir arquivo de saida.");
        return -1;
    }

    while(!feof(arq)){
        fgets(linhas, MAX, arq);
        inverteLinha(linhas);
        fprintf(out, "%s", linhas);
    }

    fclose(arq);
    fclose(out);
    return 0;
}