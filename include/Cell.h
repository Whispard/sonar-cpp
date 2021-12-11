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
    Cell() = default;
    CellType kind = CellType::Empty;
    // TODO: Decouple this distance filed from here
    //int distance = 0;



    [[nodiscard]] std::string getDrawing(int randomNum) const;
    virtual ~Cell()= default;;
};

struct EmptyCell : public Cell{
//    CellType kind = CellType::Empty;
    EmptyType emp ;
    explicit EmptyCell(EmptyType e):emp{e}{};
    void showRange(int d) ;


    ~EmptyCell() override = default;

    int distance = 0;
};

