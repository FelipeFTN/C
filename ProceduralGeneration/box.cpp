#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include "include/structs.h"

const SDL_Rect BOX_RECT = {100, 100, 320, 240};

int draw_box(SDL_Renderer* renderer, SDL_Event event) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderDrawRect(renderer, &BOX_RECT);

    return 0;
}

Vector2 get_pixel_vector(int index) {
    const int box_x = BOX_RECT.x + 0;
    const int box_y = BOX_RECT.y + 1;
    const int box_w = BOX_RECT.w - 1;
    const int box_h = BOX_RECT.h - 1;

    if (index <= box_w)
        return Vector2(box_x + index, box_y);

    int row = 0;
    while (index > box_w) {
        if (row == box_h)
            return Vector2(-8.0, -8.0);

        index = index - box_w;
        row += 1;
    }
    

    return Vector2(box_x + index, box_y + row);
}
