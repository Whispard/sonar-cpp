#include <iostream>

enum CellType{
    Empty,
    Chest,
    Sonar,
    Ranger
};

struct Cell{
    CellType kind = CellType::Empty;
    int distance = 0;
};

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