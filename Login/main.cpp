#include <iostream>

#include "handler.h"

int main() {
    std::string username;

    hello();
    registerUser(username);

    std::cout << "\nWhat is your login? "; std::cin >> username;
    if (!login(username)) { std::cout << "Wrong auth!"; return 0; }

    std::cout << "Right Auth!";
    return 0;
}