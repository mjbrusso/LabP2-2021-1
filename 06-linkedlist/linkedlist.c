#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define VALUE_SIZE 100

typedef struct node {
  char value[VALUE_SIZE];
  struct node *next;
} node;

typedef struct linkedlist {
  node *first;
  size_t size;
} LIST;

// constructor
LIST *list_create() {
    LIST* new_list=malloc(sizeof(LIST));
    new_list->first = NULL;
    new_list->size = 0;

    return new_list;
}

void list_push_front(LIST* l, char* value){
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->value, value);
    new_node->next = l->first;

    l->first = new_node;
    l->size++;
}

size_t list_size(LIST* l)
{
    return l->size;
}

void list_show(LIST *l){
    node* p = l->first;

    while(p!=NULL){
        printf("%s\n", p->value);
        p = p->next;
    }
}

// Pesquisa pelo valor na lista encadeada
// Retorna 1 se encontrou, 0 se não encontrou
int list_search(LIST *l, char* value){

}

// Remove da lista o nodo que contêm o valor 
// Retorna 1 se encontrou, 0 se não encontrou
int list_remove(LIST *l, char* value){

}