/*
Codificar, dentro da biblioteca pesquisa.c, a seguinte função:

int pesquisa_binaria_r(int vet[], int inicio, int fim, int valor) {
}

Ela busca, usando pesquisa binária recursiva, pelo valor dentro do array vet
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
	
    pos = pesquisa_binaria_r(va, 0, 9, 0);
    assert(pos == 0);

    pos = pesquisa_binaria_r(va, 0, 9, 2);
    assert(pos == 1);

    pos = pesquisa_binaria_r(va, 0, 9, 4);
    assert(pos == 2);

    pos = pesquisa_binaria_r(va, 0, 9, 8);
    assert(pos == 4);

    pos = pesquisa_binaria_r(va, 0, 9, 16);
    assert(pos == 8);

    pos = pesquisa_binaria_r(va, 0, 9, 18);
    assert(pos == 9);

    pos = pesquisa_binaria_r(va, 0, 9, -5);
    assert(pos == -1);

    pos = pesquisa_binaria_r(va, 0, 9, 19);
    assert(pos == -1);

    pos = pesquisa_binaria_r(va, 0, 9, 1);
    assert(pos == -1);

    pos = pesquisa_binaria_r(va, 0, 9, 5);
    assert(pos == -1);

    pos = pesquisa_binaria_r(va, 0, 9, 13);
    assert(pos == -1);
    
    pos = pesquisa_binaria_r(va, 0, 9, 44);
    assert(pos == -1);

    printf("All tests passed!\n");
    return 0;
}
