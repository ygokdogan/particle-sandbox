#include "headers/sand_cell.h"

sand_cell::sand_cell() : cell(cell_type::SAND) {}


void sand_cell::update(int x, int y, std::vector<std::vector<cell*>> &grid) {
    int height = grid.size();
    int width = grid[0].size();

    yVelocity += GRAVITY;
    if(yVelocity >= MAX_FALL_SPEED) yVelocity = MAX_FALL_SPEED;

    int fall = static_cast<int>(yVelocity);

    for (int i = 0; i < fall; i++){
        if(y + 1 < height){
            if(grid[y + 1][x]->is_empty() || grid[y + 1][x]->get_type() == cell_type::WATER){
                std::swap(grid[y][x], grid[y + 1][x]);
                y++;
            }
            else{
                bool canLeft = grid[y + 1][x]->is_occupied() && x > 0 && (grid[y + 1][x - 1]->is_empty() || grid[y + 1][x -1]->get_type() == cell_type::WATER);
                bool canRight = grid[y + 1][x]->is_occupied() && x < width - 1 && (grid[y + 1][x + 1]->is_empty() || grid[y+1][x + 1]->get_type() == cell_type::WATER);
                if(canRight && canLeft){
                    if(rand() % 2 == 0){
                        std::swap(grid[y][x], grid[y + 1][x + 1]);
                        y++; x++;
                    }
                    else{
                        std::swap(grid[y][x], grid[y + 1][x - 1]);
                        y++; x--;
                    }
                }
                else if(canRight){
                    std::swap(grid[y][x], grid[y + 1][x + 1]);
                    y++; x++;
                }
                else if(canLeft){
                    std::swap(grid[y][x], grid[y + 1][x - 1]);
                    y++; x--;
                }
                else{
                    yVelocity = 0;
                    break;
                }
            }
        
        }
    }
}