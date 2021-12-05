#pragma once

#include <random>
#include <iostream>

class RandomGenerator {
public:
    RandomGenerator() = default;

    // TODO: use default args
    explicit RandomGenerator(double start, double end);

    auto generate();

    int flipCoin();

    int below(int end);

private:
    std::uniform_real_distribution<double> dist;
    std::mt19937 mt;
};