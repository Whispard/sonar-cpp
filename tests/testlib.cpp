#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "RandomGenerator.h"
#include "Position.h"
#include "Sonar.h"
#include "Chest.h"
#include "Config.h"

unsigned int factorial(unsigned int num){
    if (!num) return 1;
    return num <=1 ? num: num* factorial(num-1);
}

TEST_CASE("Quick Test","[main]"){
    SECTION("exceptional case"){
        REQUIRE(factorial(0)==1);
    }

    SECTION("normal cases") {
        REQUIRE(factorial(1) == 1);
        REQUIRE(factorial(2) == 2);
        REQUIRE(factorial(3) == 6);
        REQUIRE(factorial(10) == 3628800);
    }
}

TEST_CASE("Random generator","[randomizer]"){
    auto rnd = LibRandomGenerator();

    SECTION("below"){
        REQUIRE(rnd.below(10)<10);
        REQUIRE(rnd.below(2)<2);
        REQUIRE(rnd.below(2)<2);
    }

    SECTION("coin"){
        bool c = false;
        while(!(c = rnd.flipCoin()));
        while((c = !rnd.flipCoin()));
    }

    SECTION("mock") {
        auto coins = {false, true, true};
        auto belows = {2, 3, 4};
        auto gen = MockRandomGenerator(coins, belows);
        REQUIRE(gen.flipCoin() == false);
        REQUIRE(gen.below(3) == 2);
        REQUIRE(gen.flipCoin() == true);
        REQUIRE(gen.below(3) == 3);
        REQUIRE(gen.below(3) == 4);
        REQUIRE(gen.flipCoin() == true);
    }

}

TEST_CASE("Position","[position]"){
    auto p1 = Position{4,5};
    auto p2 = Position{7,9};
    auto p3 = Position{7,9};

    REQUIRE((p1-p2 - 5.0) < 0.1);
    REQUIRE((p2-p1 - 5.0) < 0.1);
    REQUIRE(!(p1==p2));
    REQUIRE(p2==p3);

    auto conf = Config{};
    Position::setLimits(conf);
    auto p4 = Position{10,20};
    // TODO test exception with catch
}

// TODO: Make use of mock randomizer for tests
TEST_CASE("Chest","[chest]"){
    auto p = Position{4,5};
    auto c = Chest(p);
    REQUIRE(c.pos.row == p.row);
    REQUIRE(c.pos.col == p.col);

    auto config = Config();
    auto rnd = LibRandomGenerator();

    auto chests = Chest::makeRandom(config,rnd);
    REQUIRE(chests.size() == config.totalChests);
    // TODO: Use a mock randomizer to test correctly
    std::for_each(chests.begin(), chests.end(), [&config](Chest c){
        // not needed if pos don't allow such values
        REQUIRE(c.pos.row < config.rows);
        REQUIRE(c.pos.col < config.cols);
    });
    // TODO: check so no 2 chests are on same location


}

TEST_CASE("Sonar","[sonar]"){
    auto p = Position{2,2};
    auto s = Sonar(p);

    auto p2 = Position{4,5};
    auto c = Chest(p2);

}

TEST_CASE("Board","[board]"){

}
