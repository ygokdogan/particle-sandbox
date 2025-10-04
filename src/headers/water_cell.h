#pragma once

#include "cell.h"

class water_cell : public cell
{
public:
    int flow_dir = 0;
    water_cell();

    void update(int x, int y, std::vector<std::vector<cell*>>& grid) override;

};