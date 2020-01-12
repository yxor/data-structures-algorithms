#include <stdlib.h>
#include <stdio.h>
#include "btree.h"



int main()
{
    Tree t = tree_create();
    tree_insert(t, 5);
    tree_insert(t, 10);
    tree_insert(t, 3);
    tree_insert(t, 1);
    tree_insert(t, 5);
    tree_insert(t, 15);
    tree_insert(t, 19);
    tree_insert(t, 8);
    tree_print(t);
    int max = tree_max(t);
    int min = tree_min(t);
    printf("\n%d %d", max, min);
    return 0;
}