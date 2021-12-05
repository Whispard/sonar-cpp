#pragma once

#include "Config.h"
#include "RandomGenerator.h"
#include "Sonar.h"
#include "Chest.h"
#include "Cell.h"
#include <vector>
#include <iostream>

using Display = std::vector<std::vector<Cell>>;

class Board {
public:
    explicit Board(Config config, RandomGenerator randomizer);

    void markRanger(int x, int y, int d);

    void display();

    void markRangers();

    bool placeAt(Position pos);

    Cell &getCell(Position pos);

private:
    Display board;
    std::vector<Chest> chests;
    std::vector<Sonar> sonars;
    RandomGenerator randomGenerator;

    bool checkOutOfBounds(int x, int y);
};

