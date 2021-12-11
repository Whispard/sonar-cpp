#pragma once

#include <iostream>

enum class CellType {
    Empty,
    Chest,
    Sonar,
    Ranger
};

// this decouples empty from complicated one
enum class EmptyType{
    E,
    F
};

// Cell Kind & Display
struct Cell {
    // TODO: Use pos from base cell instead
    Cell() = default;
    CellType kind = CellType::Empty;

    [[nodiscard]] std::string getDrawing(int randomNum) const;
    virtual ~Cell()= default;;
};

struct EmptyCell : public Cell{
    EmptyType emp ;
    explicit EmptyCell(EmptyType e):emp{e}{
        kind = CellType::Empty;
    };
    void showRange(int d) ;


    ~EmptyCell() override = default;

    int distance = 0;
};

