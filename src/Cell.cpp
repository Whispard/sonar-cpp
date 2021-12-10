#pragma once

#include <string>
#include <Cell.h>

void Cell::showRange(int d) {
    this->kind = CellType::Ranger;
    this->distance = d;
}

std::string Cell::getDrawing(int randomNum) const {
    using namespace std::literals::string_literals;
    // this can be refactored to Cell func
    // since this is cell func common to all
    // but IDK how to convert from/to char int
    std::string out = ""s;
    switch (this->kind) {
        case CellType::Empty: {
            out = "_"s;//"~"s;
            break;
        }
        case CellType::Empty2: {
            out = "2"s;//"`"s;
            break;
        }
        case CellType::Chest: {
            out = "C"s;
            break;
        }
        case CellType::Sonar: {
            if (this->distance < 10)
                out = std::to_string(this->distance);
            else
                out = std::to_string(0);
            out = "S"s;
            break;
        }
        case CellType::Ranger: {
            // TODO: Fix this implicit convo to char
//            out = this->distance + '0';
            out = "R"s;
            break;
        }
    }
    return out;
}
