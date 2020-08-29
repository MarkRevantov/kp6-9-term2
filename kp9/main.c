#include <stdio.h>
#include <stdlib.h>

#include "types.c"
#include "item.c"
#include "table.c"
#include "sort_search_shuffle.c"

int main() {
    printf("1 filepath - Create table from file <filepath>\n");
    printf("2 - print Keys\n");
    printf("3 - print Data\n");
    printf("4 - print size\n");
    printf("5 - erase Table\n");
    printf("6 shuffles - Shuffle <shuffles> times\n");
    printf("7 - Shell sort Table\n");
    printf("8 key accuracy - Binary Search(only for sorted Table)\n");
    printf("9 key accuracy - Linear Search\n");
    printf("0 - Exit programm\n\n");
    printf("Action: ");

    short action;
    char filepath[255];
    Table table;
    do {
        // Я не понимаю как, но scanf заменяет size на 0 (??!!)
        int size = table.size;
        scanf("%d", &action);
        if(table.size == 0) table.size = size;
        // Конец какой-то магии
        // Теперь локальная переменная size берет на себя удар.
        // Я долго разбирался с этим багом. Я вставил костыль, но остался в недоумении
        if(action == 0) break;
        unsigned int shuffles;
        int index;
        float128 key, accuracy;
        switch (action) {

        case 1:
            scanf("%s", filepath);;
            createTable(&table, filepath);
            break;
        case 2:
            printKeysTable(&table);
            break;
        case 3:
            printDataTable(&table);
            break;
        case 4:
            printf("Size %i\n", table.size);
            break;
        case 5:
            printf("Erase table\n");
            eraseTable(&table);
            break;
        case 6:
            scanf("%u", &shuffles);
            shuffleTable(&table, shuffles);
            break;
        case 7:
            shellSortTable(&table);
            break;
        case 8:
            scanf("%Lf", &key);
            scanf("%Lf", &accuracy);
            index = binarySearch(&table, key, accuracy);
            if(index != -1)
                printf("Key %LF in Index: %i\n", table.items[index]->key, index);
            else
                printf("Item haven't found\n");
            break;
        case 9:
            scanf("%Lf", &key);
            scanf("%Lf", &accuracy);
            index = linearSearch(&table, key, accuracy);
            if(index != -1)
                printf("Key %LF in Index: %i\n", table.items[index]->key, index);
            else
                printf("Item haven't found\n");
            break;
        case 0:
            break;
        default:
            printf("Getted: %d\nIt is strange..\n", action);
            break;
        }
        printf("Action: ");
    } while(1);
    return 0;
}
