#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
static double stack[STACK_SIZE];
static int top = -1; //по сути это каретка для стека
void push(double n) { //пушит в стек значение n
    if (top + 1 < STACK_SIZE) {
        stack[++top] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}
double pop() { //возвращает верхний элемент стека
    if (top != -1) {
        return stack[top--];
    } else {
        printf("error: stack is empty\n");
        exit(222);
    }
}