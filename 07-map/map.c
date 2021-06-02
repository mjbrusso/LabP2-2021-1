#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_SIZE 100

typedef struct mapnode {
  char key[VALUE_SIZE];
  int value;
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

size_t map_size(MAP *m) { return m->size; }

int map_search(MAP *m, char *key, int *value) {
  mapnode *p = m->first;
  while (p != NULL) {
    if (strcmp(p->key, key) == 0) {
      *value = p->value;
      return 1;
    }
    p = p->next;
  }
  return 0;
}

// Remove da mapa o nodo que contêm a chave
// Retorna 1 se encontrou, 0 se não encontrou
int map_remove(MAP *m, char *key) {
  mapnode *p = m->first;
  mapnode *ant = NULL;
  while (p != NULL) {
    if (strcmp(p->key, key) == 0) {
      if (ant == NULL)
        m->first = p->next;
      else
        ant->next = p->next;

      free(p);
      m->size--;
      return 1;
    }
    ant = p;
    p = p->next;
  }
  return 0;
}

// Operação destrutora
void map_destroy(MAP *m) {
  mapnode *p = m->first, *aux;

  while (p != NULL) {
    aux = p->next;
    free(p);
    p = aux;
  }

  free(m);
}

void map_foreach(MAP *m, void (*fn)(char *, int)) {
  mapnode *p = m->first;
  while (p != NULL) {
    fn(p->key, p->value);
    p = p->next;
  }
}

void map_push_front(MAP *m, char *key, int value) {
  mapnode *new_mapnode = malloc(sizeof(mapnode));
  strcpy(new_mapnode->key, key);
  new_mapnode->value = value;
  new_mapnode->next = m->first;

  m->first = new_mapnode;
  m->size++;
}

// Insere o valor ordenado na mapa (ordem alfabética ascendente)
void map_insert(MAP *m, char *key, int value) {
  if (m->first == NULL || strcmp(m->first->key, key) >= 0) {
    map_push_front(m, key, value);
    return;
  }

  mapnode *p = m->first, *ant = NULL;
  while (p != NULL && strcmp(p->key, key) < 0) {
    ant = p;
    p = p->next;
  }

  mapnode *novo = malloc(sizeof(mapnode));
  strcpy(novo->key, key);
  novo->value = value;
  novo->next = p;
  ant->next = novo;
  m->size++;
}