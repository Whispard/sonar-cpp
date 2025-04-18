#include <vector>
#include <screen.h>
#include "Board.h"
#include "RandomGenerator.h"
#include "Chest.h"
#include "Cell.h"


Board::Board(Config config, RandomGenerator& randomizer, Screen& screen) :
        randomGenerator{randomizer},
        screen(screen){
    for (int i=0;i<config.rows;i++) {
        auto newRow = std::vector<std::unique_ptr<Cell>>();
        for (int j = 0; j < config.cols; ++j) {
            newRow.push_back(std::make_unique<EmptyCell>(randomizer.flipCoin()?EmptyType::E:EmptyType::F));
        }
        board.push_back(std::move(newRow));
    }
    auto randPositions = Position::makeRandom<Position,std::vector<Position>>(randomizer);
    for (auto &chestPos: randPositions) {
        board[chestPos.row][chestPos.col] = std::make_unique<Chest>(chestPos,randomizer.flipCoin()?EmptyType::E:EmptyType::F);
    }
}

// mark a cell as ranger
void Board::markRanger(int x, int y, int d) {
    if (!checkOutOfBounds(x, y)) {
        if(board[y][x]->kind == CellType::Empty) {
            auto ranger = dynamic_cast<EmptyCell*>(board[y][x].get());
            ranger->showRange(d);
        }
    }
}


// call display on every cell
void Board::display(Position pos) {
    markRangers();
    screen.clearScreen();
    for (auto &row: board) {
        for (auto &cell: row) {
            screen.print(cell->getDrawing(randomGenerator.flipCoin()).c_str());
        }
        screen.print("\n");
    }
    screen.moveTo(pos);
}


void Board::markRangers() {
    for (auto &sonar: Sonar::sonars) {
        auto ox = sonar->col;
        auto oy = sonar->row;
        auto d = sonar->distance;

        for (int p = ox - d; p <= ox + d; ++p) {
            markRanger(p, oy - d, d);
            markRanger(p, oy + d, d);
        }
        for (int p = oy - d; p < oy + d; ++p) {
            markRanger(ox - d, p, d);
            markRanger(ox + d, p, d);
        }
    }
}

bool Board::placeAt(Position pos) {
    auto &currentCell = getCell(pos);

    if (currentCell->kind == CellType::Sonar)
        return false;
    currentCell = std::make_unique<Sonar>(pos);

    auto chests = std::vector<Position>();
    std::for_each(board.begin(), board.end(), [&](auto& row){
        std::for_each(row.begin(),row.end(),[&](const std::unique_ptr<Cell>& cell){
            screen.print(cell->kind==CellType::Chest?"1":"0");
            if(cell->kind == CellType::Chest) {
                auto c = dynamic_cast<Chest *>(cell.get());
                chests.push_back(c->pos);
            }
        });
    });
    Sonar::updateAll(chests);
    return true;
}

std::unique_ptr<Cell>& Board::getCell(Position pos) {
    return board[pos.row][pos.col];
}


bool Board::checkOutOfBounds(int x, int y) {
    return (x > board[0].size() - 1 ||
            y > board.size() - 1 ||
            x < 0 ||
            y < 0);
}

