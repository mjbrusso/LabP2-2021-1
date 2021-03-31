#include <stdio.h>
#include "ordenacao.c"

#define N 100000

int vet[N];

int main()
{
    // Entrada
    for (int i = 0; i < N; i++)
        scanf("%d", &vet[i]);

    // Ordenação
    bubblesort(vet, N);

    //  Saída
    for (int i = 0; i < N; i++)
        printf("%d\n", vet[i]);

    return 0;
}
