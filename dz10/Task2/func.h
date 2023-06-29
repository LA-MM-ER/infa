#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Размер хэш-таблицы (можно выбрать любое другое простое число чтобы избежать кластеризации значений в небольшое количество сегментов)
#define TABLE_SIZE 1009

// Описание структуры города
struct City {
    char name[50];  // Название города
    int population;
    struct City *next; // указатель на следующий элемент списка
};

unsigned int hash(char *name);
void add(char *name, int population);
void list();
void add_city();
void remove_city(char *name);