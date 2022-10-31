#include <iostream>

#include "handler.h"


std::string authUsername = "";

void hello() {
    std::cout << "MySecurity!";
}

void registerUser(std::string username) {
    std::cout << "\nPlease, insert your username: "; std::cin >> username;
    authUsername = username;
}

bool login(std::string username) {
    if (username != authUsername) { return false; }
    return true;
}