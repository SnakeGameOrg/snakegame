// File : Food.h
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Food declaration
// --------------------------------------------------------

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H


#include <Eagles/AnimatedCircle.h>
#include "Snake.h"

class Food {
public:
    Food();
    void draw(fgcu::AnimatedWindow& window);
    void respawn();
    bool isEaten(Snake& snake);

private:
    static const int FOOD_SIZE = 20;

    fgcu::AnimatedCircle food;
};

#endif //SNAKEGAME_FOOD_H
