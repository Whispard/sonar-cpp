#pragma once

#include <iostream>

enum class CellType {
    Empty,
    Chest,
    Sonar,
    Ranger
};

struct Cell {
    CellType kind = CellType::Empty;
    // TODO: Decouple this distance filed from here
    int distance = 0;

    void showRange(int d) {
        this->kind = CellType::Ranger;
        this->distance = d;
    }

    void getDrawing(int randomNum) {
        // this can be refactored to Cell func
        // since this is cell func common to all
        // but IDK how to convert from/to char int
        char out = '0';
        int value = 0;
        switch (this->kind) {
            case CellType::Empty: {
                if (randomNum)
                    out = '_';//'~';
                else
                    out = '_';//'`';
                break;
            }
            case CellType::Chest: {
                out = 'C';
                break;
            }
            case CellType::Sonar: {
                if (this->distance < 10)
                    value = this->distance;
                else
                    value = this->distance % 10;
                break;
            }
            case CellType::Ranger: {
                // use simple array or fetch bla
//                        auto rangeDecorations = std::vector({'*','8','='});
//                        out = rangeDecorations[cell.distance % (rangeDecorations.size()-1)];
//                        cell.kind = CellType::Empty;
                out = this->distance + '0';
                break;
            }
        }
        if (value == 0)
            std::cout << out;
        else
            std::cout << value;
    }
};

