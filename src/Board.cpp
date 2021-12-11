#include <vector>
#include <screen.h>
#include "Board.h"
#include "RandomGenerator.h"
#include "Chest.h"
#include "Cell.h"

/*
 * OPTIONS
 * 1) USE STD VARIANT NOPE
 * 2) USE VECS OF SMART POINTERS
 * 3) USE WRAPPER CLASS
 */

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

    // TODO: This isn't speciality of chests, move to Pos
    auto randPositions = Chest::makeRandom(config, randomizer);
    for (auto &chest: randPositions) {
        board[chest.row][chest.col] = std::make_unique<Chest>(chest.pos);
    }
}

// mark a cell as ranger
void Board::markRanger(int x, int y, int d) {
    if (!checkOutOfBounds(x, y)) {
//        board[y][x]->showRange(d);
    }
}


// call display on every cell
void Board::display(Position pos) {
//    markRangers();
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
//    for (auto &sonar: sonars) {
//        auto ox = sonar.col;
//        auto oy = sonar.row;
//        auto d = 2;//getCell(sonar.pos)->distance;
//
//        for (int p = ox - d; p <= ox + d; ++p) {
//            markRanger(p, oy - d, d);
//            markRanger(p, oy + d, d);
//        }
//        for (int p = oy - d; p < oy + d; ++p) {
//            markRanger(ox - d, p, d);
//            markRanger(ox + d, p, d);
//        }
//    }
}

// TODO: Add place randomly
bool Board::placeAt(Position pos) {
    auto &currentCell = getCell(pos);
    if(currentCell->kind==CellType::Chest){
        // TODO: use cast instead
        auto chest = dynamic_cast<Chest*>(currentCell.get());
        chest->found = true;
        // other modifications?
        return false;
    }
    if (currentCell->kind != CellType::Empty)
        return false;

    currentCell = std::make_unique<Sonar>(pos);

    // fine way to solve this is just make list of all positions and sonars
    // we can snatch objs

    auto chests = std::vector<std::reference_wrapper<std::unique_ptr<Chest>>>();
    std::for_each(board.begin(), board.end(), [&chests](auto row){
        std::for_each(row.begin(),row.end(),[&chests](auto cell){
            chests.push_back(std::reference_wrapper<std::unique_ptr<Chest>>(cell));
        });
    });
//    Sonar::updateAll(chests);
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

