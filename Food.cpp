// File : Food.cpp
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Food implementation
// --------------------------------------------------------
#include "Food.h"

Food::Food() {
    food = fgcu::AnimatedCircle(FOOD_SIZE);
    food.setFillColor(sf::Color::Green);
    respawn();
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(food);
}

void Food::respawn() {
    // Generate a random position for the food within the window
    int x = rand() % 26 + 2;
    int y = rand() % 18 + 2;
    food.setPosition(x * 30, y * 30);
}

bool Food::isEaten(Snake& snake) {
    if (snake.body[0].shape.getGlobalBounds().intersects(food.getGlobalBounds())) {
        respawn();
        return true;
    }
    return false;
}

void Food::update(Snake& snake) {
    if (isEaten(snake)) {
        respawn();
    }
}
