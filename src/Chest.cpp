#pragma once

#include <vector>
#include <Chest.h>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.cpp"

Chest::Chest(Position pos) :
        pos{pos},
        row(pos.row),
        col(pos.col),
        found(false) {}


// factory making random list of chests
std::vector<Chest>
Chest::makeRandom(Config config, RandomGenerator &randomizer) {
    auto result = std::vector<Chest>();
    for (int chestsPlaced = 0; chestsPlaced < config.totalChests; ++chestsPlaced) {
        auto newChest = Chest(Position{
                randomizer.below(config.rows),
                randomizer.below(config.cols)
        });
        // TODO: Handle when chest already exists
        result.push_back(newChest);
    }
    return result;
}

int row;
int col;
bool found;
Position pos;