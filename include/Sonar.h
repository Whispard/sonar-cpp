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
    CellType kind = CellType::Sonar;
    explicit Sonar(Position pos);
    static void updateAll(const std::vector<std::unique_ptr<Chest>>& chests);
    [[nodiscard]] int distFromNearestChest(const std::vector<std::unique_ptr<Chest>> &chests) const;
    ~Sonar() override = default;
};