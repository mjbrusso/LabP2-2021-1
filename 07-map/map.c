#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_SIZE 100

typedef struct mapnode {
  char value[VALUE_SIZE];
  struct mapnode *next;
} mapnode;

struct map {
  mapnode *first;
  size_t size;
};

// constructor
MAP *map_create() {
  MAP *new_map = malloc(sizeof(MAP));
  new_map->first = NULL;
  new_map->size = 0;

  return new_map;
}

void map_push_front(MAP *l, char *value) {
  mapnode *new_mapnode = malloc(sizeof(mapnode));
  strcpy(new_mapnode->value, value);
  new_mapnode->next = l->first;

  l->first = new_mapnode;
  l->size++;
}

size_t map_size(MAP *l) { return l->size; }

// Pesquisa pelo valor na mapa encadeada
// Retorna 1 se encontrou, 0 se não encontrou
int map_search(MAP *l, char *value) {
  mapnode *p = l->first;
  while (p != NULL) {
    if (strcmp(p->value, value) == 0) {
      return 1;
    }
    p = p->next;
  }
  return 0;
}

// Remove da mapa o nodo que contêm o valor
// Retorna 1 se encontrou, 0 se não encontrou
int map_remove(MAP *l, char *value) {
  mapnode *p = l->first;
  mapnode *ant = NULL;
  while (p != NULL) {
    if (strcmp(p->value, value) == 0) {
      if (ant == NULL)
        l->first = p->next;
      else
        ant->next = p->next;

      free(p);
      l->size--;
      return 1;
    }
    ant = p;
    p = p->next;
  }
  return 0;
}

// Operação destrutora
void map_destroy(MAP *l) {
  mapnode *p = l->first, *aux;

  while (p != NULL) {
    aux = p->next;
    free(p);
    p = aux;
  }

  free(l);
}

void map_foreach(MAP *l, void (*fn)(char *)) {
  mapnode *p = l->first;
  while (p != NULL) {
    fn(p->value);
    p = p->next;
  }
}

// Insere o valor ordenado na mapa (ordem alfabética ascendente)
void map_insert(MAP *l, char *value) {
  if (l->first == NULL || strcmp(l->first->value, value) >= 0) {
    map_push_front(l, value);
    return;
  }

  mapnode *p = l->first, *ant = NULL;
  while (p != NULL && strcmp(p->value, value) < 0) {
    ant = p;
    p = p->next;
  }

  mapnode *novo = malloc(sizeof(mapnode));
  strcpy(novo->value, value);
  novo->next = p;
  ant->next = novo;
  l->size++;
}