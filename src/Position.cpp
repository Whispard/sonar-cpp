#pragma once

#include <cmath>

//(row,col)
struct Position {
    int row;
    int col;

    double operator-(Position other) const{
        return std::sqrt(
                (this->row - other.row)*(this->row - other.row)
                +    (this->col - other.col)*(this->col - other.col)
        );
    }
};
