#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../headers/animatedsprite.h"


class Graphics;


class Player : public AnimatedSprite {

public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
private:
	virtual void animationDone(std::string animation);
	virtual void setupAnimations();

};


#endif 
