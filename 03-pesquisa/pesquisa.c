int pesquisa_sequencial(int vet[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

// pesquisa sequencial em array ordenado
int pesquisa_sequencial_ord(int vet[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == valor)
            return i;

        if (vet[i] > valor)
            return -1;
    }
    return -1;
}

int pesquisa_binaria(int vet[], int n, int valor)
{
    // Versão Gabriel Tibola Castagnera
    int inicio = 0;
    int fim = n - 1;
    int meio = (inicio + fim) / 2;

    while (vet[meio] != valor)
    {
        if (inicio == fim)
            return -1;

        if (vet[meio] > valor)
            fim = meio - 1;
        else
            inicio = meio + 1;

        meio = (inicio + fim) / 2;
    }
    return meio;

    // Versão Eoil
    // int inicio = 0, fim = n, meio;
    // while (inicio <= fim)
    // {
    //     meio = (inicio + fim) / 2;

    //     if (vet[meio] == valor)
    //         return meio;

    //     if (inicio == fim)
    //         return -1;

    //     if (vet[meio] < valor)
    //         inicio = meio + 1;

    //     if (vet[meio] > valor)
    //         fim = meio - 1;
    // }
    // return -1;
}


int pesquisa_binaria_r(int vet[], int inicio, int fim, int valor)
{
    int meio = (inicio + fim) / 2;
    
    if(vet[meio]==valor) return meio;
    
    if(inicio==fim) return -1;

    if(vet[meio]>valor) return pesquisa_binaria_r(vet, inicio, meio-1, valor);

    return pesquisa_binaria_r(vet, meio+1, fim, valor);
}
