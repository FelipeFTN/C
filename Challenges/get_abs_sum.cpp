#include <iostream>
#include <vector>

int get_abs_sum(std::vector<int> arr) {
  int sum = 0;
  for (int num : arr) {
    if (num < 0) { num *= -1; }
    sum += num;
  }
  return sum;
}

int main() {
  return get_abs_sum({0, -5, 5, 10});
}
