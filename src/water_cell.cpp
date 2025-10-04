#include "headers/water_cell.h"

water_cell::water_cell() : cell(cell_type::WATER) { }

void water_cell::update(int x, int y, std::vector<std::vector<cell*>>& grid){
    int height = grid.size();
    int width = grid[0].size();

    yVelocity += GRAVITY;
    if(yVelocity >= MAX_FALL_SPEED) yVelocity = MAX_FALL_SPEED;

    int fall = static_cast<int>(yVelocity);
    
    xVelocity = 0;
    
    for (int i = 0; i < fall; i++){
        if(y + 1 < height){
            cell* cellBelow = grid[y + 1][x];

            if(cellBelow->is_empty()){
                std::swap(grid[y][x], grid[y + 1][x]);
                y++;
            }
            else{
                bool canLeft = cellBelow->is_occupied() && x > 0 && grid[y + 1][x - 1]->is_empty();
                bool canRight = cellBelow->is_occupied() && x < width - 1 && grid[y + 1][x + 1]->is_empty();


                bool canSpreadLeft = !canLeft && x > 0 && grid[y][x - 1]->is_empty();
                bool canSpreadRight = !canRight && x < width - 1 && grid[y][x + 1]-> is_empty();

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
                else if(canSpreadLeft || canSpreadRight){
                    if(canSpreadLeft && canSpreadRight){
                        if(flow_dir == 0){
                            flow_dir = rand() % 2 == 0 ? 1 : -1;
                        }
    
                        if(flow_dir > 0){
                            std::swap(grid[y][x], grid[y][x + 1]);
                            x++;
                            xVelocity--;
                        }
                        else{
                            std::swap(grid[y][x], grid[y][x - 1]);
                            x--;
                            xVelocity--;
                        }
                    }
                    else if(canSpreadLeft){
                        std::swap(grid[y][x], grid[y][x - 1]);
                        x--;
                        xVelocity--;
                    }
                    else if(canSpreadRight){
                        std::swap(grid[y][x], grid[y][x + 1]);
                        x++;
                        xVelocity--;
                    }
                }
                else{
                    yVelocity = 0;
                    xVelocity = 0;
                    flow_dir = 0;
                    break;
                }
            }
        
        }
    }
}