#ifndef CONSTANTS
#define CONSTANTS
#include <SFML/Graphics.hpp>
#include <iostream>

//X is collumns, Y is rows!
const int X_DIMENSION=31; //orginal 31 (0 BASED!!)
const int Y_DIMENSION=28; //original 28 (0 BASED!!)
const int BOX_SIZE=25;

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

//SFML stuff
const float WINDOW_WIDTH=Y_DIMENSION*BOX_SIZE;
const float WINDOW_HEIGHT=X_DIMENSION*BOX_SIZE;
const std::string GAME_TITLE="Pacman";









#endif // CONSTANTS

