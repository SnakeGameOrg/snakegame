//
// Created by Jose Suarez on 4/3/23.
//

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
