#include <vector>
#include "Cell.cpp"

class Chest{
public:
    explicit Chest(Position pos):
        pos{pos},
        row(pos.row),
        col(pos.col)
    {}

    int row;
    int col;
    Position pos;
};