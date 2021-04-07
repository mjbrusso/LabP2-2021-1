
void bubblesort(int vet[], int n)
{
    int trocou;
    do
    {
        trocou = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;

                trocou = 1;
            }
        }
        n--;
    } while (trocou);
}

void selectionsort(int vet[], int n)
{
    while (n > 1)
    {
        int posm = 0;
        for (int i = 1; i < n; i++)
        {
            if (vet[i] > vet[posm])
                posm = i;
        }
        n--;
        if (posm != n)
        {
            int aux = vet[posm];
            vet[posm] = vet[n];
            vet[n] = aux;
        }
    }
}

void insertionsort(int vet[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int aux = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > aux)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}
