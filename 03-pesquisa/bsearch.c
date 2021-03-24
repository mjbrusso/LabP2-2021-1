#include <stdio.h>
#include <stdlib.h>

int intcmp(const void *a, const void *b)
{
    const int *pa = a, *pb = b;
    return *pa - *pb;
}

int main()
{
    int vet[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int valor;

    const int **ptr;

    printf("Search: ");
    scanf("%d", &valor);
    
    if(bsearch(&valor, vet, 10, sizeof(int), intcmp)==NULL)
        printf("Not found\n");
    else
        printf("Found\n");

    return 0;
}
