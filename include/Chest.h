#pragma once

#include <vector>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.h"
#include "Cell.h"

class Chest: public Cell {
public:
    explicit Chest(Position pos);
    Chest(CellType kind,Position pos):
        kind{kind},
        pos{pos},
        row(pos.row),
        col(pos.col),
        found(false){}

        CellType kind;
    static std::vector<Chest>
    makeRandom(Config config, RandomGenerator& randomizer);

    int row;
    int col;
    // TODO: Show found and not found chests separately
    bool found;
    Position pos;
};