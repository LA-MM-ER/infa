#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int right) { // Функция слияния, передаем массив и границы
    int *mas = (int*) malloc((right - left + 1) * sizeof(int)); // Буфер для хранения массива, получившегося в результате слияния

    int l_iter, r_iter, middle; // Создаём переменные для итераторов левого и правого, а также для середины
    middle = (left + right) / 2;
    l_iter = left;
    r_iter = middle + 1;

    for (int i = left; i <= right; i++) { //Движемся по несорт массиву
        // если левый итератор не перешел середину && (правый итератор зашёл за конец || значение элемента массива на месте левого итератора меньше чем на месте правого)
        if ((l_iter <= middle) && ((r_iter > right) || (arr[l_iter] < arr[r_iter]))) {
            mas[i - left] = arr[l_iter]; // то записываем элемент, стоящий на месте левого итератора
            l_iter++;
        } else {
            mas[i - left] = arr[r_iter]; // иначе на месте правого
            r_iter++;
        }
    }

    for (int i = left; i <= right; i++) // Перезаписываем собранный массив на его место в исходном
        arr[i] = mas[i-left];

    free(mas);
}

void merge_sort(int *arr, int left, int right) { // Сортировка слиянием основная функция
    if (left >= right) 
        return; // Если индекс начала больше конца, выходим
    // Рекурсивно вызываем сортировку, но уже с новой границей (средний элемент и справа от среднего)
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, right);
}

int main() {
    int mas[] = {2,3,6,9,8,7,4,5,1};
    int size = sizeof(mas)/sizeof(mas[0]);
    merge_sort(mas, 0, size);
    for(int i = 0; i<size; i++)
        printf("%d ", mas[i]);
}