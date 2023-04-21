int finder(char a[], char b[]) {
    int i, j;
    for(i = 0; a[i] != '\0'; i++) {
        for(j = 0; b[j] != '\0'; j++) {
            if (a[i] == b[j])
                return i;
        }
    }
    return -1;
}

void input(char a[]) {
    int c, i = 0;
    while((c = getchar()) != '\n') {
        a[i++] = c;
    }
    a[i] = '\0';
}