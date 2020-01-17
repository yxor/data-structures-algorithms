#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"
#include <assert.h>


int hash(ht_t* ht, Item key)
{
    return key % ht->size;
}


ht_t* ht_init(int size)
{
    ht_t* ht = (ht_t*) malloc(sizeof(ht_t));
    assert(ht != NULL);

    ht->elements = (Node**) calloc(size, sizeof(Node*));
    ht->size = size;
    assert(ht->elements);

    return ht;
}

void ht_insert(ht_t* ht, Item key)
{
    Node* node = (Node*) malloc(sizeof(Node));
    assert(node != NULL);

    node->element = key;
    node->next = NULL;

    int hashed = hash(ht, key);

    if(ht->elements[hashed] == NULL)
    {
        ht->elements[hashed] = node;
        return;
    }

    Node* temp = ht->elements[hashed];
    if(temp->element == key) // element already exists in hashmap
        return;
    while(temp->next){
        if(temp->element == key) // element already exists in hashmap
            return;
        temp = temp->next;
    }
    // temp->next is NULL and key does not exist in the hashmap
    temp->next = node;
}

// delete elements if exists, return false if element is not found and true on successful deletion
bool ht_delete(ht_t* ht, Item key)
{
    int hashed = hash(ht, key);
    
    if(ht->elements[hashed] == NULL)
        return false;
    
    Node* temp = ht->elements[hashed];
    if(temp->element == key)
    {
        ht->elements[hashed] = temp->next;
        free(temp);
        return true;
    }

    while(temp->next && temp->next->element != key)
    {
        temp = temp->next;
    }
    
    if(!temp->next)
        return false;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return true;
}

bool ht_search(ht_t* ht, Item key)
{
    int hashed = hash(ht, key);
    Node* temp = ht->elements[hashed];
    if(!temp)
        return false;
    while(temp){
        if(temp->element == key)
            return true;
        temp = temp->next;
    }
}


void ht_dump(ht_t* ht)
{
    Node* node;
    for(int i = 0; i < ht->size; i++)
    {
        node = ht->elements[i];
        while(node)
        {
            printf("key:%3d Value:%3d\n", i, node->element);
            node = node->next;
        }
    }
}

void ht_destroy(ht_t* ht)
{
    Node* node, *toDelete;
    for(int i = 0; i < ht->size; i++)
    {
        node = ht->elements[i];
        while(node)
        {
            toDelete = node;
            node = node->next;
            free(toDelete);
        }
    }
    free(ht);
}
