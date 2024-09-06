#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora;
    int min;
    int total;
} horario;

int diferencaHora (int minPassados, horario *dia) {
    dia->total = (dia->hora * 60) + dia->min;

    int diferenca = dia->total - minPassados;

    return diferenca;
}

int main (int argc, char *argv[]) {

    if(argc == 1) return -1;

    int minPassados, testes, d1, d2;
    horario atual, t1, t2;

    testes = atoi(argv[1]);

    for(int i = 0; i < testes; i++) {
        printf("Informe o primeiro momento em hora e minuto separadamente: ");
        scanf("%d %d", &t1.hora, &t1.min);

        printf("Informe o segundo momento em hora e minuto separadamente: ");
        scanf("%d %d", &t2.hora, &t2.min);

        printf("Informe quantos minutos se passaram desde o inicio do dia: ");
        scanf("%d", &minPassados);

        d1 = diferencaHora(minPassados, &t1);
        d2 = diferencaHora(minPassados, &t2);

        if(d1 > d2)
            printf("%dh%dmin", t2.hora, t2.min);
        else if(d2 > d1)
            printf("%dh%dmin", t1.hora, t1.min);
        else
            printf("%dh%dmin", t1.hora, t1.min);
    }

    

    return 0;
}