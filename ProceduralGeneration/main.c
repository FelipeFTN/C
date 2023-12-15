#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
  printf("\033[H\033[J"); // Clear prompt
  srand(time(NULL));      // Initialization, should only be called once.
  double r = (double)rand() / RAND_MAX; // Number between 0 and 1

  int number = 0;
  char block = '0';

  while (1 == 1) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 50; j++) {
        if (number <= 5 && r < 0.4) {
          block = '-';
          number++;
        } else {
          r = (double)rand() / RAND_MAX;
          block = r < 0.6 ? '-' : '#';
          number = 0;
        }
        printf("%c", block);
      }
      printf("\n");
    }
    sleep(1);
    printf("\033[H\033[J");
  }

  return 0;
}
