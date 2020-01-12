#ifndef DEQUE
#define DEQUE
#include <stdbool.h>
typedef int Item;

typedef struct {
    Item* elements;
    int size;
    int head; // this will always be 0, just for clarifications
    int tail;
} Deque;

Deque* deque_create(int size);
void deque_push_back(Deque* d, Item i);
void deque_push_front(Deque* d, Item i);
Item deque_pop_back(Deque* d);
Item deque_pop_front(Deque* d);
Item deque_back(Deque* d);
Item deque_front(Deque* d);
bool deque_isEmpty(Deque* d);
bool deque_isFull(Deque* d);
void deque_print(Deque* d);

#endif