#include <stdio.h>
#include <stdlib.h>

#include "island.h"



void random_touch(Map* map, int row, int col) {
    
    int out_of_bound = (row >= map->n || row < 0) || (col >= map->n || col < 0);
    if(out_of_bound) 
        return;
    
    int do_i_touch = (rand() % 6) == 0; // some magic random number
    if(!do_i_touch)
        return;

    if(map->map[row][col] == LAND)
        return;
        
    map->map[row][col] = LAND;

    random_touch(map, row + 1, col); // bottom
    random_touch(map, row - 1, col);// top
    random_touch(map, row, col + 1); // right
    random_touch(map, row, col - 1); // left
    random_touch(map, row + 1, col + 1); // bottom right
    random_touch(map, row - 1, col - 1); // top left
    random_touch(map, row - 1, col + 1); // top right
    random_touch(map, row + 1, col - 1); // bottom left
}


Map* generate_map(int n, int touch_count) {

    Map* mapobj = (Map*) malloc(sizeof(Map));
    if(mapobj == NULL){
        perror("Error allocating the map object");
        exit(1);
    }

    int** map = (int**) malloc(n * sizeof(int*));
    if(map == NULL){
        perror("Error allocating the grid");
        exit(1);
    }

    for(int i = 0; i < n; i++){
    
        map[i] = (int*) calloc(n, sizeof(int)); // fill it with WATER
        if(map[i] == NULL){
            perror("Error allocating the smaller grid");
            exit(1);
        }
    }
    

    mapobj->map = map;
    mapobj->n = n;

    // number of touches to 1 w map to generate the islands
    for(int i = 0; i < touch_count; i++){
        int row = rand() % n;
        int col = rand() % n;
        random_touch(mapobj, row, col);
    }

    return mapobj;
}


void print_map(Map* map) {
    printf("Printing the map:\n");
    for(int row = 0; row < map->n; row++){
        for(int col = 0; col < map->n; col++){
            printf("%d  ", map->map[row][col]);
        }
        printf("\n");
    }
}



int count_islands(Map* map) {
    int island_count = 0;

    for(int row = 0; row < map->n; row++){
        for(int col = 0; col < map->n; col++){
            // when we find land discover it
            if(map->map[row][col] == LAND){
                discover(map, row, col);
                island_count++;
            }
        }
    }

    return island_count;
}



/**
 * Recursively crawl the island and discover it.
 * 
 * @return the size of the island.
 */
int discover(Map* map, int row, int col){
    // got out of the map
    int out_of_bound = (row >= map->n || row < 0) || (col >= map->n || col < 0);
    if(out_of_bound) 
        return 0;

    // in water or discovered this before (just a sanity check)
    int nothing_to_discover = (map->map[row][col] == WATER) || (map->map[row][col] == DISCOVERED);
    if(nothing_to_discover)
        return 0;

    // we are sitting on land, discover it
    map->map[row][col] = DISCOVERED;

    return 1 + discover(map, row + 1, col) // bottom
             + discover(map, row - 1, col) // top
             + discover(map, row, col + 1) // right
             + discover(map, row, col - 1) // left
             + discover(map, row + 1, col + 1) // bottom right
             + discover(map, row - 1, col - 1) // top left
             + discover(map, row - 1, col + 1) // top right
             + discover(map, row + 1, col - 1); // bottom left
             
}