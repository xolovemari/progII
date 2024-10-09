#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 101

int main (int argc, char *argv[ ]) {
    
    if(argc != 3)
        return 1;
    
    char in[MAX];
    FILE *arqin, *arqout;

    arqin = fopen(argv[1], "r");
    if(arqin == NULL)
        return -1;

    arqout = fopen(argv[2], "w");
    if(arqout == NULL)
        return -1;

    while(fgets(in, MAX, arqin) != NULL) {
        for(int i = 0; in[i] != '\0'; i++) {
            in[i] = toupper(in[i]);
        }
        fputs(in, arqout);
    }

    fclose(arqin);
    fclose(arqout);

    return 0;
}
