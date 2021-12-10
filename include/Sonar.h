#pragma once

#include <vector>
#include <stdexcept>
#include "Position.h"
#include "Chest.h"

class Sonar: public Cell {
public:
    explicit Sonar(Position pos);

    int distFromNearestChest(const std::vector<Chest> &chests) const;

    int row;
    int col;
    Position pos;
    ~Sonar() override = default;
};