#include <stdio.h>
#include <stdlib.h>

int main() {
  int generation_limit = 10;
  char grass = '-';
  char dirt = '0';
  char gold = '1';

  const int N = 3, M = 4;

  int **m = (int **) calloc(N, sizeof(int *));
  for (int i = 0; i < N; i++) {
    m[i] = (int *)calloc(M, sizeof(int));
  }

  /* for (int i = 0; i < sizeof(m[0]); i++) { */
  /* } */
  printf("%d", m[0][0]);
  printf("%lu", sizeof(m));

  free(m);
}
