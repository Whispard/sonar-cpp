#pragma once

#include <vector>
#include "Position.h"
#include "Config.h"
#include "RandomGenerator.h"
#include "Cell.h"

class Chest: public Cell {
public:
    explicit Chest(Position pos);
    int row;
    int col;
    Position pos;
//    kind = CellType::Chest;
    bool found;
//    Chest(CellType kind,Position pos):
//        kind{kind},
//        pos{pos},
//        row(pos.row),
//        col(pos.col),
//        found(false){}

    static std::vector<Chest> makeRandom(Config config, RandomGenerator& randomizer){
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

    // TODO: Show found and not found chests separately
    ~Chest() override = default;
};