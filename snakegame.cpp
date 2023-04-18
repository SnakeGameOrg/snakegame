//  file: snakegame.cpp
//  Author: Jose Suarez
//  Class: COP 2001 Summer B 2022
//  Purpose: make a snake game where food randomly spawns and
//           the snake eats the food to grow larger.
// ---------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedCircle.h>

#include "Snake.h"
#include "Food.h"
#include "Wall.h"

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    window.setFramerateLimit(60);

    Snake snake;
    Wall topWall(0, 0, 800, 5);
    Wall leftWall(0, 0, 5, 600);
    Wall rightWall(795, 0, 5, 600);
    Wall bottomWall(0, 595, 800, 5);
    Food food;

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                snake.handleInput(event.key.code);
            }
        }

        // Clear the window
        window.clear();

        // Update game logic
        
        food.update(snake); // Add an update function for the food object and pass the snake object to it

        // Draw game objects
        snake.draw(window);
        topWall.draw(window);
        leftWall.draw(window);
        rightWall.draw(window);
        bottomWall.draw(window);
        food.draw(window);

        // Display the window
        window.display();
    }

    return 0;
}
