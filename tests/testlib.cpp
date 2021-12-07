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
    auto rnd = RandomGenerator();

    SECTION("flip coin"){
        REQUIRE(rnd.flipCoin()>-1);
        REQUIRE(rnd.flipCoin()<1);
    }

    SECTION("below"){
        REQUIRE(rnd.below(10)<10);
        REQUIRE(rnd.below(2)<2);
        REQUIRE(rnd.below(2)<2);
    }
}

TEST_CASE("Position","[position]"){
    auto p1 = Position{4,5};
    auto p2 = Position{7,9};

    REQUIRE((p1-p2 - 5.0) < 0.1);
    REQUIRE((p2-p1 - 5.0) < 0.1);
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