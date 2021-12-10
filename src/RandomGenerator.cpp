#pragma once

#include "RandomGenerator.h"
#include "effolkronium/random.hpp"

using Random = effolkronium::random_static;

LibRandomGenerator::LibRandomGenerator() = default;

bool LibRandomGenerator::flipCoin() {
    return Random::get<bool>();
}

int LibRandomGenerator::below(int end) {
    return Random::get(0, end-1);
}

// TODO: expand double into generic types
// This won't work as sea uses all coins
MockRandomGenerator::MockRandomGenerator(std::initializer_list<bool> sup_coins,
                                         std::initializer_list<int> sup_belows):
    coins{sup_coins},
    belows{sup_belows},
    pCoin{coins.begin()},
    pBelows{belows.begin()}
    {}

bool MockRandomGenerator::flipCoin() {
    return *pCoin++;
}

int MockRandomGenerator::below(int end) {
    return *pBelows++;
}
