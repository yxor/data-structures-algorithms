#ifndef ISLAND_CHALLENGE
#define ISLAND_CHALLENGE


#define WATER 0
#define LAND 1
#define DISCOVERED 2

typedef struct {
    int** map;
    int n;
} Map;



/**
 * Allocate and create a map and generate island based on numbers of touches.
 * 
 * @return The island.
 */
Map* generate_map(int n, int touche_count);


/**
 * Print the map.
 *
 */
void print_map(Map* map);


/**
 * Find out how many islands are in a map of islands.
 * 
 * @return number of islands
 */
int count_islands(Map* map);


/**
 * Recursively crawl the island and discover it.
 * 
 * @return the size of the island.
 */
int discover(Map* map, int row, int col);


#endif