#pragma once
#include <string>

enum class CellType {
    Empty,
    Chest,
    Sonar,
    Ranger
};

struct Cell {
    CellType kind;
    int distance;

    void showRange(int d);

    std::string getDrawing(int randomNum);
};

