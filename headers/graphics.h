/*
 * File:   graphics.h
 * Author: clawlor
 *
 * Created on December 18, 2015, 2:56 PM
 * EDIT
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif	/* GRAPHICS_H */

