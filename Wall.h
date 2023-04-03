//
// Created by Jose Suarez on 4/3/23.
//

#ifndef SNAKEGAME_WALL_H
#define SNAKEGAME_WALL_H

#include <Eagles/AnimatedRectangle.h>
#include "Snake.h"

class Snake;

class Wall {
public:
    Wall(int x, int y, int w, int h);
    void draw(fgcu::AnimatedWindow& window);
    bool isCollision(Snake & snake);

private:
    fgcu::AnimatedRectangle wall;
};

#endif //SNAKEGAME_WALL_H
