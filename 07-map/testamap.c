#include "map.h"
#include <stdio.h>

void mostra(char *k, int v) 
{
     printf("%s : %d\n", k, v); 
}

int main() {
  MAP *deaths = map_create();

  map_insert(deaths, "Brasil", 465312);
  map_insert(deaths, "USA", 610540);
  map_insert(deaths, "India", 337421);
  map_insert(deaths, "Uk", 127794);

  int n;
  if (map_search(deaths, "Uruguay", &n)) {
    printf("%d deaths\n", n);
  } else {
    printf("Not found\n");
  }

  map_foreach(deaths, mostra);
  map_destroy(deaths);
}