
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
    
}

void insertionsort(int vet[], int n)
{

}