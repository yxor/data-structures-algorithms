#include <stdio.h>
#include "deque.h"



int main()
{
    Deque* d;

    d = deque_create(20);
    deque_print(d);

    // should be empty on create
    printf("The deque is %s. (expects empty)\n", deque_isEmpty(d) ? "empty" : "not empty");


    for(int i = 0; i < 10; i++)
    {
        deque_push_front(d, i);
        deque_push_back(d, i);
    }
    
    deque_print(d);
    // should be full:
    printf("The deque is %s. (expects full)\n", deque_isFull(d) ? "full" : "not full");

    while(!deque_isEmpty(d))
    {
        printf("%2d", deque_pop_front(d));
    }
    printf("\n");
    
    for(int i = 0; i < 10; i++)
    {
        deque_push_front(d, i);
    }

    while(!deque_isEmpty(d))
    {
        printf("%2d", deque_pop_back(d));
    }


    return 0;
}