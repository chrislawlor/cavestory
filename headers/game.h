#ifndef GAME_H
#define GAME_H

/* Game class
 * Holds all information for the main game loop
 */

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
};

#endif
