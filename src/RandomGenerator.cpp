#pragma once

#include <random>
#include <iostream>
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(double start, double end) {
    std::random_device rd;
    mt = static_cast<std::mt19937>(rd());
    dist = std::uniform_real_distribution(start, end);
}

auto RandomGenerator::generate() {
    return static_cast<int>(std::round(dist(mt)));
}

int RandomGenerator::flipCoin() {
    return (std::round(dist(mt))) > 5.0;
}

int RandomGenerator::below(int end) {
    return static_cast<int>(std::floor(dist(mt) * end / 10.0 - 1));
}