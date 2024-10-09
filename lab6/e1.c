#include <stdio.h>
#include <stdlib.h>

int grava (FILE *pFile, int N) {
    if (fwrite(&i, sizeof(int), 1, pFile) != 1) {
            return -1;  // Erro ao gravar no arquivo
    }

    return N;
}

int *recupera (FILE *pFile) {
    fseek(pFile, 0, SEEK_END);
    int tamanho = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);

    int N = tamanho / sizeof(int);

    int *vetor = (int*)malloc(tamanho);
    if(vetor == NULL)
        return NULL;
    
    if (fread(vetor, sizeof(int), N, pFile) != N) {
        free(vetor);  // Libera a memória se ocorrer erro na leitura
        return NULL;
    }

    return vetor;
}

void exibe_vetor (int *vetor, int N) {
    for(int i = 0; i < N; i++) 
        printf("%d ", vetor[i]);
    printf("\n");
}

int modifica (FILE *pFile, int M) {
    fseek(pFile, 0, SEEK_END);
    int N = ftell(pFile) / sizeof(int);
    
    if(M <= 0 || M > N)
        return -1;

    fseek(pFile, -M * sizeof(int), SEEK_END);
    for(int i = 0; i < M; i++) {
        int num;
        if (fread(&num, sizeof(int), 1, pFile) != 1) {
            return -1;  // Erro ao ler o arquivo
        }
        if(num % 2 == 0) {
            num *= 2;
            fseek(pFile, -sizeof(int), SEEK_CUR);
             if (fwrite(&num, sizeof(int), 1, pFile) != 1) {
                return -1;  // Erro ao escrever no arquivo
            }
        }
    }
    return M;
}

void recupera_exibe(FILE *pFile) {
    fseek(pFile, 0, SEEK_END);
    int N = ftell(pFile) / sizeof(int);
    fseek(pFile, 0, SEEK_SET);

    for(int i = 0; i < N; i++) {
        int num;
        fread(&num, sizeof(int), 1, pFile);
        printf("%d ", num);
    }
    printf("\n");
}

int main ( ) {
    FILE *pFile;
    int i, N, M, num, mod, *vetor;
    char nome_arquivo[100];

    printf("Informe o nome do arquivo a ser criado: ");
    gets(nome_arquivo);

    printf("Informe um numero positivo: ");
    scanf("%d", &N);

    pFile = fopen (nome_arquivo, "wb+");
    if (!pFile) { 
        printf("Erro na criacao do arquivo...");
        return -1;
    }

    if (grava(pFile, N) != N) {
        printf("Erro na gravacao do arquivo...");
        return -1;
    }

    vetor = recupera(pFile);

    if(vetor == NULL) {
        printf("Erro na recuperacao de dados do arquivo...");
        return -1;
    }

    exibe_vetor(vetor, N);

    printf("Informe um numero positivo M correspondente a quantidade de valores a partir do final do arquivo que deseja alterar: "); 
    scanf("%d", &M);

    mod = modifica(pFile, M);

    if(mod == -1) {
        printf("Valor de M fora do intervalo permitido...");
        return -1;
    }

    if(mod != M) { 
        printf("Erro de leitura e/ou gravacao no arquivo...");
        return -1;
    }

    recupera_exibe(pFile);
    fclose(pFile);

    return 0;
}