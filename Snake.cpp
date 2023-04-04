// File : Snake.cpp
// Class: COP 2001 Summer B 2022
// Dev  : Jose Suarez
// Desc : Snake implementation
// --------------------------------------------------------

#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "Wall.h"

Snake::Snake() {
    // Spawn the snake in the middle of the window
    int rows = 600 / SNAKE_SIZE;
    int columns = 800 / SNAKE_SIZE;
    int x = columns / 2;
    int y = rows / 2;
    length = 1;
    dir = North;
    body[0].shape = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);
    body[0].shape.setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
    body[0].shape.setPosition(x * SNAKE_SIZE, y * SNAKE_SIZE);
    body[0].shape.setFillColor(sf::Color::Blue);
}

void Snake::draw(fgcu::AnimatedWindow& window) {
    for (int i = 0; i < length; i++) {
        window.addShape(&body[i].shape);
    }
}

void Snake::update(fgcu::AnimatedWindow& window) {
    // Move the body
    for (int i = length - 1; i > 0; i--) {
        body[i].shape.setPosition(body[i - 1].shape.getPosition());
        body[i].shape.setRotation(body[i-1].shape.getRotation());
    }

    // Move the head in the current direction
    switch (dir) {
        case North:
            body[0].shape.move(0, -SNAKE_SIZE);
            body[0].shape.setRotation(North);
            break;
        case South:
            body[0].shape.move(0, SNAKE_SIZE);
            body[0].shape.setRotation(South);
            break;
        case West:
            body[0].shape.move(-SNAKE_SIZE, 0);
            body[0].shape.setRotation(West);
            break;
        case East:
            body[0].shape.move(SNAKE_SIZE, 0);
            body[0].shape.setRotation(East);
            break;
    }

    Wall topWall(0, 0, 800, 5);
    Wall leftWall(0, 0, 5, 600);
    Wall rightWall(795, 0, 5, 600);
    Wall bottomWall(0, 595, 800, 5);

    // Check for collision with walls
    if (topWall.isCollision(*this) || leftWall.isCollision(*this) ||
        rightWall.isCollision(*this) || bottomWall.isCollision(*this)) {
        std::cout << "Snake collided with wall" << std::endl;
        window.close();
    }

    // Check for collision with self
    for (int i = 1; i < length; i++) {
        if (body[0].shape.getGlobalBounds().intersects(body[i].shape.getGlobalBounds())) {
            std::cout << "Snake collided with self" << std::endl;
            window.close();
        }
    }

    // Check for eating food
    if (Food ().isEaten(*this)) {
        std::cout << "Snake ate food" << std::endl;
        length++;
        body[length - 1].shape = body[length - 2].shape;
    }
}


void Snake::handleInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Left:
        case sf::Keyboard::A:
            if (dir != East) {
                dir = West;
            }
            break;
        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            if (dir != West) {
                dir = East;
            }
            break;
        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            if (dir != South) {
                dir = North;
            }
            break;
        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            if (dir != North) {
                dir = South;
            }
            break;
    }
}
