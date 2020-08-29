#ifndef __studentpc.h__
#define __studentpc.h__

#include <stdio.h>

#define LENGTHOWNER 25
#define LENGTHMODEL 22

typedef struct {
    char owner[LENGTHOWNER];
    char cpuModel[LENGTHMODEL];
    unsigned int cpuCores;
    unsigned int cpuClocks;

    char ramModel[LENGTHMODEL];
    unsigned int ramValue;
    
    char gpuModel[LENGTHMODEL];
    unsigned int gpuValue;

    char storageModel[LENGTHMODEL];
    unsigned int storageValue;
    
    char os[LENGTHMODEL];
    char isCompleted;
} Student_PC;

#endif