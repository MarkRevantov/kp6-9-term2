#include <stdio.h>
#include <stdlib.h>
#include "list.c"

int main() {
    List list;
    createList(&list);

    short action;
    int index;
    T value;
    
    printf("1 value - Push Back\n");
    printf("2 value - Push Front\n");
    printf("3 - Pop Back\n");
    printf("4 - Pop Front\n");
    printf("5 index value - Push Index\n");
    printf("6 index - Pop Index\n");
    printf("7 - Erase List\n");
    printf("8 size value - Push Until List is Full\n");
    printf("9 - print List\n");
    printf("10 - print Size\n");
    printf("0 - Exit programm\n\n");
    printf("Action: ");


    while((scanf("%d", &action) != EOF) && action) {
        switch (action) {
        case 1:
            scanf("%ld", &value);
            pushBack(&list, value);
            break;
        case 2:
            scanf("%ld", &value);
            pushFront(&list, value);
            break;
        case 3:
            printf("Poped: %ld\n", popBack(&list));
            break;
        case 4:
            printf("Poped: %ld\n", popFront(&list));
            break;
        case 5:
            scanf("%d", &index);
            scanf("%ld", &value);
            pushIndex(&list, index, value);
            break;
        case 6:
            scanf("%d", &index);
            printf("Poped: %ld\n", popIndex(&list, index));
            break;
        case 7:
            eraseList(&list);
            printf("Erased!\n");
            break;
        case 8:
            // index === size
            scanf("%d", &index);
            scanf("%ld", &value);
            pushUtilListFull(&list, index, value);
            break;
        case 9:
            printList(&list);
            break;
        case 10:
            printf("Size of list: %d\n", list.size);
            break;
        case 0:
            break;
        
        default:
        printf("Getted: %d\nIt is strange..\n", action);
            break;
        }
        printf("Action: ");
    }


    return 0;
}
