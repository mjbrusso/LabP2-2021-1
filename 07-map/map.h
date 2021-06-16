#include <wchar.h>

typedef struct map MAP;
MAP *map_create();
void map_insert(MAP *m, wchar_t *key, int value);
size_t map_size(MAP *l);
int map_search(MAP *m, wchar_t *key, int *value);
int map_remove(MAP *l, wchar_t *value);
void map_foreach(MAP *l, void (*fn)(wchar_t *, int));
int map_setvalue(MAP *m, wchar_t *key, int value);
void map_destroy(MAP *l);

typedef struct mapnode* MAP_ITERATOR;
MAP_ITERATOR *map_get_iterators(MAP *m);
wchar_t *map_key_at(MAP_ITERATOR it);
int map_value_at(MAP_ITERATOR it);
