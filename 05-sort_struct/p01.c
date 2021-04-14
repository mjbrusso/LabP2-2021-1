#include <stdio.h>

typedef struct {
  int matricula;
  char nome[100];
  float salario;
} funcionario;

int main() {
  funcionario eu;

  printf("Informe dados do funcionário\n");
  printf("Matrícula: ");
  scanf("%d%*c", &eu.matricula);
  printf("Nome.....: ");
  scanf("%[^\n]", eu.nome);
  printf("Salário..: ");
  scanf("%f", &eu.salario);

  printf("Matrícula: %d\tNome: %s\tSalário: %.2f\n", eu.matricula, eu.nome,
         eu.salario);
         
  return 0;
}
