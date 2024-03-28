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
#include "include/structs.h"

int draw_window();

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
bool drawing = false;

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
        SDL_Delay(50);
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

typedef struct {
    float x, y;
} vector2;

// I still have some questions about how this function does what it does
// But in summary, it gets X and Y, and for each value,
// it will always return the same output, based on the input
// Each input will always return the same output, but random in someway.
// This works based on seed and strange calculus I still don't fully understand.
// I want to build my own function like this soon!
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

int procedural_generation(SDL_Renderer* renderer, SDL_Event event) {
    srand(time(NULL));

    // double x = ((double)rand() / RAND_MAX)*100;
    // double y = ((double)rand() / RAND_MAX)*100;
    double x = 100;
    double y = 100;
    double fx = ((double)rand() / RAND_MAX)*100;
    double fy = ((double)rand() / RAND_MAX)*100;

    // Vector2 offset = Vector2(x, y, fx, fy);
    // printf("x: %f; y: %f\n", offset.x, offset.y);
    // printf("fx: %f; fy: %f\n", offset.fx, offset.fy);
    //
    // float slope = (fy - y) / (fx - x);
    // printf("slope: %f\n", slope);

    SDL_SetRenderDrawColor(renderer, 100, 100, 255, 255);
    SDL_RenderDrawLine(renderer, x, y, fx, fy);

    SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
    int i = 0;
    Vector2 pixel = get_pixel_vector(i);
    while (pixel.x != -8.0 && pixel.y != -8.0) {
        pixel = get_pixel_vector(i);
        // TODO: NORMALIZING FUNCTION
        // int dot_color = 100 + (pixel.y * fy) * (pixel.x * fx);
        vector2 gradient = randomGradient(fx, fy);
        printf("Random Gradient: x: %f; y: %f\n", gradient.x, gradient.y);
        int dot_product = ((pixel.x - fx) * gradient.x) + ((pixel.y - fy) * gradient.y);
        SDL_SetRenderDrawColor(renderer, dot_product, dot_product, dot_product, 255);
        SDL_RenderDrawPoint(renderer, pixel.x, pixel.y);
        i += 1;
    }

    return 0;
}
