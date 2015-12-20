#ifndef PLAYER_H
#define PLAYER_H

#include "../headers/animatedsprite.h"
#include "../headers/globals.h"


class Graphics;


class Player : public AnimatedSprite {

public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/* Moves the player left by _dx 
	 */
	void moveLeft();

	/* Moves the player right by negative _dx 
	 */
	void moveRight();

	/* Stops moving the player 
	 */
	void stopMoving();
private:
	virtual void animationDone(std::string animation);
	virtual void setupAnimations();
	float _dx, _dy;
	Direction _facing;
};


#endif 
