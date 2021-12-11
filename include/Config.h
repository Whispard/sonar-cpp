#pragma once

struct Config {
    int rows = 15;
    int cols = 60;
    int totalChests = 15;
    int totalSonars = 18;

    explicit Config()= default;
//    (int rows = 15, int cols = 60, int chests = 18, int sonars = 18) :
//            rows(rows),
//            cols(cols),
//            totalChests(chests),
//            totalSonars(sonars) {
//    }

};

