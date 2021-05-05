#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia, mes, ano;
} data;

int main() {
  /* data hoje = {20, 5, 2021};
 data *pd;
 pd = &hoje;
 printf("%p\n", pd);
 printf("%02d/%02d/%04d\n", hoje.dia, hoje.mes, hoje.ano);
 printf("%d\n", pd->ano);
 hoje.ano = 2045;
 printf("%d\n", pd->ano); */

  data *pd;
  pd = malloc(sizeof(data));
  if (pd == NULL) {
    printf("No memory!\n");
    exit(1);
  }
  printf("Informe a data (dd/mm/aaaa):");
  scanf("%d/%d/%d", &pd->dia, &pd->mes, &pd->ano);
  printf("%02d/%02d/%04d\n", pd->dia, pd->mes, pd->ano);
  free(pd);

  return 0;
}