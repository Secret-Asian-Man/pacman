#include "ghostchild2.h"
#include "constants.h"
ghostChild2::ghostChild2(coords position):ghost(position,GHOST_GATE_DROPPER)
{
    char fileName[]="ghostChild2.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

ghostChild2::~ghostChild2()
{

}

