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
            // the problem is it is sonar but it is marked as kind = empty
            // means defaults are incorrect
            if(emptyCell->emp==EmptyType::E) {
                out = "~"s;
            }else{
                out = "`"s;}
            }
            break;
        case CellType::Chest: {
            auto chest = dynamic_cast<const Chest*>(this);
            if(chest->emp==EmptyType::E) {
                out = "~"s;
            }else{
                out = "`"s;}
        }
            break;
        case CellType::Sonar: {
            auto sonar = dynamic_cast<const Sonar*>(this);
            if (sonar->distance < 10)
                out = std::to_string(sonar->distance);
            else
                out = std::to_string(0);
//            out = "S"s;
            break;
        }
        case CellType::Ranger: {
            out = "."s;
            break;
        }
    }
    return out;
}
