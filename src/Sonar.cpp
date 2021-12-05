#include <vector>
#include <stdexcept>
#include "Sonar.h"
#include "Position.h"
#include "Chest.h"

Sonar::Sonar(Position pos) :
        pos{pos},
        row(pos.row),
        col(pos.col) {}

int Sonar::distFromNearestChest(const std::vector<Chest> &chests) {
    // TODO: use vector max directly
    double smallest = 100;
    for (auto &chest: chests) {
        if ((this->pos - chest.pos) < smallest)
            smallest = this->pos - chest.pos;
    }
    if (smallest == 100) {
        throw std::logic_error("distance func not working");
    }
    return static_cast<int>(std::round(smallest));
}
