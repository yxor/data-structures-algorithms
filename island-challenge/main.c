#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "island.h"





int main() {
    srand(time(NULL));

    Map* map = generate_map(50, 100);
    print_map(map);


    int island_count = count_islands(map);
    printf("---- AFTER SOLVING ----\n");
    print_map(map);

    printf("result: %d", island_count);

    return 0;
}

