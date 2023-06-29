#include "func.h"

int main() {
    system("chcp 65001");
    int cmd;
    char name[50];
    do {
        puts("Меню программы:\n1. Список городов\n2. Добавить город(Пример: 2 Gus'-Khrustalnyi 150000)\n3. Удалить город\n4. Выход");
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                system("cls");
                list();
                break;
            case 2:
                add_city();
                break;
            case 3:
                puts("Введите название города для удаления: ");
                scanf("%s", name);
                remove_city(name);
                break;
            case 4:
                system("cls");
                puts("Выход");
                break;
            default:
                system("cls");
                puts("Некорректный ввод, попробуйте ещё раз");
        }
    } while (cmd != 4);

    return 0;
}
