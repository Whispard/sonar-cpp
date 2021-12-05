#pragma once

#include <vector>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.h"

class Chest {
public:
    explicit Chest(Position pos);

    static std::vector<Chest>
    makeRandom(Config config, RandomGenerator &randomizer);

    int row;
    int col;
    bool found;
    Position pos;
};