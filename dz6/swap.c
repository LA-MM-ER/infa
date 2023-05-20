#include <stdio.h>

#define swap(a, b , type) type c = a; a = b; b = c;
int main() {
    int a, b;
    printf("enter a & b: ");
    scanf("%d%d",&a, &b);
    printf("old a = %d\t old b = %d\n",a,b);
    swap(a, b, int);
    printf("new a = %d\t new b = %d",a,b);
}
