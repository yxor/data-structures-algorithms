#include <stdlib.h>
#include <stdio.h>
#include "list.h"


//// node related functions ////
Node* node_create(Item data)
{
    Node* node = (Node*) malloc(sizeof(Node));

    if (node == NULL){
        fprintf(stderr, "Not enough memory to allocate the node");
        exit(1);
    }

    node->data = data;
    node->next = NULL;
    node->previous = NULL;
    
    return node;
}
//// list related functions ////
// constructor
List* list_create()
{
    List* list = (List*) malloc(sizeof(List));
    
    if (list == NULL){
        fprintf(stderr, "Not enough memory to allocate the List");
        exit(1);
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}
// destructor
void list_free(List* list)
{
    if(!list->head){
        free(list);
        return;
    }
    
    Node* curr = list->head;

    while(curr)
    {
        curr = curr->next;
        free(curr->previous);

    }
    free(list);
}

// access
Item list_get_first(List* list)
{
    return list->head->data;
}

Item list_get_last(List* list)
{
    return list->tail->data;
}

Item list_get_index(List* list, int index)
{
    if(index < 0 || index >= list->length){
        fprintf(stderr, "Index out of range");
        exit(1);
    }
    if(index == list->length -1)
    {
        return list_get_last(list);
    }

    int i = 0;
    Node* curr = list->head;

    while(i < index)
    {
        curr = curr->next;
        i++;
    }
    return curr->data;
}


// insertion
int list_insert_first(List* list, Item item)
{
    Node* to_insert = node_create(item);

    if(list->head == NULL){ 
        // the list was empty before this
        list->head = to_insert;
        list->tail = to_insert;
    }else{ 
        // the list has items in it
        to_insert->next = list->head;
        to_insert->previous = NULL;
        list->head->previous = to_insert;
        list->head = to_insert;
    }

    list->length++;
    return SUCCESS;
}


int list_insert_last(List* list, Item item)
{
    Node* to_insert = node_create(item);

    if(list->tail == NULL){ 
        // the list was empty before this
        list->head = to_insert;
        list->tail = to_insert;
    }else{ 
        // the list has items in it
        to_insert->next = NULL;
        to_insert->previous = list->tail;
        list->tail->next = to_insert;
        list->tail = to_insert;
    }
    list->length++;
}

int list_insert_at(List* list, Item item, Item key, bool add_after)
{
    Node* before;
    Node* after;
    Node* curr = list->head;
    Node* to_insert;

    // just in case its either the beginning or the end of the node
    if(list->head->data == key){
        return list_insert_first(list, item);
    }
    if(list->tail->data == key){
        return list_insert_last(list, item);
    }
    // if thats not the case
    while(curr && curr->data != key){
        curr = curr->next;
    }
    //now curr is pointing at the key node or at the end of the array
    // if its in the end of the array raise key not found error
    if (curr == NULL)
        return KEY_NOT_FOUND;
    // okay now we know the key is there, lets take the element after the key Node
    // or the one after depending on the bool add after

    if(add_after){
        before = curr;
        after = curr->next;
    }else{
        before = curr->previous;
        after = curr;
    }
    // since all is left is to connect lets fucking create the node for the new link
    to_insert = node_create(item);
    // time to connect the fucking Nodes
    to_insert->previous = before;
    to_insert->next = after;

    before->next = to_insert;
    after->previous = to_insert;
    // all good
}

// deletion
int list_remove_first(List* list)
{
    Node* to_remove = list->head;
    list->head = list->head->next;
    list->head->previous = NULL;
    free(to_remove);
    list->length--;
}
int list_remove_last(List* list)
{
    Node* to_remove = list->tail;
    list->tail = list->tail->previous;
    list->tail->next = NULL;
    free(to_remove);
    list->length--;
}


int list_remove_key(List* list, Item key)
{
    Node* before;
    Node* after;
    Node* curr = list->head;
    Node* to_insert;

    if(list->head->data == key){
        return list_remove_first(list);
    }
    if(list->tail->data == key){
        return list_remove_last(list);
    }
    // if thats not the case
    while(curr && curr->data != key){
        curr = curr->next;
    }
    //now curr is pointing at the key node or at the end of the array
    // if its in the end of the array return key not found error code
    if (curr == NULL)
        return KEY_NOT_FOUND;
    
    before = curr->previous;
    after = curr->next;

    before->next = after;
    after->previous = before;

    free(curr);
    list->length--;
    
    return SUCCESS;
}

// other stuff
void list_print(List *list)
{
    Node* iter;
    iter = list->head;
    printf("List contain %d Items:\n", list->length);
    while(iter)
    {
        printf("%d|", iter->data);
        iter = iter->next;
    }
}

bool list_isEmpty(List* list)
{
    return !list->length;
}