#include <stdio.h>
#include <stdlib.h>
typedef long T;
typedef struct Node {
    T value;
    struct Node* prev;
    struct Node* next;
} Node;
typedef struct {
    int size;
    Node* first;
    Node* last;
} List;

Node* makeNode(T value) {
    Node* node = malloc(sizeof(Node));
    node->value = value;
}
void destroyNode(Node* node) {
    free(node);
}
void printNode(Node* node) {
    printf("%li ", node->value);
}
void createList(List* list) {
    list->size=0;
    list->first = NULL;
    list->last = NULL;
}
void printList(List* list) {
    Node* current = list->first;
    for(int i=0; i<list->size; i++) {

        printNode(current);
        current = current->next;
    }
    printf("\n");
}
void pushBack(List* list, T value) {
    Node* newNode = makeNode(value);
    if(list->size >= 1) {
        newNode->prev = list->last;
        newNode->next = list->first;
        list->last->next = newNode;
        list->first->prev = newNode;
        list->last = newNode;
    }
    else {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->first = newNode;
        list->last = newNode;
    }
    list->size++;
}
void pushFront(List* list, T value) {
    Node* newNode = makeNode(value);
    if(list->size >= 1) {
        newNode->prev = list->last;
        newNode->next = list->first;
        list->last->next = newNode;
        list->first->prev = newNode;
        list->first = newNode;
    }
    else {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->first = newNode;
        list->last = newNode;
    }
    list->size++;
}
T popFront(List* list) {
    if(list->size >= 1) {
        T value = list->first->value;
        Node* oldfirst = list->first;
        list->first = list->first->next;
        list->first->prev = list->last;
        list->last->next = list->first;
        
        list->size--;
        destroyNode(oldfirst);
        return value;
    }
    else if(list->size == 1) {
        T value = list->last->value;
        Node* oldfirst = list->first;

        list->first = NULL;
        list->last = NULL;

        list->size--;
        destroyNode(oldfirst);
        return value;
    }
    else {
        printf("There is no Elements. Returned 0");
        return 0;
    }
}
T popBack(List* list) {
    if(list->size >= 2) {
        T value = list->last->value;
        Node* oldlast = list->last;
        list->last = list->last->prev;
        list->last->next = list->first;
        list->first->prev = list->first;

        list->size--;
        destroyNode(oldlast);
        return value;
    }
    else if(list->size == 1) {
        T value = list->last->value;
        Node* oldlast = list->last;

        list->first = NULL;
        list->last = NULL;

        list->size--;
        destroyNode(oldlast);
        return value;
    }
    else {
        printf("There is no Elements. Returned 0");
        return 0;
    }
}
void eraseList(List* list) {
    while(list->size != 0) {
        popBack(list);
    }
}
void pushIndex(List* list, unsigned int index, T value) {
    if(index <= list->size) {
        Node* insertNode = makeNode(value);
        Node* nextNode = list->first;
        if(index < list->size/2) {
            for(int i=0; i < index; i++) nextNode = nextNode->next;
        }
        else if(index != list->size) {
            for(int i=list->size; i > index; i--) nextNode = nextNode->prev;
            
        }
        insertNode->prev = nextNode->prev;
        insertNode->next = nextNode;
        insertNode->prev->next = insertNode;
        insertNode->next->prev = insertNode;

        if(index == list->size) list->last = insertNode;
        if(index == 0) list->first = insertNode;

        list->size++;
    }
    else {
        printf("Out of Range\nIndex is %i but size of list is %i\n", index, list->size);
    }
}
T popIndex(List* list, unsigned int index) {
    if(index < list->size) {
        Node* node;
        if(index < list->size/2) {
            node = list->first;
            for(int i=0; i < index; i++) node = node->next;
        }
        else {
            node = list->last;
            for(int i=list->size-1; i > index; i--) node = node->prev;   
        }

        T value = node->value;
        node->next->prev = node->prev;
        node->prev->next = node->next;

        if(index == list->size-1) list->last = node->prev;
        if(index == 0) list->first = node->next;

        destroyNode(node);
        list->size--;

        return value;
    }
    else {
        printf("Out of Range\nIndex is %i but size of list is %i\nReturned 0", index, list->size);
        return 0;
    }

}
void pushUtilListFull(List* list, unsigned int size, T value) {
    while(list->size < size) {
        pushBack(list, value);
    }
}
