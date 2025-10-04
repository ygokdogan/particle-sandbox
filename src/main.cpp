#include <stdio.h>
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "headers/grid.h"
#include "headers/cell.h"
#include "headers/sand_cell.h"
#include "headers/water_cell.h"

const int WIDTH = 800;
const int HEIGHT = 600;

const int CELL_SIZE = 5;
const int GRID_WIDTH = WIDTH / CELL_SIZE;
const int GRID_HEIGHT = HEIGHT / CELL_SIZE;

cell_type currentType = cell_type::SAND;

sf::Vector2f get_mouse_pos(sf::RenderWindow& window){
    sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
    sf::Vector2f world_pos = window.mapPixelToCoords(pixel_pos);
    return world_pos;
}

void spawn_cell(grid& grid, sf::RenderWindow& window, cell* new_cell){
    sf::Vector2f pos = get_mouse_pos(window);
    int gx = static_cast<int>(pos.x) / CELL_SIZE;
    int gy = static_cast<int>(pos.y) / CELL_SIZE;

    if(gx >= 0 && gx < GRID_WIDTH && gy >= 0 && gy <= GRID_HEIGHT){
        if(grid.cells[gy][gx]->get_type() == cell_type::EMPTY){
            grid.set_cell(gx, gy, new_cell);
        }
    }

}


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Particle Sandbox");

    grid grid(GRID_WIDTH, GRID_HEIGHT, CELL_SIZE);
    
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
         
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            switch (currentType)
            {
                case cell_type::SAND:
                    spawn_cell(grid, window, new sand_cell());
                    break;
                case cell_type::WATER:
                    spawn_cell(grid, window, new water_cell());
                    break;
                default:
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Num1)){
            currentType = cell_type::SAND;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Num2)){
            currentType = cell_type::WATER;
        }
        
        // Clear screen
        window.clear();
        
        grid.update_all();
        grid.draw(window);
        
        // Update the window
        window.display();
    }
}