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

void door::move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions choice)
{
    object::increment_age();

    if (object::get_age()>=GATE_TIMER)
    {
    object::die(board);
    }
}

