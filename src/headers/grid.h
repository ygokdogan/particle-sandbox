#include <vector>
#include "cell.h"

class grid
{
    public:
    int width, height;
    std::vector<std::vector<cell*>> cells;

    grid(int w, int h) : width(w), height(h){
        cells.resize(height, std::vector<cell*>(width, nullptr));
        for(int y = 0; y < height; ++y){
            for (int x = 0; x < width; ++x){
                cells[y][x] = new cell(cell_type::EMPTY);
            }
        }
    }

    ~grid() {
        for (auto &row : cells)
            for (auto &cell : row)
                delete cell;
    }

    void reset_updates() {
        for (auto &row : cells)
            for (auto &cell : row)
                cell->reset_update();
    }

    void update_all(){
        for (int y = height - 1; y >= 0; --y){
            for (int x = 0; x < width; ++x){
                cells[y][x]->update(x, y, cells);
            }
        }
    }

    void set_cell(int x, int y, cell* new_cell){
        delete cells[y][x];
        cells[y][x] = new_cell;
    }
};
