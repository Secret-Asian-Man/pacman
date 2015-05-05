#include "ghostchild1.h"
#include "constants.h"
#include "pellet.h"

ghostChild1::ghostChild1(coords position/*,pacman* pacptr*/):ghost(position,GHOST_PELLET_POOPER/*,pacptr*/)
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

    if (object::get_age() % PELLET_POOPER_TIMER==0 && pellets[_position.get_y()][_position.get_x()]==NULL)
    {
        pellets[_position.get_y()][_position.get_x()]=new pellet(_position);
        ghost::move(board, pellets, direction);
    }
    else
    {
        ghost::move(board, pellets, direction);
    }

}

