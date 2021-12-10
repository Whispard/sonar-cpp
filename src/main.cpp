#include "Board.h"
#include <fmt/format.h>
#include <screen.h>

void startTitle(const std::string& title,char decorator){
    fmt::print("{}{}{}\n",decorator,title,decorator);
}


int main() {
    startTitle("SONAR",'*');
    auto config = Config();
    auto randomizer = LibRandomGenerator();
    auto rnd = LibRandomGenerator();
    auto screen = CursesScreen(config);
    auto board = Board(config, randomizer, screen);
    for (int i = 0; i < 5; ++i) {
        auto pos = Position{rnd.below(config.rows), rnd.below(config.cols)};
        board.placeAt(pos);
    }
    board.display(Position{0,0});
    while(true) {
        auto newPos = screen.giveControl();
        board.placeAt(newPos);
        board.display(newPos);
    }
    screen.end();
    return 0;
}

