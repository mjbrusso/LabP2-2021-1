#include <stdio.h>
#include <assert.h>
#include "funcoes.c"

int main()
{
    assert(maiorf(10, 5)==10);
    assert(maiorf(-10, 5)==5);
    assert(maiorf(5, 10)==10);
    assert(maiorf(-5, 10)==10);
    assert(maiorf(-5, -10)==-5);
    assert(maiorf(55, 55)==55);

    printf("The end\n");
    return 0;
}
