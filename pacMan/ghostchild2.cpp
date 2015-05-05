#include "ghostchild2.h"
#include "constants.h"
#include "door.h"

ghostChild2::ghostChild2(coords position/*, pacman *pacptr*/):ghost(position,GHOST_GATE_DROPPER/*,pacptr*/)
{
    char fileName[]="ghostChild2.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

}

ghostChild2::~ghostChild2()
{

}

void ghostChild2::move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions direction)
{



        coords previousPos= previous_position(direction);

        if (board[previousPos.get_y()][previousPos.get_x()]==NULL && object::get_age() % GATE_DROPPER_TIMER==0)
        {
            //save current coord
            //move
            //spawn new pellet at saved coord

            board[previousPos.get_y()][previousPos.get_x()]=new door(previousPos); //TEST THIS!!
            ghost::move(board,pellets,direction);
        }
        else
        {
            //move normally
            ghost::move(board,pellets,direction);//increment age already called inside
        }
}
