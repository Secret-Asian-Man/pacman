#include "pellet.h"
#include "constants.h"
#include "grid.h"
#include <windows.h>

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

void pellet::die(object *board[][X_DIMENSION])
{
    Beep(2000,7);
    Beep(500,7);

    object::die(board);
}



