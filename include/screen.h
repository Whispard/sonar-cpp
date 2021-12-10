#pragma once

#include <curses.h>
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


class CursesScreen: public Screen{
public:
    explicit CursesScreen(Config& config):
        Screen{config}{
        initscr();
        keypad(stdscr, true);
        noecho();
        start_color(); /* Start color */
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
    }

    void print(const char* c) override{
        attron(COLOR_PAIR(1));
        printw(c);
        attroff(COLOR_PAIR(1));
    }

    void clearScreen() override{
        clear();
    }

    void moveTo(Position pos) override{
        move(pos.row, pos.col);
    }

    Position giveControl() override{
        int lastKey = 0;
        while(lastKey != KEY_BACKSPACE){
            lastKey = getch();
            int posx = getcurx(stdscr);
            int posy = getcury(stdscr);
            switch (lastKey) {
                case KEY_UP:
                    move(posy - 1, posx);
                    break;
                case KEY_DOWN:
                    move(posy + 1, posx);
                    break;
                case KEY_LEFT:
                    move(posy, posx - 1);
                    break;
                case KEY_RIGHT:
                    move(posy, posx + 1);
                    break;
                case ' ':
                    return Position{posy, posx};
            }
            refresh();
        }
        return Position{0,0};
    }

    void end() override{
        getch();
        endwin();
    }
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

