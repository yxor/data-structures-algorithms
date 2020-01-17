#ifndef _HTABLE
#define _HTABLE
#include <stdbool.h>

typedef int Item;

typedef struct node {
    Item element;
    struct node* next; 
} Node;

typedef struct {
    Node** elements;
    int size;
} ht_t;



ht_t* ht_init(int size);
void ht_insert(ht_t* ht, Item key);
bool ht_delete(ht_t* ht, Item key);
bool ht_search(ht_t* ht, Item key);
void ht_dump(ht_t* ht);
void ht_destroy(ht_t* ht);

#endif