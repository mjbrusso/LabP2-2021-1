#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int matricula;
  char nome[100];
  float salario;
} funcionario;

#define NFUNC 4

int ordenasalario(const void* p1, const void* p2) {
  const funcionario *pf1 = p1, *pf2 = p2;

  if (pf1->salario < pf2->salario)
    return 1;
  else if (pf1->salario > pf2->salario)
    return -1;
  else  // Empatou
      // desempata em ordem alfabética do nome : 
    return strcmp(pf1->nome, pf2->nome);
    // desempata em ordem crescente da matrícula : 
    // return pf1->matricula - pf2->matricula;
}

int main() {
  funcionario equipe[NFUNC];

  for (int i = 0; i < NFUNC; i++) {
    printf("Informe dados do funcionário\n");
    printf("  Matrícula: ");
    scanf("%d%*c", &equipe[i].matricula);
    printf("  Nome.....: ");
    scanf("%[^\n]", equipe[i].nome);
    printf("  Salário..: ");
    scanf("%f", &equipe[i].salario);
  }

  qsort(equipe, NFUNC, sizeof(funcionario), ordenasalario);

  for (int i = 0; i < NFUNC; i++) {
    printf("#%d Matrícula: %06d Nome: %-40s Salário: %10.2f\n", i,
           equipe[i].matricula, equipe[i].nome, equipe[i].salario);
  }
  return 0;
}
