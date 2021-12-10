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
    CellType kind = CellType::Empty;
    // TODO: Decouple this distance filed from here
    int distance = 0;


    void showRange(int d) ;

    [[nodiscard]] std::string getDrawing(int randomNum) const;
    virtual ~Cell()= default;;
};

struct EmptyCell : public Cell{
    EmptyCell() = default;
    CellType kind;
    explicit EmptyCell(CellType kind):kind{kind}{};
    ~EmptyCell() override = default;
};

