#ifndef GAME_H
#define GAME_H

/* Game class
 * Holds all information for the main game loop
 */


# include "../headers/sprite.h"

class Graphics;


class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;
};

#endif
