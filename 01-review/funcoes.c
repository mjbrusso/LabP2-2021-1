float mediavetf(float vet[], int n)
{
    float s = 0.0;

    for (int i = 0; i < n; i++)
        s += vet[i];

    return s / n;
}

float maiorf(float a, float b)
{
    if(a>b) return a;
    else    return b;
}
