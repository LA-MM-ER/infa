#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100

int main() {
    int type, lens, num = 0;
    double op2; //для записи врем знач
    char s[MAXOP];
    lens = getline(s);
    for(int i = 0; i < lens; i++) {    
        switch (s[i]) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': //isdigit
                num += s[i]-'0';
                while (isdigit(s[++i])) 
                    num = num * 10 + s[i]-'0';
                push (num);
                num = 0; //занулили
                break;
            case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-': 
                op2 = pop(); //нужно тк мы из нижнего элемента в стеке будем вычитать верхний
                push (pop() - op2);
                break;
            case '^':
                op2 = pop();
                push (pow(pop(), op2));
                break;
            case '%' :
                op2 = pop();
                if (op2 != 0.0)
                    push (floor(pop() / op2));
                else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case 's' :
                push (sin(pop()));
                break;
            case 'c' :
                push (cos(pop()));
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            case ' ':
                break;
            default:
                printf("error: unknown command %s\n", s);
                return -1;
        }
    }
    return 0;
}