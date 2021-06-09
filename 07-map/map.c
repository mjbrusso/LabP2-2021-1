#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_SIZE 100
#define HASH_SIZE 50

typedef struct mapnode {
    char key[VALUE_SIZE];
    int value;
    struct mapnode *next;
} mapnode;

struct map {
    mapnode *first;
    size_t size;
};

size_t hash_fn(char *s)
{
    return s[0]>='a' && s[0]<='m' ? 0 : 1;
}

// constructor
MAP *map_create()
{
    MAP *new_map = malloc(HASH_SIZE * sizeof(MAP));
    for (int i = 0; i < HASH_SIZE; i++) {
        new_map[i].first = NULL;
        new_map[i].size = 0;
    }

    return new_map;
}

size_t map_size(MAP *m)
{
    size_t total = 0;
    for (int h = 0; h < HASH_SIZE; h++) {
        total += m[h].size;
    }
    return total;
}

// Operação destrutora
void map_destroy(MAP *m)
{
    for (int h = 0; h < HASH_SIZE; h++) {
        mapnode *p = m[h].first, *aux;

        while (p != NULL) {
            aux = p->next;
            free(p);
            p = aux;
        }
    }
    free(m);
}

void map_foreach(MAP *m, void (*fn)(char *, int))
{
    for (int h = 0; h < HASH_SIZE; h++) {
        mapnode *p = m[h].first;
        while (p != NULL) {
            fn(p->key, p->value);
            p = p->next;
        }
    }
}

int map_search(MAP *m, char *key, int *value)
{
    size_t h = hash_fn(key);
    mapnode *p = m[h].first;
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
int map_remove(MAP *m, char *key)
{
    size_t h = hash_fn(key);
    mapnode *p = m[h].first;
    mapnode *ant = NULL;
    while (p != NULL) {
        if (strcmp(p->key, key) == 0) {
            if (ant == NULL)
                m[h].first = p->next;
            else
                ant->next = p->next;

            free(p);
            m[h].size--;
            return 1;
        }
        ant = p;
        p = p->next;
    }
    return 0;
}

void map_push_front(MAP *m, char *key, int value)
{
    size_t h = hash_fn(key);
    mapnode *new_mapnode = malloc(sizeof(mapnode));
    strcpy(new_mapnode->key, key);
    new_mapnode->value = value;
    new_mapnode->next = m[h].first;

    m[h].first = new_mapnode;
    m[h].size++;
}

// Insere o valor ordenado na mapa (ordem alfabética ascendente)
void map_insert(MAP *m, char *key, int value)
{
    size_t h = hash_fn(key);
    if (m[h].first == NULL || strcmp(m[h].first->key, key) >= 0) {
        map_push_front(m, key, value);
        return;
    }

    mapnode *p = m[h].first, *ant = NULL;
    while (p != NULL && strcmp(p->key, key) < 0) {
        ant = p;
        p = p->next;
    }

    mapnode *novo = malloc(sizeof(mapnode));
    strcpy(novo->key, key);
    novo->value = value;
    novo->next = p;
    ant->next = novo;
    m[h].size++;
}

int map_setvalue(MAP *m, char *key, int value)
{
	size_t h = hash_fn(key);
    mapnode *p = m[h].first;
    while (p != NULL) {
        if (strcmp(p->key, key) == 0) {
            p->value = value;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

MAP_ITERATOR *map_get_iterators(MAP *m)
{
    size_t i = 0;
    MAP_ITERATOR *vio = malloc(map_size(m) * sizeof(MAP_ITERATOR));
    for (int h = 0; h < HASH_SIZE; h++) {
        mapnode *p = m[h].first;
        while (p != NULL) {
            vio[i++] = p;
            p = p->next;
        }
    }
    return vio;
}

char *map_key_at(MAP_ITERATOR it)
{
    return it->key;
}

int map_value_at(MAP_ITERATOR it)
{
    return it->value;
}