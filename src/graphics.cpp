#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "../headers/graphics.h"
#include "../headers/globals.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT,
                                0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}


SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if (this->_spriteSheets.count(filePath) == 0) {
        SDL_Surface* surface = IMG_Load(filePath.c_str());
        if (!surface) {
            printf("IMG_Load Error: %s", IMG_GetError());
        }
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _spriteSheets[filePath];
}


void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle,
                           SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}
