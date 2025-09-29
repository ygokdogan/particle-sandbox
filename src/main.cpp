#include <stdio.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "cell.h"
#include "sand_cell.h"
#include "grid.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 4;


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SFML window");

    grid grid(WIDTH, HEIGHT);

    grid.set_cell(100, 30, new sand_cell());
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        grid.reset_updates();
        grid.update_all();
        
        // Clear screen
        window.clear();

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                sf::RectangleShape rect(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                rect.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
                rect.setFillColor(grid.cells[y][x]->get_color());

                window.draw(rect);
            }
        }

        // Update the window
        window.display();
    }
}