#pragma once
#include <SFML/Graphics.hpp>

enum cell_type {
    EMPTY,
    SAND,
    WALL
};

class cell{
public:
    static const int CELL_SIZE = 4;
    
    cell(cell_type type = EMPTY) : type(type), has_been_updated(false){
        set_color_by_type();
    }
    
    virtual ~cell() = default;

    virtual void update(int x, int y, std::vector<std::vector<cell*>> &grid){
        has_been_updated = true;
    }

    void reset_update() { has_been_updated = false; }

    sf::Color get_color() const { return color; }
    cell_type get_type() const { return type; }

protected:
    cell_type type;
    sf::Color color;
    bool has_been_updated;

    void set_color_by_type(){
        switch(type){
            case cell_type::EMPTY: color = sf::Color::Black; break;
            case cell_type::SAND:  color = sf::Color::Yellow; break;
            case cell_type::WALL:  color = sf::Color(128, 128, 128); break;
        }
    }

    void change_type(cell_type  new_type){
        type = new_type;
        set_color_by_type();
    }
};
