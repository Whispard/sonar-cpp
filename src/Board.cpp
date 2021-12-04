#include "Config.cpp"
#include "Cell.cpp"
#include "RandomGenerator.cpp"
#include <vector>
#include <string>
#include <iostream>
#include <random>

using Display = std::vector<std::vector<Cell>>;
using Positions = std::vector<Position>;

class Board{
public:
    explicit Board(Config config, RandomGenerator randomizer):
            board{std::vector(config.rows,std::vector(config.cols,Cell{
                CellType::Empty
            }))},
            randomGenerator{randomizer}
    {
        chestLocs = std::vector<Position>();
        for (int chestsPlaced = 0; chestsPlaced < config.totalChests; ++chestsPlaced) {
            auto newChest = Position{
                    randomizer.below(config.rows),
                    randomizer.below(config.cols)
            };
            // TODO: Handle when chest already exists
            chestLocs.push_back(newChest);
        }

        for (auto& chest:chestLocs) {
            board[chest.row][chest.col] = Cell{
                CellType::Chest
            };
        }
    }

    void markRanger(int x, int y,int d){
        if(x > board[0].size() - 1 ||
           y > board.size() - 1 ||
           x < 0 ||
           y < 0)
            return;
        board[y][x].kind = CellType::Ranger;
        board[y][x].distance = d;
    }


    void display(){
        markRangers();
        for(auto& row:board){
            for(auto& cell:row){
                drawCell(cell);
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    void drawCell(Cell &cell) {
        char out = '0';
        int value = 0;
        switch (cell.kind){
            case CellType::Empty:{
                if (randomGenerator.flipCoin())
                    out = '_';//'~';
                else
                    out = '_';//'`';
                break;
            }
            case CellType::Chest:{
                out = ' ';
                break;
            }
            case CellType::Sonar:{
                if (cell.distance<10)
                    value = cell.distance;
                else
                    value = cell.distance % 10;
                break;
            }
            case CellType::Ranger:{
                // use simple array or fetch bla bla
//                        auto rangeDecorations = std::vector({'*','8','='});
//                        out = rangeDecorations[cell.distance % (rangeDecorations.size()-1)];
//                        cell.kind = CellType::Empty;
                out = '_';// cell.distance + '0';
                break;
            }
        }
        if(value==0)
            std::cout<< out ;
        else
            std::cout << value;
    }

    void markRangers() {
        for (auto& sonar: sonarLocs) {
            auto ox = sonar.col;
            auto oy = sonar.row;
            auto d = getCell(sonar).distance;

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
        sonarLocs.push_back(pos);

        for (auto& sonar:sonarLocs) {
            board[sonar.row][sonar.col].distance = distFromNearestChest(sonar);
        }
        return true;
    }

    Cell& getCell(Position pos){
        return board[pos.row][pos.col];
    }

    int distFromNearestChest(Position sonar) {
        // TODO: use vector max directly
//        auto distances = std::vector<double>();
//            distances.push_back(dist(sonar, chest));
        double smallest = 100;
        for (auto& chest:chestLocs) {
            if ((sonar- chest) < smallest)
                smallest = sonar - chest;
        }
        return static_cast<int>(std::round(smallest));
    }


private:
    Display board;
    Positions chestLocs;
    Positions sonarLocs;
    RandomGenerator randomGenerator;
};

