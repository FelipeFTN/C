#ifndef BOX_h
#define BOX_h
#include <SDL2/SDL.h>
#include "structs.h"

int draw_box(SDL_Renderer* renderer, SDL_Event event);

Vector2 get_pixel_vector(int index);

#endif // !BOX_h
