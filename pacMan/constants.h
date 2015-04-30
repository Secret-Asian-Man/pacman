#ifndef CONSTANTS
#define CONSTANTS
#include <SFML/Graphics.hpp>
#include <iostream>

//X is collumns, Y is rows!
const int X_DIMENSION=28; //orginal 31 (0 BASED!!)
const int Y_DIMENSION=31; //original 28 (0 BASED!!)
const int HUD_SIZE=50;
const int BOX_SIZE=25;

const int LIVES=3;

const char PACMAN='M';
const char WALLS='W';
const char PELLET='P';
const char POWER_PELLET='U';
const char DOOR='D';
const char NULLED='.';
const char WARP='R';
const char BOARDERS='B';
const char GHOST='G';
const char GHOST_PELLET_POOPER='O';
const char GHOST_GATE_DROPPER='A';
const char NEXT_LINE=10; // return/enter key
//M=pacman
//W=walls
//P=pebble
//U=powerUp
//D=door
//N=null
//H=wormHole
//G=ghost
//R=Warp


enum directions{
    none=-1,
    goLeft=3,
    goRight=1,
    goUp=0,
    goDown=2
};

//SFML stuff
const float WINDOW_WIDTH=X_DIMENSION*BOX_SIZE;
const float WINDOW_HEIGHT=Y_DIMENSION*BOX_SIZE;
const std::string GAME_TITLE="Pacman";
const double RATE=0.5*1000;
const int FRAME_RATE=60;








#endif // CONSTANTS

