#include "linkedlist.h"
#include <stdio.h>

int main() {
  LIST *nomes;

  nomes = list_create(); // operação construtora

  list_push_front(nomes, "Paula"); // operação atualizadora
  list_push_front(nomes, "Joaquim");
  list_push_front(nomes, "Alberto");

  printf("A lista possui %lu valores\n",
         list_size(nomes)); // operação consultora

  printf("Antes do remove\n");
  list_show(nomes); // operação consultora

  list_remove(nomes, "Paula"); // operação atualizadora

  printf("Depois do remove\n");
  list_show(nomes); // operação consultora

  printf("%schou na lista\n", list_search(nomes, "Joaquim") ? "A" : "Não a");

  list_destroy(nomes); // operação destrutora
}
