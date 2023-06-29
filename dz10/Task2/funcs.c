#include "func.h"

// Каждый элемент хэш-таблицы - указатель на первый элемент списка городов
struct City* table[TABLE_SIZE];

// Хэш-функция для названия города
unsigned int hash(char *name) {
    unsigned int h = 0;
    for (int i = 0; name[i]; i++)
        h = (h * 31 + name[i]) % TABLE_SIZE;
    return h;
}

// Функция добавления города в хэш-таблицу
void add(char *name, int population) {
    unsigned int h = hash(name);
    struct City *new_city = malloc(sizeof(struct City));
    strcpy(new_city->name, name);
    new_city->population = population;
    new_city->next = table[h];
    table[h] = new_city;
}

// Функция вывода списка всех городов
void list() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct City *curr = table[i];
        while (curr) {
            printf("%s: %d\n", curr->name, curr->population);
            curr = curr->next;
        }
    }
}

// Функция добавления города через терминал
void add_city() {
char input[100];
fgets(input, sizeof(input), stdin);
char name[50];
int population;
if (sscanf(input, "%s %d", name, &population) != 2) {
    system("cls");
    printf("Ошибка ввода\n");
    return;
}

unsigned int h = hash(name);
struct City *curr = table[h];
while (curr) {
    if (strcmp(curr->name, name) == 0) { 
        system("cls");
        printf("Город %s уже существует\n", name);
        return;
    }
    curr = curr->next;
}

add(name, population);
system("cls");
printf("Город %s добавлен\n", name);

}

// Функция удаления города из хэш-таблицы
void remove_city(char *name) {
    unsigned int h = hash(name);
    struct City *prev = NULL;
    struct City *curr = table[h];
    while (curr) {
        if (strcmp(curr->name, name) == 0) { // если город найден
            if (prev) // если текущий элемент не первый в списке
                prev->next = curr->next;
            else // иначе изменяем указатель на первый элемент списка в таблице
                table[h] = curr->next;
            free(curr); // освобождаем память, занятую элементом списка
            system("cls");
            printf("Город %s удален\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    system("cls");
    printf("Город %s не найден\n", name);
}
