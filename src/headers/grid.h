#include <vector>
#include "cell.h"
#include "SFML/Graphics.hpp"

class grid
{
    public:
    int width, height, cell_size;
    std::vector<std::vector<cell*>> cells;

    grid(int w, int h, int cs) : width(w), height(h), cell_size(cs){
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

    void draw(sf::RenderWindow& window){
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                sf::RectangleShape rect(sf::Vector2f(cell_size, cell_size));
                rect.setPosition(sf::Vector2f(x * cell_size, y * cell_size));
                rect.setFillColor(cells[y][x]->get_color());
                window.draw(rect);
            }
        }

    }

    void set_cell(int x, int y, cell* new_cell){
        delete cells[y][x];
        cells[y][x] = new_cell;
    }
};
