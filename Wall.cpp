// File : Wall.cpp
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Wall implementation
// --------------------------------------------------------

#include "Wall.h"


Wall::Wall(int x, int y, int w, int h) {
    wall = fgcu::AnimatedRectangle(w, h);
    wall.setPosition(x, y);
    wall.setFillColor(sf::Color::White);
}

void Wall::draw(fgcu::AnimatedWindow& window) {
    window.addShape(&wall);
}

bool Wall::isCollision(Snake& snake) {
    if (snake.body[0].shape.getGlobalBounds().intersects(wall.getGlobalBounds())) {
        return true;
    }
    return false;
}
