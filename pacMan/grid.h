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


    object* _board[Y_DIMENSION][X_DIMENSION]; //grid of creatures pointers
    object* _pellets[Y_DIMENSION][X_DIMENSION];
    std::ifstream _mapData;
    std::ifstream _pelletData;

    int _pelletCount;


private:
    //private functions
    void loadFile();
    void loadMap();
    void initializeToNull();

};

#endif // GRID_H
