#include <stdbool.h>
#include <stdio.h>

/*
 * returns true if stack is up, false if it's down
 * up is positive
 * down is negative
 */
bool upordown(int *other) {
  int x;

  if (!other) {
    return upordown(&x);
  } else {
    return &x > other;
  }
}

int main() {
  printf("%s\n", upordown(NULL) ? "Up" : "Down");
  return 0;
}
