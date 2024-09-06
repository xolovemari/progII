#include <stdio.h>
#include <stdlib.h>
int k = 0;
int main (int argc, char *argv[]) {

    if(argc == 1) //argc == 1 sem argumento, se tiver argc == 2
        return -1;

    k = atoi(argv[1]); //k == 35
    int vetor[] = {10, 20, 30, 40, 50, 60};
    int *p1, *p2, *p3;
    int i = 100, j;
    p1 = &vetor[2]; // *p1 == 30
    p2 = &i; // *p2 == 100
    printf("%d, %d\n",*p1, *p2); // 30, 100
    p3 = malloc(sizeof(int));

    for (j = 3; j > 0; j--) {
        int k;
        if (j % 2 != 0) {
            k = j * 5; //15, 5
            printf("%d, %d\n", j, k); //3, 15 && 1, 5
        }
        *p3 = k; //*p3 == 15 && 5
        *p2 = *p3; //*p2 == 15 && 5
        p1++; //40, 50, 60
    }

    printf("%d, %d, %d\n", *p1, *p2, *p3); //60, 5, 5  
    printf("%d, %d, %d\n", i, j, k); //5, 0, 35
    free(p3);
    return 0;
}