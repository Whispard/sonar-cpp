#pragma once

struct Config{
    int rows;
    int cols;
    int totalChests;
    int totalSonars;
    explicit Config(int rows=15,int cols=60,int chests=18,int sonars=18):
        rows(rows),
        cols(cols),
        totalChests(chests),
        totalSonars(sonars){
    }

};

