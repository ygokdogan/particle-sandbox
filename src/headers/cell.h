#pragma once
#include <SFML/Graphics.hpp>

const float GRAVITY = 0.3f;
const float MAX_FALL_SPEED = 4;

enum cell_type {
    EMPTY,
    SAND,
    WALL,
    WATER
};

class cell{
public:
    static const int CELL_SIZE = 4;
    
    cell(cell_type type);
    virtual ~cell() = default;
    virtual void update(int x, int y, std::vector<std::vector<cell*>> &grid) {}

    sf::Color get_color() const { return color; }
    cell_type get_type() const { return type; }
    bool is_occupied() const { return get_type() != cell_type::EMPTY; }
    bool is_empty() const { return get_type() == cell_type::EMPTY; }

protected:
    cell_type type;
    sf::Color color;
    float yVelocity;
    int xVelocity = 0;

    void set_color_by_type();
    void change_type(cell_type  new_type);
};
