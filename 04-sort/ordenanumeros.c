#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.c"

#define N 100000

int vet[N];

int intcmp(const void *a, const void *b)
{
    const int *pa = a, *pb = b;
    return *pa - *pb;
}

int main()
{
    // Entrada
    for (int i = 0; i < N; i++)
        scanf("%d", &vet[i]);

    // Ordenação
    //insertionsort(vet, N);
    qsort(vet, N, sizeof(vet[0]), intcmp);

    //  Saída
    for (int i = 0; i < N; i++)
        printf("%d\n", vet[i]);

    return 0;
}
