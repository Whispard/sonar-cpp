#pragma once

#include <string>
#include <Cell.h>
#include <Sonar.h>

void EmptyCell::showRange(int d) {
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
            auto emptyCell = dynamic_cast<const EmptyCell*>(this);
            if(emptyCell->emp==EmptyType::E) {
                out = "_"s;//"~"s;
            }else{
            out = "2"s;}
            }
            break;
        case CellType::Chest: {
            out = "C"s;
            break;
        }
        case CellType::Sonar: {
            auto sonar = dynamic_cast<const Sonar*>(this);
            if (sonar->distance < 10)
                out = std::to_string(sonar->distance);
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
