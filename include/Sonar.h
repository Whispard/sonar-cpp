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
    inline static std::vector<std::unique_ptr<Sonar>> sonars{};
    explicit Sonar(Position pos);
    static void updateAll(const std::vector<Position>& chests);
    [[nodiscard]] int distFromNearestChest(const std::vector<Position> &chests) const;
    ~Sonar() override = default;
};