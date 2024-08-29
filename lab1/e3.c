void pares(int *v, int *n) {
    int i = 0, count = 0;
    while(i < *n) {
        if(v[i] % 2 == 0) 
            count++;
        i++;
    }
    *n = count;
}