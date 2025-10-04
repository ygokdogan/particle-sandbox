#pragma once
#include <cstdlib>
#include "cell.h"

class sand_cell : public cell{
public:
    sand_cell();

    void update(int x, int y, std::vector<std::vector<cell*>> &grid) override;
};
