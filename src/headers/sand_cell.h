#pragma once
#include "cell.h"

class sand_cell : public cell{
public:
    sand_cell() : cell(cell_type::SAND){}

    void update(int x, int y, std::vector<std::vector<cell*>> &grid) override {
        if(has_been_updated) return;
        has_been_updated = true;

        int height = grid.size();
        int width = grid[0].size();

        yVelocity += GRAVITY;
        if(yVelocity >= MAX_FALL_SPEED) yVelocity = MAX_FALL_SPEED;

        int fall = static_cast<int>(yVelocity);

        for (int i = 0; i < fall; i++){
            if(y + 1 < height){
                if(grid[y + 1][x]->get_type() == cell_type::EMPTY){
                    std::swap(grid[y][x], grid[y + 1][x]);
                    y += 1;
                }
                else if(grid[y + 1][x]->get_type() == !cell_type::EMPTY && grid[y + 1][x - 1]->get_type() == cell_type::EMPTY){
                    std::swap(grid[y][x], grid[y + 1][x - 1]);
                    y += 1;
                    x -= 1;
                }
                else if(grid[y + 1][x]->get_type() == !cell_type::EMPTY && grid[y + 1][x + 1]->get_type() == cell_type::EMPTY){
                    std::swap(grid[y][x], grid[y + 1][x + 1]);
                    y += 1;
                    x += 1;
                }
            }
        }

    }
};
