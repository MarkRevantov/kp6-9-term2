#include <stdio.h>
#include <stdlib.h>
#include "studentpc.h"

int main(int argc , char* argv[]) {
    if(argc!=3) {
        printf("Введите ещё два аргумента в формате:\n./input <Входной текстовый файл> <Выходной бинарный файл>\n");
        return 2;
    }
    Student_PC pc;
    FILE *output;
    FILE *input;
    input  = fopen(argv[1],"r");
    output = fopen(argv[2],"wb");
    while(fscanf(input,"%s %s %d %d %s %d %s %d %s %d %s %c\n",
            pc.owner,
            pc.cpuModel, &pc.cpuCores, &pc.cpuClocks,
            pc.ramModel, &pc.ramValue,
            pc.gpuModel, &pc.gpuValue,
            pc.storageModel, &pc.storageValue,
            pc.os, &pc.isCompleted
            )!=EOF) {
        fwrite(&pc,sizeof(pc),1,output);
    }
    fclose(input);
    fclose(output);
    return 0;
}