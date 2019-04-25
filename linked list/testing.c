#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main()
{
    int i;
    List* list = list_create();
    for(i = 0; i < 10; i++)
    {
        list_insert_first(list, i);
    }
    for(i = 0; i < 10; i++)
    {
        list_insert_last(list, i);
    }
    
    list_print(list);
    
    for(i = 0; i < 5; i++)
    {
        list_remove_last(list);
    }
    for(i = 0; i < 5; i++)
    {
        list_remove_first(list);
    }
    for(i = 0; i < 5; i++)
    {
        list_remove_key(list, 0);
    }

    list_print(list);

    return 0;
}