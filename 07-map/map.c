#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define VALUE_SIZE 100
#define HASH_SIZE 997

typedef struct mapnode {
    wchar_t key[VALUE_SIZE];
    int value;
    struct mapnode *next;
} mapnode;

struct map {
    mapnode *first;
    size_t size;
};

size_t hash_fn(wchar_t *s)
{
    // unsigned soma = 0;
    // for (int i = 0; s[i] != '\0'; i++) {
    //     soma += (unsigned)s[i];
    // }
    //     return soma % HASH_SIZE;
    size_t n = 5381;

    for (int i = 0; s[i] != '\0'; i++) {
        n = (n * 33) + s[i];
    }

    return n % HASH_SIZE;
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

void map_foreach(MAP *m, void (*fn)(wchar_t *, int))
{
    for (int h = 0; h < HASH_SIZE; h++) {
        mapnode *p = m[h].first;
        while (p != NULL) {
            fn(p->key, p->value);
            p = p->next;
        }
    }
}

int map_search(MAP *m, wchar_t *key, int *value)
{
    size_t h = hash_fn(key);
    mapnode *p = m[h].first;
    while (p != NULL) {
        int res = wcscmp(p->key, key);
        if (res == 0) {
            *value = p->value;
            return 1;
        } else if (res > 0)
            return 0;
        p = p->next;
    }

    return 0;
}

// Remove da mapa o nodo que contêm a chave
// Retorna 1 se encontrou, 0 se não encontrou
int map_remove(MAP *m, wchar_t *key)
{
    size_t h = hash_fn(key);
    mapnode *p = m[h].first;
    mapnode *ant = NULL;
    while (p != NULL) {
        if (wcscmp(p->key, key) == 0) {
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

void map_push_front(MAP *m, wchar_t *key, int value)
{
    size_t h = hash_fn(key);
    mapnode *new_mapnode = malloc(sizeof(mapnode));
    wcscpy(new_mapnode->key, key);
    new_mapnode->value = value;
    new_mapnode->next = m[h].first;

    m[h].first = new_mapnode;
    m[h].size++;
}

// Insere o valor ordenado na mapa (ordem alfabética ascendente)
void map_insert(MAP *m, wchar_t *key, int value)
{
    size_t h = hash_fn(key);
    if (m[h].first == NULL || wcscmp(m[h].first->key, key) >= 0) {
        map_push_front(m, key, value);
        return;
    }

    mapnode *p = m[h].first, *ant = NULL;
    while (p != NULL && wcscmp(p->key, key) < 0) {
        ant = p;
        p = p->next;
    }

    mapnode *novo = malloc(sizeof(mapnode));
    wcscpy(novo->key, key);
    novo->value = value;
    novo->next = p;
    ant->next = novo;
    m[h].size++;
}

int map_setvalue(MAP *m, wchar_t *key, int value)
{
    size_t h = hash_fn(key);
    mapnode *p = m[h].first;
    while (p != NULL) {
        int res = wcscmp(p->key, key);
        if (res > 0)
            break;
        else if (res == 0) {
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
        //printf("h=%d, size=%ld\n", h, m[h].size);
        mapnode *p = m[h].first;
        while (p != NULL) {
            vio[i++] = p;
            p = p->next;
        }
    }
    return vio;
}

wchar_t *map_key_at(MAP_ITERATOR it)
{
    return it->key;
}

int map_value_at(MAP_ITERATOR it)
{
    return it->value;
}