#include "linkedlist.h"
#include <ctype.h>
#include <stdio.h>

void exibe(char *s) { printf("%s\n", s); }

void maiusculas(char *s) {
  while (*s != '\0') {
    *s = toupper(*s);
    s++;
  }
}

int main() {
  LIST *nomes;

  nomes = list_create(); // operação construtora

  list_push_front(nomes, "Paula"); // operação atualizadora
  list_push_front(nomes, "Joaquim");
  list_push_front(nomes, "Alberto");

  printf("A lista possui %lu valores\n",
         list_size(nomes)); // operação consultora

  printf("Antes do remove\n");
  list_foreach(nomes, exibe);
  list_remove(nomes, "Paula"); // operação atualizadora

  list_foreach(nomes, maiusculas);
  printf("Depois do remove\n");
  list_foreach(nomes, exibe);

  printf("%schou na lista\n", list_search(nomes, "Joaquim") ? "A" : "Não a");

  list_destroy(nomes); // operação destrutora
}
