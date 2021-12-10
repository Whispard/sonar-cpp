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
    chests = Chest::makeRandom(config, randomizer);
    for (int i=0;i<config.rows;i++) {
        auto newRow = std::vector<std::unique_ptr<Cell>>();
        for (int j = 0; j < config.cols; ++j) {
            newRow.push_back(std::make_unique<Cell>(randomizer.flipCoin()?CellType::Empty:CellType::Empty2));
        }
        board.push_back(std::move(newRow));
    }

    for (auto &chest: chests) {
        board[chest.row][chest.col] = std::make_unique<Chest>(CellType::Chest,chest.pos);
    }
}

// mark a cell as ranger
void Board::markRanger(int x, int y, int d) {
    if (!checkOutOfBounds(x, y))
        board[y][x]->showRange(d);
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
    for (auto &sonar: sonars) {
        auto ox = sonar.col;
        auto oy = sonar.row;
        auto d = getCell(sonar.pos)->distance;

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

// TODO: Add place randomly
bool Board::placeAt(Position pos) {
    auto &currentCell = getCell(pos);
    if(currentCell->kind==CellType::Chest){
        // TODO: use cast instead
        auto chest = std::find_if(chests.begin(), chests.end(),
                     [&pos](Chest c){
            return c.pos==pos;
        });
        chest->found = true;
        // other modifications?
        return false;
    }
    if (currentCell->kind != CellType::Empty && currentCell->kind != CellType::Empty2)
        return false;

    currentCell->kind = CellType::Sonar;
    currentCell->distance = 0;
    // making Sonar from pos
    sonars.emplace_back(pos);

    for (auto &sonar: sonars) {
        board[sonar.row][sonar.col]->distance = sonar.distFromNearestChest(chests);
    }
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

