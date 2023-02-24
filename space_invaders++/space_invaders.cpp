#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "space_invaders.hpp"

/* 
RUN:

g++ -std=c++11 space_invaders.cpp space_invaders.hpp space_invaders_classes.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include 
-L/opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -lsfml-system -lsfml-window -lsfml-graphics      

 */


int main()
{
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    // SETUP
    //-background

    sf::Texture background;
    background.loadFromFile("/Users/llekcevic/Downloads/space.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background);
    background_sprite.setScale(0.5, 0.5);

    Ship ship(&window);
    Enemy enemy;

    // GAME ENGINE LOOP

    // The main loop - ends as soon as the window is closed
    while (window.isOpen())
    {
        // FRAME CALCULATION

        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Right)
                {
                    ship.isMovingRight = true;
                }
                else if (event.key.code == sf::Keyboard::Key::Left)
                {
                    ship.isMovingLeft = true;
                }
                else if (event.key.code == sf::Keyboard::Key::Space)
                {
                    //laser.isShooting = true;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Key::Right)
                {
                    ship.isMovingRight = false;
                }
                else if (event.key.code == sf::Keyboard::Key::Left)
                {
                    ship.isMovingLeft = false;
                }
            }
        }
        // Activate the window for OpenGL rendering
        window.setActive();

        enemy.move(&window);

        ship.moveShip(&window);

        // DRAW
        window.clear();
        window.draw(background_sprite);
       // window.draw(laser.laser_sprite);
        window.draw(ship.ship_sprite);
        window.draw(enemy.enemy_sprite);

        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}

