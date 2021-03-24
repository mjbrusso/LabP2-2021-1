#include <stdio.h>

int main()
{
    int vet[4], soma=0;

    for (int i = 0; i < 4; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &vet[i]);
        soma += vet[i];
    }

    printf("Soma: %d\nMédia: %f\n", soma, soma/4.0);

    return 0;
}
