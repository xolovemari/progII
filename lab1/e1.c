#include <stdio.h>

float alteraSalario(float *salario, float perc) {
    return *salario + (*salario * (perc/100));
}

int main ( ) {

    float salario, perc;

    printf("Insira o salario atual e o percentual de aumento de um funcionario: ");
    scanf("%f %f", &salario, &perc);

    printf("O novo salario eh: %.2f", alteraSalario(&salario, perc));

    return 0;
}