#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100

int getline(char s[]) {
    int c, i;
    for(i = 0; i < MAXOP-2 && (c = getchar()) != '\n'; i++) { //сделали запас под \n и \0
        s[i] = c;
    }
    s[i] = '\n';
    s[++i] = '\0';
    return i;
}