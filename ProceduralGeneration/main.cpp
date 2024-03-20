#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL.h>

#include "include/box.h"

int draw_window();

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool drawing = false;

// Box
const int BOX_WIDTH = 320;
const int BOX_HEIGHT = 240;

struct Vector2 {
  Vector2(float x, float y, float fx, float fy) : x(x), y(y), fx(fx), fy(fy) {}
  float x;
  float y;
  float fx;
  float fy;
};

int procedural_generation(SDL_Renderer* renderer, SDL_Event event);

int main() { 
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("ProceduralGeneration", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Error: Window could not be initialized! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    bool quit = false;
    SDL_Event event;
    while (quit == false) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) quit = true;

        SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
        SDL_RenderClear(renderer);

        draw_box(renderer, event);

        procedural_generation(renderer, event);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int procedural_generation(SDL_Renderer* renderer, SDL_Event event) {
    srand(time(NULL));

    // double x = ((double)rand() / RAND_MAX)*100;
    // double y = ((double)rand() / RAND_MAX)*100;
    double x = 50;
    double y = 50;
    double fx = ((double)rand() / RAND_MAX)*100;
    double fy = ((double)rand() / RAND_MAX)*100;

    Vector2 offset = Vector2(x, y, fx, fy);
    printf("x: %f; y: %f\n", offset.x, offset.y);
    printf("fx: %f; fy: %f\n", offset.fx, offset.fy);

    float slope = (fy - y) / (fx - x);
    printf("slope: %f\n", slope);

    SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
    // SDL_RenderDrawLine(renderer, 100, 100, 200, 200);

    SDL_RenderDrawLine(renderer, x, y, fx, fy);

    return 0;
}
