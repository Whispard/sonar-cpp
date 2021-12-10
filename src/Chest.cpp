#pragma once

#include <vector>
#include <Chest.h>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.h"

Chest::Chest(Position pos) :
        pos{pos},
        row(pos.row),
        col(pos.col),
        found(false) {}


// factory making random list of chests
std::vector<Chest>
Chest::makeRandom(Config config, RandomGenerator& randomizer) {
    // TODO: Use fp for shorter method
    auto result = std::vector<Chest>();
    Position::setLimits(config);
    for (int chestsPlaced = 0; chestsPlaced < config.totalChests; ++chestsPlaced) {
        auto newPos = Position{
                randomizer.below(config.rows),
                randomizer.below(config.cols)
        };
        auto newChest = Chest(newPos);
        // TODO: Handle when chest already exists
        result.push_back(newChest);
    }
    return result;
}