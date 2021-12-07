#pragma once

#include <random>
#include <iostream>

// TODO: Make below func generic
class RandomGenerator {
public:
    RandomGenerator() = default;
    virtual bool flipCoin() = 0;
    virtual int below(int end) = 0 ;
    virtual ~RandomGenerator()= default;;
};

class LibRandomGenerator: public RandomGenerator {
public:
    LibRandomGenerator();
    bool flipCoin() override;
    int below(int end) override;
    ~LibRandomGenerator() override = default;;
};

class MockRandomGenerator: public RandomGenerator {
public:
    MockRandomGenerator(std::initializer_list<bool> coins,std::initializer_list<int> belows);
    bool flipCoin() override;
    int below(int end) override;
    ~MockRandomGenerator() override = default;

private:
    std::vector<bool> coins;
    std::vector<int> belows;
    std::vector<bool>::const_iterator pCoin;
    std::vector<int>::const_iterator pBelows;
};


