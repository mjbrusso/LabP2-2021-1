#include <stdlib.h>

#define VALUE_SIZE 100

typedef struct node{
    char value[VALUE_SIZE];
    struct node *next;
} node;

typedef struct linkedlist
{
    node *first;
    size_t size;  
} LIST;




