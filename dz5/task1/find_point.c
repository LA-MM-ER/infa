#include <stdio.h>
#include "find_point.h"

int main() {
    char s1[100], s2[100];
    input(s1);
    input(s2);
    printf("%d", finder(s1, s2));
}

