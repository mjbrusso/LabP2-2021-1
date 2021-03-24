#include <stdio.h>

int main()
{
    int d=5, m=12, a=2021;

    printf("%02d/%02d/%04d\n", d, m, a);

    float preco = 5.25;
    char str[20];

    sprintf(str, "R$ %.2f", preco);
    printf("%15s\n", str);
    return 0;
}
