#ifndef __item_c__
#define __item_c__

typedef struct {
    float128 key;
    char* data;
} Item;

Item* makeItem(float128 key, char* string) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->key = key;
    item->data = string;
    return item;
}
void destroyItem(Item* item) {
    free(item->data);
    free(item);
}
#endif
