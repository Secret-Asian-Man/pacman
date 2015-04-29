#include "pellet.h"
#include "constants.h"

pellet::pellet(coords position):object(position,PELLET)
{
    char fileName[]="pellet.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

pellet::~pellet()
{

}

void pellet::die()
{

}


