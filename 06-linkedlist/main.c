#include <stdio.h>
#include "linkedlist.c"

int main() {
  LIST *nomes;

  nomes = list_create(); // operação construtora

  list_push_front(nomes, "Paula"); // operação atualizadora
  list_push_front(nomes, "Joaquim");
  list_push_front(nomes, "Alberto");

  printf("A lista possui %lu valores\n",
         list_size(nomes)); // operação consultora

  list_show(nomes);         // operação consultora

  //   list_remove(nomes, "Joaquim"); // operação atualizadora

  //   if (list_search(nomes, "Pedro")) { // operação consultora
  //     printf("Achou Pedro na lista\n");
  //   }


  //   list_destroy(nomes);      // operação destrutora
}