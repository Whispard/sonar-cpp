#include <vector>
#include "Cell.cpp"

class Sonar{
public:
    explicit Sonar(Position pos):
            pos{pos},
            row(pos.row),
            col(pos.col)
    {}

    int row;
    int col;
    Position pos;
};