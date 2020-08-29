#ifndef __table_c__
#define __table_c__

#include <stdio.h>
#include <stdlib.h>

#include "types.c"
#include "item.c"

typedef struct {
    unsigned int size;
    // Массив указателей
    Item** items;
    // Массив ключей
    // float* keys;
    // Массив строк
    // char** data;
} Table;

void eraseTable(Table* table) {
    if(table->size != 0) {
        for(int i=0; i<table->size; i++) {
            destroyItem(table->items[i]);
        }
        table->size = 0;
    }
}
void createTable(Table* table, char* filepath) {
    FILE* inputfile;
    inputfile = fopen(filepath, "r");
    int size;

    fscanf(inputfile, "%i", &size);
    table->size = size;
    table->items = malloc(sizeof(Item)*size);

    // Заполняю массив указателей указателями на Item
    for(int i=0; i < size; i++) {
        float128 key;
        char* inputString = NULL;

        fscanf(inputfile, "%Lf", &key);

        // Ниже считываю посимвольно строку до конца строки
            char buffer;
            unsigned long size = 0;

            buffer = fgetc(inputfile);
            if (buffer == EOF) break;
            do {
                buffer = fgetc(inputfile);
                if(buffer == '\n' || buffer == EOF) break;
                size++;
                if (inputString == NULL)
                    inputString = (char *) malloc(sizeof(char));
                else
                    inputString = (char *) realloc(inputString, size * sizeof(char));

                inputString[size - 1] = buffer;
            } while (buffer != '\n' && buffer != EOF);
            inputString = realloc(inputString, sizeof(char)*size);
        // Считал строку
        table->items[i] = makeItem(key, inputString);
    }
    printf("Table has been loaded\n");
    return;
}
void printKeysTable(Table* table) {
    for(int i=0; i < table->size; i++) {
        // Обращаюсь к таблице к i элементу массива типа Item* к его ключу
        printf("%Lf\n", table->items[i]->key);
    }
}
void printDataTable(Table* table) {
    for(int i=0; i < table->size; i++) {
        // Обращаюсь к таблице к i элементу массива типа Item* к его строке
        printf("%s\n", table->items[i]->data);
    }
}

#endif