#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int idade;
} Tpessoa;

int grava(FILE *pFile, int N) {
    Tpessoa p;

    for(int i = 0; i < N; i++) {
        scanf("%29s", p.nome);
        scanf("%d", &p.idade);
        if(fwrite(&p, sizeof(Tpessoa), 1, pFile) != 1)
            return -1;
    }
    
    return N;
}

int modifica(FILE *pFile, int M, int idade) {
    Tpessoa p;

    fseek(pFile, 0, SEEK_END);
    int tamanhoArq = ftell(pFile);
    int numRegistros = tamanhoArq / sizeof(Tpessoa);
    if(M < 1 || M > numRegistros) 
        return -1;
    
    fseek(pFile, (M - 1) * sizeof(Tpessoa), SEEK_SET);
    if(fread(&p, sizeof(Tpessoa), 1, pFile) != 1)
        return 0;

    p.idade = idade;

    fseek(pFile, (M - 1) * sizeof(Tpessoa), SEEK_SET);
    if(fwrite(&p, sizeof(Tpessoa), 1, pFile) != 1)
        return 0;

    return M;
}

void exibe(FILE *pFile) {
    Tpessoa p;

    fseek(pFile, 0, SEEK_SET);
    
    while (fread(&p, sizeof(Tpessoa), 1, pFile) == 1) {
        printf("%s - %d anos\n", p.nome, p.idade);
    }
}

int main ( ) {

    FILE *pFile;
    int N, M, mod, idade;

    char nome_arquivo[101];
    fgets(nome_arquivo, 100, stdin); //nome do arquivo a ser criado
    nome_arquivo[strlen(nome_arquivo)-1] = '\0';
    scanf("%d", &N); //numero de pessoas desejado
    pFile = fopen (nome_arquivo , "wb+");

    if (!pFile) { 
        printf("Erro na criacao do arquivo...");
        return -1;
    }

    if (grava(pFile, N) != N) {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }

    scanf("%d", &M); 
    scanf("%d", &idade);
    mod = modifica(pFile, M, idade);

    if(mod == -1) {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }
    if(mod == 0) {
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }

    exibe(pFile);
    fclose (pFile);

    return 0;
}