#include <stdio.h>

void quicksort(int arr[], int left, int right); 
void swap(int *a, int *b);

int main()
{
    int array[] = {5, 3, 9, 7, 1, 8, 6, 4, 2, 0}; // исходный массив для сортировки
    int n = sizeof(array)/sizeof(array[0]); //число элементов массива

    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    quicksort(array, 0, n - 1); 
    printf("\nAfter sorting:  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]); 
    }

    return 0;
}

void quicksort(int arr[], int left, int right)
{
    int stack[right], top = -1; // инициализация массива границ
    stack[++top] = left; // добавление левой границы в стек
    stack[++top] = right; // добавление правой границы в стек

    while (top >= 0) // пока стек не пустой
    {
        right = stack[top--]; // извлечение из стека правой границы
        left = stack[top--]; // извлечение из стека левой границы

        int pivot = arr[(left + right) / 2]; // выбор опорного элемента (середина)
        //printf("\ncurrent_test_pivot:  %d", pivot);
        int i = left, j = right;

        while (i <= j) //пока каретки не достигли опорного элемента
        {
            while (arr[i] < pivot) //сравнение с опор эл
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) 
            {
                swap(&arr[i], &arr[j]);
                i++; //свапнутые элементы уже можно не проверять
                j--;
            }
        }

        //printf("\nleft = %d, right = %d\ni = %d, j = %d", left, right, i, j);

        if (left < j) // Добавление границ левой и правой частей в стек, чтобы отсортировать их позднее
        {
            //printf("\ntest gran j:  %d", j);
            stack[++top] = left;
            stack[++top] = j; // если нужно отсортировать левую часть, добавляем ее границы в стек
        }

        if (i < right)
        {
            //printf("\ntest gran i:  %d", i);
            stack[++top] = i;
            stack[++top] = right; // если нужно отсортировать правую часть, добавляем ее границы в стек
        }

        /*printf("\nend testing mas:  ");
            for (int i = 0; i < 10; i++)
            {
                printf("%d ", arr[i]); 
            }*/
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}