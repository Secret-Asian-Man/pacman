#ifndef GRID_H
#define GRID_H
#include "object.h"
#include "constants.h"
#include <fstream>
#include <iostream>


class grid
{
public:
    grid();
    ~grid();

    //main functions
    void step();
    void show();



private:
    object* _board[X_DIMENSION][Y_DIMENSION]; //grid of creatures pointers
    object* _pellets[X_DIMENSION][Y_DIMENSION];
    std::ifstream _mapData;
    std::ifstream _pelletData;



    //private functions
    void loadFile();
    void loadMap();
    void initializeToNull();

};

#endif // GRID_H
