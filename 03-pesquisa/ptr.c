
#include <stdio.h>
#include <assert.h>

void mostra(int n){
    printf("%d\n", n);
}

int main()
{
    int n=5;
    int *p;
    p = &n;

    void (*pf)(int);

    pf = &mostra;

    pf(55);

    printf("%p\n", p);
    mostra(*p);

    return 0;
}
