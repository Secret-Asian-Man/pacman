#ifndef GRID_H
#define GRID_H
#include "object.h"
#include "constants.h"
#include <fstream>
#include <iostream>
enum gameState{//MAY MOVE THIS TO GAME.H
    normal=0,
    paused=1,
    gameOver=2,
    win=3
};

enum directions{
    none=-1,
    goLeft=0,
    goRight=1,
    goUp=2,
    goDown=3
};

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
    void increment_pelletCount();
    void decrement_pelletCount();

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
