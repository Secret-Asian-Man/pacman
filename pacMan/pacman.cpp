#include "pacman.h"
#include "constants.h"


pacman::pacman(coords position):object(position,PACMAN)
{
    char fileName[]="pacman.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();


        _direction = -1;
        _lives=LIVES;
}

pacman::~pacman()
{

}

int pacman::checkValid(int direction){

    if(direction >= 0 && direction <= 3)
        return direction;


}

void pacman::die(object *board[][X_DIMENSION])
{
    _lives--;
    //remember to move pacman and the ghost to start locations using the mapFile(dont touch the pelletFile), after calling this function

    if (_lives<0)
    {
        object::die(board);
    }

}

void pacman::move(object *board[][X_DIMENSION], int direction)
{
//    coords temp=object::get_position();

//    board[object::get_position().get_y()][object::get_position().get_x()+1]=board[object::get_position().get_y()][object::get_position().get_x()];

//    object.set_position(new coords(object::get_position().get_x()+1,object::get_position().get_y()));
//    board[temp.get_y()][temp.get_x()]==NULL;
}

void pacman::command(object* board[][X_DIMENSION], int direction){

    // check if you can move there
    move(board, direction);

    _direction = direction;
}
