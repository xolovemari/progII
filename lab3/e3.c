#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func {
    char nome[40];
    int ano_nasc;
    float renda; 
} Tfunc ;

Tfunc *inicializa (Tfunc *cadastro, int funcionarios) {
    cadastro = (Tfunc*)malloc(funcionarios * sizeof(Tfunc));
    if(!cadastro)
        return NULL;
    
    for(int i = 0; i < funcionarios; i++) {
        printf("- Funcionario %d -\n", i + 1);
        printf("Nome: ");
        scanf("%s", (cadastro + i)->nome);
        printf("Ano de nascimento: ");
        scanf("%d", &(cadastro + i)->ano_nasc);
        printf("Renda: ");
        scanf("%f", &(cadastro + i)->renda);
    }

    return cadastro;
}

Tfunc *inclui_novos (Tfunc *cadastro, int funcionarios, int adicionais) {
    int total = funcionarios + adicionais;
    Tfunc *Ncadastro = realloc(cadastro, total * sizeof(Tfunc));
    if(!Ncadastro)
        return cadastro;
    
    for(int i = funcionarios; i < total; i++) {
        printf("- Funcionario %d -\n", i + 1);
        printf("Nome: ");
        scanf("%s", (Ncadastro + i)->nome);
        printf("Ano de nascimento: ");
        scanf("%d", &(Ncadastro + i)->ano_nasc);
        printf("Renda: ");
        scanf("%f", &(Ncadastro + i)->renda);
    }

    return Ncadastro;
}

void imprime (Tfunc *cadastro, int inicio, int fim) {
    for(int i = inicio; i < fim; i++) {
        printf("- Funcionario %d -\n", i + 1);
        printf("Nome: %s\n", (cadastro + i)->nome);
        printf("Ano de nascimento: %d\n", (cadastro + i)->ano_nasc);
        printf("Renda: %.2f\n", (cadastro + i)->renda);
    }
}

int main ( ) {
    Tfunc *cadastro;
    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    scanf("%d", &funcionarios);
    cadastro = inicializa(cadastro, funcionarios);
    if (!cadastro)
        return -1;

    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d",&adicionais);
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro)
        return -1;

    printf("Lista de funcionarios cadastrados\n");
    imprime(cadastro, 0, funcionarios+adicionais);
    free(cadastro);

    return 0;
}