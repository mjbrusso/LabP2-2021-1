#include <stdio.h>

float maior(float n1, float n2)
{
    if (n1 > n2)
    {
        return n1;
    }

    return n2;
}

int main()
{
    float a, b, m;

    printf("Input 2 values: ");
    scanf("%f %f", &a, &b);
    m = maior(a, b);
    printf("Max: %.2f\n", m);
    return 0;
}
