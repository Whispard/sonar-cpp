#include "Config.cpp"
#include "RandomGenerator.cpp"
#include "Chest.cpp"
#include "Sonar.cpp"
#include "Cell.cpp"
#include <vector>
#include <iostream>

using Display = std::vector<std::vector<Cell>>;

class Board{
public:
    explicit Board(Config config, RandomGenerator randomizer):
            board{std::vector(config.rows,std::vector(config.cols,Cell{}))},
            randomGenerator{randomizer}
    {
        chests = Chest::makeRandom(config, randomizer);

        for (auto& chest:chests) {
            board[chest.row][chest.col].kind = CellType::Chest;
        }
    }

    // mark a cell as ranger
    void markRanger(int x, int y,int d){
        if (!checkOutOfBounds(x,y))
            board[y][x].showRange(d);
    }

    // call display on every cell
    void display(){
        markRangers();
        for(auto& row:board){
            for(auto& cell:row){
                cell.getDrawing(randomGenerator.flipCoin());
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }



    void markRangers() {
        for (auto& sonar: sonars) {
            auto ox = sonar.col;
            auto oy = sonar.row;
            auto d = getCell(sonar.pos).distance;

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

    bool placeAt(Position pos){
        auto& currentCell = getCell(pos);
        if(currentCell.kind != CellType::Empty)
            return false;

        currentCell = Cell{
            CellType::Sonar,
            0
        };
        // making Sonar from pos
        sonars.emplace_back(pos);

        for (auto& sonar:sonars) {
            board[sonar.row][sonar.col].distance = sonar.distFromNearestChest(chests);
        }
        return true;
    }

    Cell& getCell(Position pos){
        return board[pos.row][pos.col];
    }




private:
    Display board;
    std::vector<Chest> chests;
    std::vector<Sonar> sonars;
    RandomGenerator randomGenerator;

    bool checkOutOfBounds(int x, int y) {
        return (x > board[0].size() - 1 ||
                y > board.size() - 1 ||
                x < 0 ||
                y < 0);
    }
};

