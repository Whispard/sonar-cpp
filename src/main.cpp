#include "Board.h"

int main() {
    auto config = Config();
    auto randomizer = RandomGenerator(1.0, 10.0);
    auto rnd = RandomGenerator(1.0, 10.0);
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

