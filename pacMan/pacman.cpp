#include "pacman.h"
#include "constants.h"

//how would the child give the parent some data, if the parent is born first
//if not possible have the child take care of the textures

pacman::pacman(coords position):object(position,PACMAN)
{
    char fileName[]="pacman.png";
    _fileName=fileName;
    object::loadTexture(_fileName); //@GO DRAW THE SPRITES NOW!!! AND LOAD TEXTURES IN THE REST OF THE CHILDS@

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
