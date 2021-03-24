/*
Codificar, dentro da biblioteca pesquisa.c, a seguinte função:

int pesquisa_binaria(int vet[], int n, int valor) {
}

Ela busca, usando pesquisa binária, pelo valor dentro do array vet, de tamanho n
Se encontrou, retorna o índice da ocorrência encontrada
Se não encontrou, retorna -1

Validar sua implementação com o programa de teste abaixo.
*/

#include <stdio.h>
#include <assert.h>
#include "pesquisa.c"

int main()
{
    int pos, va[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};

    pos = pesquisa_binaria(va, 10, 0);
    assert(pos == 0);

    pos = pesquisa_binaria(va, 10, 2);
    assert(pos == 1);

    pos = pesquisa_binaria(va, 10, 4);
    assert(pos == 2);

    pos = pesquisa_binaria(va, 10, 8);
    assert(pos == 4);

    pos = pesquisa_binaria(va, 10, 16);
    assert(pos == 8);

    pos = pesquisa_binaria(va, 10, 18);
    assert(pos == 9);

    pos = pesquisa_binaria(va, 10, -5);
    assert(pos == -1);

    pos = pesquisa_binaria(va, 10, 19);
    assert(pos == -1);

    pos = pesquisa_binaria(va, 10, 1);
    assert(pos == -1);

    pos = pesquisa_binaria(va, 10, 5);
    assert(pos == -1);

    pos = pesquisa_binaria(va, 10, 13);
    assert(pos == -1);
    
    pos = pesquisa_binaria(va, 10, 44);
    assert(pos == -1);

    printf("All tests passed!\n");
    return 0;
}
