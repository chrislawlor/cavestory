#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../headers/globals.h"
#include "../headers/sprite.h"


class Graphics;
// struct SDL_Rect{};
// struct SDL_Window{};
// struct SDL_Renderer{};

/* AnimatedSprite class
 */

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath,
		int sourceX, int sourceY, int width, int height, float posX,
		float posY, float timeToUpdate);

	/* Play the animation provided if it's not already playing
	 */
	void playAnimation(std::string animation,  bool once = false);

	/* Updates the animated Sprite
	 */
	void update(int elapsedTime);

	/* Draw the sprite to the screen
	 */
	void draw(Graphics &graphics, int x, int y);

	/* A required function that sets up all animations for a sprite
	 */
	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* Adds an animation to the list of animations for the sprite
	 */
	void addAnimation(int frames, int x, int y, std::string name, int width,
		int height, Vector2 offset);

	/* Resets all animations associated with this sprite
	 */
	void resetAnimations();

	/* Stop the current animation
	 */
	void stopAnimation();

	/* Changes the visibility
	 */
	void setVisible(bool visible);

	/* Logic that happens when an animation ends
	 */
	virtual void animationDone(std::string currentAnimation);
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif
