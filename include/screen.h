#pragma once

#include <Config.h>
#include <vector>
#include <Cell.h>
#include "Position.h"

class Screen{
public:
    explicit Screen(Config& config):config{config}{};
    virtual void print(const char* c) = 0;
    virtual void end() = 0;
    virtual void clearScreen() = 0;
    virtual void moveTo(Position pos) = 0;
    virtual Position giveControl() = 0;
    virtual ~Screen()= default;

protected:
    Config& config;
};

// TODO: Split into declaration and definition
class CursesScreen: public Screen{
public:
    explicit CursesScreen(Config& config);

    void print(const char* c) override;

    void clearScreen() override;

    void moveTo(Position pos) override;

    Position giveControl() override;

    void end() override;

};
/*
class ConsoleScreen: public Screen{
public:
    explicit ConsoleScreen(Config config) {
    }

    void print(const char* c) override{
        std::cout << c;
    }

    void end() override{}
};

*/

