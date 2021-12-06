#pragma once

#include <cmath>

//(row,col)
struct Position {
    // TODO: use config in constructor etc so you cant make incorrect position
    int row;
    int col;

    // TODO: Use std::distance
    double operator-(Position other) const {
        return std::sqrt(
                (this->row - other.row) * (this->row - other.row)
                + (this->col - other.col) * (this->col - other.col)
        );
    }
};
