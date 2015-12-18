/*
 * File:   graphics.h
 * Author: clawlor
 *
 * Created on December 18, 2015, 2:56 PM
 * EDIT
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    /* Loads an image into _spriteSheets map if it doesn't already exist
     * Returns the image from the map
     */
    SDL_Surface* loadImage(const std::string &filePath);

    /* Draws a texture to a certain part of the screen.
     */
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle,
                     SDL_Rect* destinationRectangle);

    /* Renders everything to the screen
     */
    void flip();

    /* Clears the screen
     */
    void clear();

    /* Returns the renderer
     */
    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif	/* GRAPHICS_H */

