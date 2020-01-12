#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "deque.h"

// Util functions

// shifts an array one element to the right
static void shift_right(int* arr, int n)
{
    for(int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1]; 
    }
}

// shifts an array one element to the right
static void shift_left(int* arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i]; 
    }
}

// DEQUE functions

Deque* deque_create(int size)
{
    Deque* d = (Deque*) calloc(1, sizeof(Deque));
    assert(d != NULL);

    d->elements = (Item*) malloc(size * sizeof(Item));
    assert(d->elements != NULL);

    d->head = -1;
    d->tail = -1;
    d->size = size;

    return d;
}

void deque_push_back(Deque* d, Item i)
{
    // sanity check
    assert(d != NULL);
    assert(!deque_isFull(d));

    if(deque_isEmpty(d)){
        d->head = d->tail = 0;
        d->elements[d->tail] = i;
    }else {
        d->elements[++(d->tail)] = i;
    }
}
void deque_push_front(Deque* d, Item i)
{
    // sanity check
    assert(d != NULL);
    assert(!deque_isFull(d));

    if(deque_isEmpty(d)){
        d->head = d->tail = 0;
        d->elements[d->head] = i;
    }else {
        shift_right(d->elements, d->size);
        d->elements[d->head] = i;
        d->tail++;
    }
}

Item deque_pop_back(Deque* d)
{
    assert(d != NULL);
    assert(!deque_isEmpty(d));

    return d->elements[d->tail--];
}

Item deque_pop_front(Deque* d)
{
    assert(d != NULL);
    assert(!deque_isEmpty(d));
    
    Item toReturn = d->elements[d->head];
    shift_left(d->elements, d->size);
    d->tail--;

    return toReturn;
}

Item deque_back(Deque* d)
{
    assert(d != NULL);
    assert(!deque_isEmpty(d));

    return d->elements[d->tail];
}
Item deque_front(Deque* d)
{
    assert(d != NULL);
    assert(!deque_isEmpty(d));
    
    return d->elements[d->head];
}

bool deque_isEmpty(Deque* d)
{
    return d->tail == -1;
}

bool deque_isFull(Deque* d)
{
    return d->tail >= d->size-1;
}

void deque_print(Deque* d)
{
    for(int i = 0; i < d->tail+1; i++)
    {
        printf("%2d", d->elements[i]);
    }
    printf("\n");
}