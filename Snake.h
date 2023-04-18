// File : Snake.h
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Snake declaration
// --------------------------------------------------------

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H


#pragma once

#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedCircle.h>
#include "Wall.h"

class Wall;

class Snake {
public:
    struct Body {
        int width;
        int height;
        int x;
        int y;
        fgcu::AnimatedRectangle shape;
    };

    static const int MAX_LENGTH = 25;
    static const int SNAKE_SIZE = 30;

    Snake();
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow&  window);
    void handleInput(sf::Keyboard::Key key);
    bool isEating(fgcu::AnimatedCircle food);

    Body body[MAX_LENGTH];
private:

    enum Direction {
        North = 0,
        South = 180,
        West = 90,
        East = 270,
    };

    Direction dir;
    int length;

    void checkCollisions(sf::RenderWindow& window);


};


#endif //SNAKEGAME_SNAKE_H
