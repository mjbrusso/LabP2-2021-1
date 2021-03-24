#include <stdio.h>
#define LIN 2
#define COL 3

int main()
{
  double m[LIN][COL] = {{1.1, 222.2, 33.3}, {44444.4, 5.5, 6.6}};

  for (int i = 0; i < LIN; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      printf("%10.1f ", m[i][j]);
    }
    printf("\n");
  }
  return 0;
}
