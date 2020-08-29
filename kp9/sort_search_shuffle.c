#ifndef __sort_search_shuffle_c__
#define __sort_search_shuffle_c__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "types.c"
#include "item.c"
#include "table.c"

void shuffleTable(Table* table, unsigned long shuffles) {
    time_t t;
    time(&t);
    srand(t + clock());
    unsigned int randnum1, randnum2;
    for(unsigned long i=0; i < shuffles; i++) {
        randnum1 = (unsigned)(rand()*rand())%table->size;
        randnum2 = (unsigned)(rand()*rand())%table->size;
        Item* tmp = table->items[randnum1];
        table->items[randnum1] = table->items[randnum2];
        table->items[randnum2] = tmp;
    }
}
// Сортировка Шелла - улучшенная сортировка вставками
// Сортируем сначала элементы на расстоянии step
// С каждой новой итерацией уменьшаем step в 2 раза
void shellSortTable(Table* table) {
    // Проверка отсортированности Таблицы
    short isSorted = 1, isReverseSorted = 1;
    for(int i=1; i < table->size; i++) {
        if(table->items[i-1] > table->items[i]) {
            isSorted = 0;
            break;
        }
    }
    for(int i=1; i < table->size; i++) {
        if(table->items[i-1] < table->items[i]) {
            isReverseSorted = 0;
            break;
        }
    }

    if(isSorted) return;
    if(isReverseSorted) {
        Item* tmp;
        for(int i=0; i < table->size/2; i++) {
            tmp = table->items[i];
            table->items[i] = table->items[table->size-i-1];
            table->items[table->size-i-1] = tmp;
        }
        return;
    }


    unsigned int step;
    Item* tmp;
    for(step = table->size/2; step > 0; step /= 2) {
        for(int i=step; i < table->size; i++) {
            for(int j=i-step; j>=0 && (table->items[j]->key > table->items[j+step]->key); j -= step) {
                tmp = table->items[j];
                table->items[j] = table->items[j+step];
                table->items[j+step] = tmp;
            }
        }
    }

}
int linearSearch(Table* table, float128 key, float128 accuracy) {
    for(int i=0; i < table->size; i++) {
        if(table->items[i]->key - accuracy <= key && key <= table->items[i]->key + accuracy) {
            return i;
        }
    }
}
int binarySearch(Table* table, float128 key, float128 accuracy) {
    int low = 0;
    int high = table->size-1;
    int mid;
    while(low <= high) {
        mid = (high+low)/2;
        if(key < table->items[mid]->key - accuracy) {
            high = mid-1;
        }
        else if(key > table->items[mid]->key + accuracy) {
            low = mid+1;
        }
        else if(table->items[mid]->key - accuracy <= key && key <= table->items[mid]->key + accuracy) {
            return mid;
        }
    }
    return -1;
}

#endif