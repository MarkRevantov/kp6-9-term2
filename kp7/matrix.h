#ifndef __matrix_H__
#define __matrix_H__

#include <stdio.h>
#include <stdlib.h>

typedef long T;
typedef struct {
    int rows;
    int colums;
    int nozeros;
    int* index_colums;
    int* indexation_rows;
    T* data;
} Matrix;

long char_to_number(char buffer) {
    return buffer - '0';
}
long str_to_number(char* str, int size) {
    long result = 0;
    for(int i=0; i < size; i++) {
        result *= 10;
        result += char_to_number(str[i]);
    }

    return result;
}
void inputMatrix(Matrix* matrix, char* filepath) {
    FILE* inputfile;
    inputfile = fopen(filepath, "r");

    int rows;
    int colums;
    int nozeros;
    fscanf(inputfile, "%d %d %d\n", &rows, &colums, &nozeros);
    matrix->colums = colums;
    matrix->rows = rows;
    matrix->nozeros = nozeros;
    matrix->index_colums = malloc(sizeof(int)*nozeros);
    matrix->indexation_rows = malloc(sizeof(int)*rows);
    matrix->data = malloc(sizeof(T)*nozeros);
    
    matrix->indexation_rows[0] = 0;
    int nums = 0;
    for(int j=0; j < rows; j++) {
        for(int i=0; i < colums; i++) {
            T num;
            fscanf(inputfile, "%ld", &num);
            if(num != 0) {
                matrix->index_colums[nums] = i;
                matrix->data[nums] = num;
                nums++;
            }
        }
        matrix->indexation_rows[j+1] = nums;
    }
    return;
}
void printMatrix(Matrix* matrix) {
    printf("Rows: %d\tColums: %d\tNozeros:%d\n", matrix->rows, matrix->colums, matrix->nozeros);
    for(int i=0; i <= matrix->rows; i++) {
        printf("%d ", matrix->indexation_rows[i]);
    }
    printf("\n");
    for(int i=0; i < matrix->nozeros; i++) {
        printf("%d ", matrix->index_colums[i]);
    }
    printf("\n");
    for(int i=0; i < matrix->nozeros; i++) {
        printf("%ld ", matrix->data[i]);
    }
    printf("\n");
}
void mathPrintMatrix(Matrix* matrix) {
    int iter = 0;
    printf("%d %d %d\n", matrix->rows, matrix->colums, matrix->nozeros);
    for(int row=0; row < matrix->rows; row++) {
        for(int colum=0; colum < matrix->colums; colum++) {
            if(matrix->indexation_rows[row] <= iter && iter < matrix->indexation_rows[row+1]
            && colum == matrix->index_colums[iter]) {
                printf("%ld ", matrix->data[iter]);
                iter++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return;
}
void saveMatrix(Matrix* matrix, char* filepath) {
    FILE* outfile;
    outfile = fopen(filepath, "wb");

    fwrite(&matrix,sizeof(matrix),1,outfile);
    return;
}
void loadMatrix(Matrix* matrix, char* filepath) {
    FILE* inputfile;
    inputfile = fopen(filepath, "rb");

    fread(&matrix, sizeof(matrix), 1, inputfile);
    return;
}
// Найти строку, содержащую наибольше число элементов.
// Напечатать номер стркои и количество элементов.
// Если таких строк несколько - обработать все
void task7(Matrix* matrix) {
    int maxelems = 0;
    int elemsInRow = 0;
    for(int i=0; i < matrix->rows; i++) {
        elemsInRow = matrix->indexation_rows[i+1] - matrix->indexation_rows[i];
        if(maxelems < elemsInRow) maxelems = elemsInRow;
    }
    printf("Наибольшее число элементов в строке: %d\n", maxelems);
    printf("Строки с наибольшим числом элементов: ");
    for(int i=0; i < matrix->rows; i++) {
        elemsInRow = matrix->indexation_rows[i+1] - matrix->indexation_rows[i];
        if(elemsInRow == maxelems) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return;
}

#endif