#pragma once

#include <vector>
#include <iostream>

#include "Config.h"
#include "RandomGenerator.h"
#include "Sonar.h"
#include "Chest.h"
#include "Cell.h"
#include "screen.h"

// this should have been another way around but change that later
using Display = std::vector<std::vector<std::unique_ptr<Cell>>>;

class Board {
public:
    explicit Board(Config config, RandomGenerator& randomizer, Screen& screen);

    void markRanger(int x, int y, int d);

    void display(Position pos);

    void markRangers();

    bool placeAt(Position pos);

    std::unique_ptr<Cell>& getCell(Position pos);

    Display board;
private:
    RandomGenerator& randomGenerator;
    Screen& screen;

    bool checkOutOfBounds(int x, int y);
};
