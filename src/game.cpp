#include <SDL2/SDL.h>
#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game(){

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    while(true){
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            // Handle key up/down events
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {  // key isn't held down
                    input.keyDownEvent(event);
                }
            }
            else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }

            if (event.type == SDL_QUIT) {
                return;
            }
        }
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
            return;
        }
    }
}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}
