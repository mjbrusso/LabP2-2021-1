float mediavetf(float vet[], int n)
{
    float s = 0.0;

    for (int i = 0; i < n; i++)
        s += vet[i];

    return s / n;
}

float maiorf(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}

// versão iterativa
// long long fatorial(int n){
//     long long fat = 1;

//     for(int i=2; i<=n; i++){
//         fat *= i;
//     }

//     return fat;
// }

// versão recursiva
long long fatorial(int n)
{
    if (n == 0)
        return 1;
    else
        return fatorial(n - 1) * n;
}
