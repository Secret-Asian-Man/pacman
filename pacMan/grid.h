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


    //accessors
    int get_pelletCount();
    gameState get_gameState();
    directions get_directions();

    //mutators
    void set_pelletCount(int other);
    void set_gameState(gameState other);
    void set_directions(directions other);

    //main functions
    void step();
    void show();
    void reset();
    void increment_pelletCount();
    void decrement_pelletCount();
    int count_pellets();

    //public variables
    object* _board[Y_DIMENSION][X_DIMENSION]; //grid of creatures pointers
    object* _pellets[Y_DIMENSION][X_DIMENSION];
    std::ifstream _mapData;
    std::ifstream _pelletData;



private:
    //private variables
    int _pelletCount;
    directions _pacmanDirection; //this class calls the move function, so it must provide the direction!
    gameState _gameState;

    //private functions
    void loadFile();
    void loadMap();
    void initializeToNull();

};

#endif // GRID_H
