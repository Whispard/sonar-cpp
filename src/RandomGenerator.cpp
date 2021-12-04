#include <random>
#include <iostream>

class RandomGenerator{
public:
    RandomGenerator(double start=1.0, double end=10.0) {
        std::random_device rd;
        mt = static_cast<std::mt19937>(rd());
        dist = std::uniform_real_distribution(start, end);
    }

    auto generate(){
        return static_cast<int>(std::round(dist(mt)));
    }

    auto flipCoin(){
        return (std::round(dist(mt)))>5.0;
    }

    auto below(int end){
        return static_cast<int>(std::floor(dist(mt)*end/10.0 - 1));
    }

private:
    std::uniform_real_distribution<double> dist;
    std::mt19937 mt;
};