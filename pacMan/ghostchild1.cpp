#include "ghostchild1.h"
#include "constants.h"

ghostChild1::ghostChild1(coords position):ghost(position,GHOST_PELLET_POOPER)
{
    char fileName[]="ghostChild1.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
}

ghostChild1::~ghostChild1()
{

}

