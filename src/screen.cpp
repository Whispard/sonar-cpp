#include <curses.h>
#include <screen.h>

CursesScreen::CursesScreen(Config &config):
    Screen{config}{
        initscr();
        keypad(stdscr, true);
        noecho();
        start_color(); /* Start color */
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
}

void CursesScreen::print(const char* c){
    attron(COLOR_PAIR(1));
    printw(c);
    attroff(COLOR_PAIR(1));
}

void CursesScreen::clearScreen() {
    clear();
}

void CursesScreen::moveTo(Position pos) {
    move(pos.row, pos.col);
}

Position CursesScreen::giveControl() {
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

void CursesScreen::end() {
    getch();
    endwin();
}


