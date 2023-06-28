#include "func.h"

int main(int argc, char* argv[]) {
    // Проверка наличия имени файла в аргументах командной строки
    if (argc < 2) {
        printf("HOW TO USE: %s <file_name> [-o ASC|DESC]\n", argv[0]);
        return 1;
    }
    
    // Открытие файла для чтения
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    
    // Чтение слов из файла и добавление их в бинарное дерево
    Node* root = NULL;
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        root = insert(root, word);
    }
    
    // Закрытие файла
    fclose(file);
    
    // Проверка наличия аргумента сортировки
    int reverse = 0; // флаг для сортировки в порядке убывания
    if (argc >= 3 && strcmp(argv[2], "-o") == 0) {
        if (argc == 4 && strcmp(argv[3], "DESC") == 0) {
            reverse = 1;
        }
    }
    //printf("\nARGV 2 = %s\n", argv[2]);
    //printf("\nREVERSE = %d\n", reverse);
    // Вывод отсортированного списка слов и их частоты повторения
    if (reverse) {
        printOutOrder(root);
    } else {
        printInOrder(root);
    }
    
    // Освобождение памяти, занятой бинарным деревом
    freeTree(root);
    
    return 0;
}