#include <stdlib.h>

typedef struct map MAP;

MAP *map_create();
void map_insert(MAP *m, char *key, int value);
size_t map_size(MAP *l);
int map_search(MAP *m, char *key, int *value);
int map_remove(MAP *l, char *value);
void map_foreach(MAP *l, void (*fn)(char *, int));
void map_destroy(MAP *l);
