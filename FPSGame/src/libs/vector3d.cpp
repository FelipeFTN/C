#include "vector3d.h"

vector3d::vector3d() {
    x = y = z = 0;
}

vector3d::vector3d(float a, float b) {
    x = a;
    y = b;
    z = 0;
}

vector3d::vector3d(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

float vector3d::dotProduct(const vector3d& vec2) {
    return (x*vec2.x+y*vec2.y+z*vec2.z);
}

vector3d vector3d::crossProduct(const vector3d& vec2) {
    return vector3d();
}

float vector3d::length() {
    return sqrt(x*x+y*y+z*z);
}

void vector3d::normalize() {
    float len=length();
    if (len != 0) {
        x /= len;
        y /= len;
        z /= len;
    }
}

void vector3d::change(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

void vector3d::change(vector3d vec2) {
    x = vec2.x;
    y = vec2.y;
    z = vec2.z;
}

void vector3d::changeX(float a) { x = a; }
void vector3d::changeY(float a) { y = a; }
void vector3d::changeZ(float a) { z = a; }

vector3d vector3d::operator+(const vector3d& vec2) {
    return vector3d(x+vec2.x, y+vec2.y, z+vec2.z);
}

vector3d vector3d::operator-(const vector3d& vec2) {
    return vector3d(x-vec2.x, y-vec2.y, z-vec2.z);
}

vector3d vector3d::operator*(float n) {
    return vector3d(x*n, y*n, z*n);
}

vector3d vector3d::operator/(float n) {
    if (n == 0)
        return vector3d();
    return vector3d(x/n, y/n, z/n);
}

vector3d vector3d::operator+=(const vector3d& vec2) {
    x += vec2.x;
    y += vec2.y;
    z += vec2.z;
    return *this;
}

vector3d vector3d::operator-=(const vector3d& vec2) {
    x -= vec2.x;
    y -= vec2.y;
    z -= vec2.z;
    return *this;
}

vector3d vector3d::operator*=(float n) {
    x *= n;
    y *= n;
    z *= n;
    return *this;
}
vector3d vector3d::operator/=(float n) {
    if (n == 0) return *this;

    x /= n;
    y /= n;
    z /= n;
    return *this;

}

bool vector3d::operator==(const vector3d vec2) {
    return (x==vec2.x && y==vec2.y && z==vec2.z);

}

bool vector3d::operator!=(const vector3d vec2) {
    return !(*this==vec2);
}

std::ostream& operator<<(std::ostream& out, const vector3d& vec) {
    return out << vec.x << " " << vec.y << " " << vec.z << std::endl;
}
