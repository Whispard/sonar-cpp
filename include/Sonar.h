#pragma once

#include <vector>
#include <stdexcept>
#include "Position.h"
#include "Chest.h"

class Sonar: public Cell {
public:
    int row;
    int col;
    Position pos;
    int distance = 0;
    std::vector<Position> sonars{};
    CellType kind = CellType::Sonar;
    explicit Sonar(Position pos);
    [[nodiscard]] int distFromNearestChest(const std::vector<Chest> &chests) const;
    ~Sonar() override = default;
};