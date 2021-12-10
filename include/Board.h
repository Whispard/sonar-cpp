#pragma once

#include "Config.h"
#include "RandomGenerator.h"
#include "Sonar.h"
#include "Chest.h"
#include "Cell.h"
#include <vector>
#include <iostream>
#include "screen.h"

using Display = std::vector<std::vector<Cell>>;

class Board {
public:
    explicit Board(Config config, RandomGenerator& randomizer, Screen& screen);

    void markRanger(int x, int y, int d);

    void display(Position pos);

    void markRangers();

    bool placeAt(Position pos);

    Cell &getCell(Position pos);

    Display board;
private:
    std::vector<Chest> chests;
    std::vector<Sonar> sonars;
    RandomGenerator& randomGenerator;
    Screen& screen;

    bool checkOutOfBounds(int x, int y);
};

