#include "headers/cell.h"

cell::cell(cell_type type) : type(type) {
    set_color_by_type();
}


void cell::set_color_by_type(){
    switch(type){
        case cell_type::EMPTY: color = sf::Color::Black; break;
        case cell_type::SAND:  color = sf::Color::Yellow; break;
        case cell_type::WALL:  color = sf::Color(128, 128, 128); break;
        case cell_type::WATER: color = sf::Color::Cyan; break;
    }
}

void cell::change_type(cell_type  new_type){
    type = new_type;
    set_color_by_type();
}