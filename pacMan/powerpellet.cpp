#include "powerpellet.h"
#include "constants.h"
powerPellet::powerPellet(coords position):object(position,POWER_PELLET)
{
    char fileName[]="powerPellet.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

powerPellet::~powerPellet()
{

}

