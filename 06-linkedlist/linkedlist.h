#include <stdlib.h>

typedef struct linkedlist LIST;

LIST *list_create();
void list_push_front(LIST *l, char *value);
size_t list_size(LIST *l);
void list_show(LIST *l);
int list_search(LIST *l, char *value);
int list_remove(LIST *l, char *value);
void list_destroy(LIST *l);

