#include <stdio.h>
#include <stdlib.h>
#include "studentpc.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Inputed wrong parameters. Must be: programm <bin file> -p/-f \n");
        return 2;
    }
    FILE* input;
    input = fopen(argv[1], "rb");

    Student_PC pc;
    if(strcmp(argv[2], "-f") == 0) {
        printf("--------------------------\n");
        printf("Owner_Name CPU_Model CPU_Cores CPU_Clocks RAM_Model RAM_Value GPU_Model GPU_Value Storage_Model Storage_Value OS Is_Completed?\n");
        while(fread(&pc, sizeof(pc), 1, input)) {
            printf("%-25s %-22s %-2d %-4dMHz %-22s %-6dMiB %-22s %-8dMiB %-22s %-8dMiB %-22s %-1c\n",
            pc.owner,
            pc.cpuModel, pc.cpuCores, pc.cpuClocks,
            pc.ramModel, pc.ramValue,
            pc.gpuModel, pc.gpuValue,
            pc.storageModel, pc.storageValue,
            pc.os, pc.isCompleted
            );
        }
    }
    else if(strcmp(argv[2], "-p") == 0) {
        printf("--------------------------\n");
        printf("Owner_Name CPU_Model CPU_Cores CPU_Clocks RAM_Model RAM_Value GPU_Model GPU_Value Storage_Model Storage_Value OS Is_Completed?\n");
        while(fread(&pc, sizeof(pc), 1, input)) {
            if(pc.isCompleted == 'y') { continue;}
            printf("%-25s %-22s %-2d %-4dMHz %-22s %-6dMiB %-22s %-8dMiB %-22s %-8dMiB %-22s %-1c\n",
            pc.owner,
            pc.cpuModel, pc.cpuCores, pc.cpuClocks,
            pc.ramModel, pc.ramValue,
            pc.gpuModel, pc.gpuValue,
            pc.storageModel, pc.storageValue,
            pc.os, pc.isCompleted
            );
        }
    }
    else {
        printf("Wrong parameters\n");
        return 1;
    }

    return 0;
}