#include <stdio.h>
#define MAX 10

void countsort(int* mas, int n, int max) {
    int outp[n], k = 0;
    int ctr_mas[max+1]; //тк от 0 до max
    for(int i = 0; i<max+1; i++)
        ctr_mas[i] = 0; //массив подсчета встреч элементов
    for (int i = 0; i < n; i++) 
        ctr_mas[mas[i]]++; //заполнили

    for(int i = 0; i<max+1; i++) {
        if(ctr_mas[i] != 0) {
            for(int j = 0; j<ctr_mas[i]; j++)
                outp[k++] = i;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", outp[i]);
}
 
int main()
{
    int arr[] = { 4, 2, 10, 10, 1, 4, 2, 1, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    countsort(arr, n, MAX);
    return 0;
}