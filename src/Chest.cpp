#pragma once

#include <Chest.h>
#include "Position.h"

Chest::Chest(Position pos) :
        pos{pos},
        row(pos.row),
        col(pos.col),
        found(false) {
    kind = CellType::Chest;
}

