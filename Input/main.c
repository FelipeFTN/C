#include <stdio.h>

int main() {
  int my_favorite_number = 7;
  int favorite_number;

  printf("Enter your favorite number: ");
  scanf("%d", &favorite_number);
  if (favorite_number == my_favorite_number) {
    printf("Amazing!! That's my favorite number too!\n");
  } else {
    printf("Not really!! %d is my favorite number!\n", my_favorite_number);
  }
  return 0;
}
