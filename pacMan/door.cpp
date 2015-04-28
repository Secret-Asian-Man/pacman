#include "door.h"
#include "constants.h"
door::door(coords position):object(position,DOOR)
{
    char fileName[]="door.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

door::~door()
{

}

