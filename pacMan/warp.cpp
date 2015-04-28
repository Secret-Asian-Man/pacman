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

