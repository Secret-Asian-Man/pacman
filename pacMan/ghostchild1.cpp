#include "ghostchild1.h"
#include "constants.h"

ghostChild1::ghostChild1(coords position):ghost(position,GHOST_PELLET_POOPER)
{
    char fileName[]="ghostChild1.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

ghostChild1::~ghostChild1()
{

}

void ghostChild1::move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions direction)
{
    if (false /*the previous space is null*/)
    {
        //save current coord
        //move
        //spawn new pellet at saved coord

    }
    else
    {
        //move normally
        ghost::move(board,pellets,direction);//increment age already called inside
    }
}

