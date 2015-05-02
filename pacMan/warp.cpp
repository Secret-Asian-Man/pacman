#include "warp.h"
#include "constants.h"
warp::warp(coords position):object(position, WARP)
{
    char fileName[]="warp.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

warp::~warp()
{

}

void warp::move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions choice)
{

}

