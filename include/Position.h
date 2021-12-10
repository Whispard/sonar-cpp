#pragma once

#include <cmath>
#include "Config.h"
#include <stdexcept>

//(row,col)
struct Position {
    // TODO: use config in constructor etc so you cant make incorrect position
    int row;
    int col;

    Position(int row, int col):
        row{row},
        col{col}
    {
    }


    // TODO: Use std::distance
    double operator-(Position other) const {
        return std::sqrt(
                (this->row - other.row) * (this->row - other.row)
                + (this->col - other.col) * (this->col - other.col)
        );
    }

    bool operator==(Position other) const{
        return this->row==other.row && this->col==other.col;
    }
};

// TODO: Switch from factory to static attributes
class PositionFactory{
public:
    explicit PositionFactory(Config& conf):
        config{conf}
    {}

    Position makePosition(int row, int col) const{
       if (row < config.rows &&
         col < config.cols &&
         row >= 0 &&
         col >= 0){
           return Position{row,col};
       }else{
           throw std::logic_error("Incorrect");
       }
    }

private:
    Config config;
};
