#include <stdlib.h>

typedef struct map MAP;
MAP *map_create();
void map_insert(MAP *m, char *key, int value);
size_t map_size(MAP *l);
int map_search(MAP *m, char *key, int *value);
int map_remove(MAP *l, char *value);
void map_foreach(MAP *l, void (*fn)(char *, int));
int map_setvalue(MAP *m, char *key, int value);
void map_destroy(MAP *l);

typedef struct mapnode* MAP_ITERATOR;
MAP_ITERATOR *map_get_iterators(MAP *m);
char *map_key_at(MAP_ITERATOR it);
int map_value_at(MAP_ITERATOR it);
