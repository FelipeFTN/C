#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

const SDL_Rect BOX_RECT = {50, 50, 100, 100};

int draw_box(SDL_Renderer* renderer, SDL_Event event) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderDrawRect(renderer, &BOX_RECT);

    return 0;
}
