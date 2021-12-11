#pragma once

#include <Chest.h>
#include "Position.h"

Chest::Chest(Position pos,EmptyType emp) :
        pos{pos},
        row(pos.row),
        col(pos.col),
        emp{emp}{
    kind = CellType::Chest;
}

