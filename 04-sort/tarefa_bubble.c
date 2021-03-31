/*
Codificar, dentro da biblioteca ordenacao.cpp, a função:

void bubblesort(int vet[], int n);

Ele recebe um vetor de inteiros e o seu tamanho (n).
A função deve ordenar (classificar) o vetor em ordem crescente, usando o método da bolha (Bubble Sort).
Esta função não retorna valor.

Validar sua implementaçao com o programa de teste abaixo.
*/

#include <stdio.h>
#include <assert.h>
#include "ordenacao.c"

int main()
{
    int va[5] = {20, 10, 3, 88, 14};
    bubblesort(va, 5);
    assert(va[0]==3 && va[1]==10 && va[2]==14 && va[3]==20 && va[4]==88);

    int vb[2]  = {-99, -1};
    bubblesort(vb, 2);
    assert(vb[0]==-99 && vb[1]==-1);

    int vc[10]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubblesort(vc, 10);
    assert(vc[0]==1 && vc[1]==2 && vc[2]==3 && vc[3]==4 && vc[4]==5 && vc[5]==6 && vc[6]==7 && vc[7]==8 && vc[8]==9 && vc[9]==10);

    int vd[10]  = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubblesort(vd, 10);
    assert(vd[0]==1 && vd[1]==2 && vd[2]==3 && vd[3]==4 && vd[4]==5 && vd[5]==6 && vd[6]==7 && vd[7]==8 && vd[8]==9 && vd[9]==10);

    int ve[1]  = {18};
    bubblesort(ve, 1);
    assert(ve[0]==18);

    printf("All test passed!\n");
    return 0;
}


