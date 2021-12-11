#pragma once

#include <vector>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.h"
#include "Cell.h"

class Chest: public Cell {
public:
    explicit Chest(Position pos,EmptyType emp);
    int row;
    int col;
    Position pos;
    EmptyType emp;

    // TODO: Show found and not found chests separately
    ~Chest() override = default;
};