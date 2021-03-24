/*
    Escrever, no arquivo "funcoes.c", a função:

        long long fatorial(int n)
    
    Ela recebe um inteiro n como parâmetro, 
    calcula e retorna o fatorial de n (n!), 
    no formato de um long long (inteiro de 64 bits).

    Usar a seguinte bateria de testes para validar a sua implementação.
*/

#include <stdio.h>
#include <assert.h>
#include "funcoes.h"

int main()
{
    assert(fatorial(0)==1);
    assert(fatorial(1)==1);
    assert(fatorial(2)==2);
    assert(fatorial(3)==6);
    assert(fatorial(4)==24);
    assert(fatorial(5)==120);
    assert(fatorial(6)==720);
    assert(fatorial(13)==6227020800);
    
    printf("OK\n");
    return 0;
}



