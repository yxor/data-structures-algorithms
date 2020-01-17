#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "hashtable.h"

int main(){
    ht_t* hashtable = ht_init(50);
    ht_dump(hashtable);
    printf("\n");
    ht_insert(hashtable, 30);
    ht_insert(hashtable, 5);
    ht_insert(hashtable, 2);
    ht_insert(hashtable, 15);
    ht_insert(hashtable, 1);
    ht_insert(hashtable, 22);
    ht_insert(hashtable, 9);
    ht_insert(hashtable, 100);
    ht_insert(hashtable, 50);
    ht_dump(hashtable);
    printf("\n");
    printf("Searching for %d, expected %d, result %d\n", 100, true, ht_search(hashtable, 100));
    ht_delete(hashtable, 100);
    printf("Searching for %d, expected %d, result %d\n", 100, false, ht_search(hashtable, 100));

}