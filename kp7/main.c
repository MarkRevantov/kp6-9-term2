#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    Matrix matrix;
    printf("Программа разреженные матрицы. Курсовой проект VII.\n");

    int ans = 0;
    char* filepath = malloc(sizeof(char)*256);
    do {
        printf("\nВыберите дальнейшее действие:\n");
        printf("1. Считать матрицу из текстового файла\n");
        printf("2. Считать матрицу из бинарного файла\n");
        printf("3. Вывести матрицу\n");
        printf("4. Вывести структуру матрицы\n");
        printf("5. Сохранить матрицу в бинарный файл\n");
        printf("6. Выволнить задание 7 над матрицей, т.е найти строки с наибольшим числом элементов\n");
        printf("0. Выйти из программы\n");
        printf("Ваш выбор: ");
        scanf("%d", &ans);

        switch (ans) {
        case 1:
            printf("Введите путь к файлу: ");
            scanf("%s", filepath);
            inputMatrix(&matrix, filepath);
            printf("Считал!");
            break;
        case 2:
            printf("Введите путь к файлу: ");
            scanf("%s", filepath);
            loadMatrix(&matrix, filepath);
            printf("Считал!");
            break;
        case 3:
            mathPrintMatrix(&matrix);
            break;
        case 4:
            printMatrix(&matrix);
            break;
        case 5:
            printf("Введите путь к файлу: ");
            scanf("%s", filepath);
            saveMatrix(&matrix, filepath);
            printf("Сохранил!");
            break;
        case 6:
            task7(&matrix);
            break;
        case 0:
            break;
        default:
            printf("Ошибочный ввод\n");
            break;
        }
    } while(ans);
    free(filepath);
    return 0;
}