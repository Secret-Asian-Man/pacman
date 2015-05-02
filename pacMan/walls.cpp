#include "walls.h"
#include "constants.h"
#include <iostream>
walls::walls(coords position):object(position,WALLS)
{
    char fileName[]="walls.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

walls::~walls()
{

}

void walls::die(object *board[][X_DIMENSION])
{

}

void walls::move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions choice)
{

}

