#pragma once

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

    void getDrawing(int randomNum);
};

