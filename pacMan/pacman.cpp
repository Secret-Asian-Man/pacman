#include "pacman.h"
#include "constants.h"

pacman::pacman(coords position):object(position,PACMAN)
{
        _direction = -1;
}

pacman::~pacman()
{

}

int pacman::checkValid(int direction){

    if(direction >= 0 && direction <= 3)
        return direction;


}

void pacman::command(object* board[][Y_DIMENSION], int direction){

    // check if you can move there
    move(board, direction);

    _direction = direction;
}
