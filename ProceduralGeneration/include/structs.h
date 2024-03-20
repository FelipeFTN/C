#ifndef STRUCTS_H
#define STRUCTS_H

struct Vector2 {
  Vector2(float x, float y, float fx=0, float fy=0) : x(x), y(y), fx(fx), fy(fy) {}
  float x;
  float y;
  float fx;
  float fy;
};

#endif
