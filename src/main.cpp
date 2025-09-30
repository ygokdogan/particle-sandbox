#include <stdio.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "headers/cell.h"
#include "headers/sand_cell.h"
#include "headers/grid.h"

const int WIDTH = 800;
const int HEIGHT = 600;

const int CELL_SIZE = 4;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "SFML window");

    grid grid(GRID_WIDTH, GRID_HEIGHT);

    grid.set_cell(100, 32, new sand_cell());
    grid.set_cell(100, 34, new sand_cell());
    grid.set_cell(100, 36, new sand_cell());
    grid.set_cell(100, 38, new sand_cell());
    grid.set_cell(100, 40, new sand_cell());
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

        for (int y = 0; y < GRID_HEIGHT; ++y) {
            for (int x = 0; x < GRID_WIDTH; ++x) {
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