#pragma once

#include <iostream>

enum class CellType {
    Empty,
    Empty2,
    Chest,
    Sonar,
    Ranger
};

// Cell Kind & Display
struct Cell {
    Cell() = default;
    explicit Cell(CellType kind):kind{kind}{};
    CellType kind = CellType::Empty;
    // TODO: Decouple this distance filed from here
    int distance = 0;


    void showRange(int d) ;

    std::string getDrawing(int randomNum) const;
    virtual ~Cell()= default;;
};

class Cell2:Cell{};

