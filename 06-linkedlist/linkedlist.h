#include <stdlib.h>

typedef struct linkedlist LIST;

LIST *list_create();
void list_push_front(LIST *l, char *value);
void list_sorted_insert(LIST *l, char *value)
size_t list_size(LIST *l);
int list_search(LIST *l, char *value);
int list_remove(LIST *l, char *value);
void list_foreach(LIST *l, void (*fn)(char *));
void list_destroy(LIST *l);

