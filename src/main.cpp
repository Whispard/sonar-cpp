#include "Board.h"
#include <fmt/format.h>

void startTitle(const std::string& title,char decorator){
    fmt::print("{}{}{}",decorator,title,decorator);
}

int main() {
    startTitle("SONAR",'*');
    auto config = Config();
    auto randomizer = LibRandomGenerator();
    auto rnd = LibRandomGenerator();
    auto board = Board(config, randomizer);
    for (int i = 0; i < 5; ++i) {
        auto pos = Position{rnd.below(config.rows), rnd.below(config.cols)};
        board.placeAt(pos);
    }
    board.display();
    board.placeAt(Position{10, 8});
    board.display();
    return 0;
}

