#pragma once

#include <vector>
#include <stdexcept>
#include "Position.h"
#include "Chest.h"

class Sonar {
public:
    explicit Sonar(Position pos);

    int distFromNearestChest(const std::vector<Chest> &chests);

    int row;
    int col;
    Position pos;
};