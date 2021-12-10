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
    CellType kind = CellType::Empty;
    // TODO: Decouple this distance filed from here
    int distance = 0;

    void showRange(int d) {
        this->kind = CellType::Ranger;
        this->distance = d;
    }

    std::string getDrawing(int randomNum) {
        using namespace std::literals::string_literals;
        // this can be refactored to Cell func
        // since this is cell func common to all
        // but IDK how to convert from/to char int
        int value = 0;
        std::string out = ""s;
        switch (this->kind) {
            case CellType::Empty: {
                out = "_"s;//"~"s;
                break;
            }
            case CellType::Empty2:{
                out = "_"s;//"`"s;
                break;
            }
            case CellType::Chest: {
                out = "C"s;
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
                // TODO: Fix this implicit convo to char
                out = this->distance + '0';
                break;
            }
        }
        return out;
    }
};

