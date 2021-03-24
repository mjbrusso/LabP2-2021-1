#include <stdio.h>
#include "funcoes.c"

#define N 5

int main()
{
    float v[N] = {3.3, 4.4, 5.5, 7.7, 9.0};

    float med = mediavetf(v, N);
    printf("Média: %f\n", med);

    float b[]={10.0, 20.0, 999.0};
    printf("Média: %f\n", mediavetf(b, 3));
    return 0;
}
