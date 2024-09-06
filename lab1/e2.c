//versao 1
int numeroVogais(char str[ ]) {
    int count = 0;
    for(int i = 0; i != '\0'; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
    }

    return count;
}

//versao 2
int numeroVogais(char *str) {
    int count = 0;
    while(*str != '\0') {
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
            count++;
        str++;
    }

    return count;
}