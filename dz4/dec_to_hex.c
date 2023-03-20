#include <stdio.h>
#include "dec_to_hex.h"

int main() {
int i, c, task1, task2;
char mas[50];

for (i = 0; (c = getchar()) != '\n'; i++)
    mas[i] = c;
mas[i] = '\0';

task1 = hex_to_dec(mas);
printf("Task 1: %d\n", task1);

task2 = odd_bit_ctr(task1);
printf("Task 2: %d\n", task2);
}
