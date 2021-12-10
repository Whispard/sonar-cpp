#pragma once

#include <cmath>
#include "Config.h"
#include <stdexcept>

//(row,col)
struct Position {
    // TODO: use config in constructor etc so you cant make incorrect position
    int row;
    int col;

    inline static Config config;
    static void setLimits(Config config1){
        config = config1;
    }

    Position(int row, int col):
        row{row},
        col{col}
    {
        if (!(row < config.rows &&
            col < config.cols &&
            row >= 0 &&
            col >= 0)){
            throw std::logic_error("Invalid pos parameters");
        }
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
