#include "raylib.h"

int main() {

  const int screenWidth = 800;
  const int screenHeigt = 450;

  InitWindow(screenWidth, screenHeigt, "Game");

  SetTargetFPS(60);

  while(!WindowShouldClose()) {

    BeginDrawing();

    DrawText("MyGame!", 350, 200, 20, LIGHTGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
