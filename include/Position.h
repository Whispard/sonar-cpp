#pragma once

#include <cmath>
#include "Config.h"
#include "RandomGenerator.h"
#include <stdexcept>

//(row,col)
struct Position {
    // TODO: use config in constructor etc so you cant make incorrect position
    int row;
    int col;

    inline static Config config;
    static void setLimits(Config config1){
        config = config1;
    }

    Position(int row, int col):
        row{row},
        col{col}
    {
        if (!(row < config.rows &&
            col < config.cols &&
            row >= 0 &&
            col >= 0)){
            throw std::logic_error("Invalid pos parameters");
        }
    }
    // 106

    template<typename T,typename Container>
    static auto makeRandom(RandomGenerator& randomizer){
        // TODO: Use fp for shorter method
//        auto result = Container<T>{};
        auto result = Container();
        Position::setLimits(config);
        for (int chestsPlaced = 0; chestsPlaced < config.totalChests; ++chestsPlaced) {
            auto newPos = Position{
                    randomizer.below(config.rows),
                    randomizer.below(config.cols)
            };
            //Handle if Position already exists
            if(std::find(result.begin(), result.end(), newPos)!=result.end()){
                chestsPlaced--;
                continue;
            }
            result.push_back(newPos);
        }
        return result;
    }

//    template<typename Container>
//    static auto makeRandom(RandomGenerator& randomizer){
//        // TODO: Use fp for shorter method
//        auto result = std::vector<Position>();
//        Position::setLimits(config);
//        for (int chestsPlaced = 0; chestsPlaced < config.totalChests; ++chestsPlaced) {
//            auto newPos = Position{
//                    randomizer.below(config.rows),
//                    randomizer.below(config.cols)
//            };
//            //Handle if Position already exists
//            if(std::find(result.begin(), result.end(), newPos)!=result.end()){
//                chestsPlaced--;
//                continue;
//            }
//            result.push_back(newPos);
//        }
//        return result;
//    }



    // TODO: Use std::distance
    double operator-(Position other) const {
        return std::sqrt(
                (this->row - other.row) * (this->row - other.row)
                + (this->col - other.col) * (this->col - other.col)
        );
    }

    bool operator==(Position other) const{
        return this->row==other.row && this->col==other.col;
    }
};
