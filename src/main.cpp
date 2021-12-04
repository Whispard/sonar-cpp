#include "Board.cpp"

int main() {
    auto config = Config();
    auto randomizer = RandomGenerator();
    auto rnd = RandomGenerator();
    auto board = Board(config, randomizer);
    for (int i = 0; i < 5; ++i) {
        auto pos = Position{rnd.below(config.rows), rnd.below(config.cols)};
        board.placeAt(pos);
    }
    board.display();
    board.placeAt(Position{10,8});
    board.display();
    return 0;
}

