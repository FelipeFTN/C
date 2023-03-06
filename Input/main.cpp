#include <iostream>

int main() {
  int my_favorite_number = 7;
  int favorite_number;

  std::cout << "Enter your favorite number between 1 and 100: ";
  std::cin >> favorite_number;
  if (favorite_number == my_favorite_number) {
    std::cout << "Amazing!! That's my favorite number too!" << std::endl;
  } else {
    std::cout << "Not really!! " << my_favorite_number << " is my favorite number!" << std::endl;
  }
  return 0;
}
