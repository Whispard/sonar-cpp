#include <vector>
#include <stdexcept>
#include "Sonar.h"
#include "Position.h"
#include "Chest.h"
#include "Cell.h"

Sonar::Sonar(Position pos) :
        pos{pos},
        row(pos.row),
        col(pos.col) {
    kind = CellType::Sonar;
    sonars.push_back(std::unique_ptr<Sonar>(this));
}

int Sonar::distFromNearestChest(const std::vector<Position> &chests) const {
    // TODO: use vector max directly
    double smallest = 100;
    for (auto &chest: chests) {
        if ((this->pos - chest) < smallest)
            smallest = this->pos - chest;
    }
    if (smallest == 100) {
        throw std::logic_error("distance func not working");
    }
    return static_cast<int>(std::round(smallest));
}

void Sonar::updateAll(const std::vector<Position>& chests) {
        for (auto &sonar: sonars) {
         sonar->distance = sonar->distFromNearestChest(chests);
    }
}
