#include <stdio.h>
#include <stdlib.h> // for qsort()

int compara(const void *a, const void *b) {
  float *pa = (float *)a;
  float *pb = (float *)b;

  if (*pa == *pb)
    return 0;
  else if (*pa > *pb)
    return 1;

  return -1;
}

int comparad(const void *a, const void *b) {
  float *pa = (float *)a;
  float *pb = (float *)b;

  if (*pa == *pb)
    return 0;
  else if (*pa < *pb)
    return 1;

  return -1;
}

int main() {
  float vet[5] = {23.3, 99.1, 66.6, 0.5, 40.7};

  qsort(vet, 5, sizeof(vet[0]), comparad);
  for (int i = 0; i < 5; i++)
    printf("%.1f\n", vet[i]);

  return 0;
}
