#include <cmath>
#include <iostream>
#include <ostream>

typedef struct {
    float x, y;
} vector2;

vector2 randomGradient(int ix, int iy);

int main( void ) {
    vector2 random = randomGradient(10, 20);
    std::cout << random.x << std::endl;
}

vector2 randomGradient(int ix, int iy) {
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2; // rotation width
    unsigned a = ix, b = iy;
    a *= 3284157443; b ^= a << s | a >> (w-s);
    b *= 1911520717; a ^= b << s | b >> (w-s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]
    vector2 v;
    v.x = cos(random); v.y = sin(random);
    return v;
}
