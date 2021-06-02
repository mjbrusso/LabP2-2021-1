#include <stdlib.h>

typedef struct map MAP;

MAP *map_create();
void map_push_front(MAP *l, char *value);
void map_sorted_insert(MAP *l, char *value);
size_t map_size(MAP *l);
int map_search(MAP *l, char *value);
int map_remove(MAP *l, char *value);
void map_foreach(MAP *l, void (*fn)(char *));
void map_destroy(MAP *l);
