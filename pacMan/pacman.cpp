//DAVID



#include "pacman.h"
#include "constants.h"
#include <iostream>
using namespace std;

pacman::pacman(coords position):object(position,PACMAN)
{
    char fileName[]="pacman.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();


    _lives=LIVES;
}

pacman::~pacman()
{

}

directions pacman::get_pacmanDirection()
{
    return _pacmanDirection;
}

int pacman::get_lives()
{
    return _lives;
}

void pacman::set_pacmanDirection(directions other)
{
    _pacmanDirection=other;
}

void pacman::set_lives(int other)
{
    _lives=other;
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

void pacman::move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice)
{
    coords pacPosition(object::get_position());

    switch (choice)
    {
    case goUp:
        if (board[pacPosition.get_y()-1][pacPosition.get_x()]==NULL)
        {
               _pacmanDirection=choice;
               _sprite.setRotation(-90);

        }
        else
        {
            cout<<"@#$!$#%"<<endl;
        }
        //else move (already taken care of after switch case)
        break;

    case goRight:
        if (board[pacPosition.get_y()][pacPosition.get_x()+1]==NULL)
        {
               _pacmanDirection=choice;
               _sprite.setRotation(0);

        }
        break;

    case goDown:
        if (board[pacPosition.get_y()+1][pacPosition.get_x()]==NULL)
        {
               _pacmanDirection=choice;
               _sprite.setRotation(90);

        }
        break;

    case goLeft: //put sprite rotation in here instead!!!!@@@@@@@@@
        if (board[pacPosition.get_y()][pacPosition.get_x()-1]==NULL)
        {
               _pacmanDirection=choice;
               _sprite.setRotation(180);

        }
        break;

    default:
        break;

    }


    checkPellet(pellets, _pacmanDirection); //checks if there is a pellet in the next slot, and kills it if found
    object::move(board, pellets, _pacmanDirection);

//    switch (choice)
//    {
//    case goUp:
//        _sprite.setRotation(-90);
//        break;

//    case goDown:
//        _sprite.setRotation(90);
//        break;

//    case goLeft:
//        _sprite.setRotation(180);
//        break;

//    case goRight:
//        _sprite.setRotation(0);
//        break;

//    default:
//        break;
//    }

    object::increment_age();
}

void pacman::checkPellet(object* pellet[][X_DIMENSION], directions choice)
{

    coords temp(object::get_position()); //pacman's position

    // up = 0, right = 1, down = 2, left = 3
    switch(choice)
    {

    //================ up =====================
    case goUp:

        if (pellet[temp.get_y()-1][temp.get_x()]!=NULL)
        {
            pellet[temp.get_y()-1][temp.get_x()]->die(pellet);
        }// end if
        break;


        //================ right =====================
    case goRight:

        if (pellet[temp.get_y()][temp.get_x()+1]!=NULL )
        {
            pellet[temp.get_y()][temp.get_x()+1]->die(pellet);
        }// end if
        break;

        //================ down =====================
    case goDown:

        if (pellet[temp.get_y()+1][temp.get_x()]!=NULL)
        {
            pellet[temp.get_y()+1][temp.get_x()]->die(pellet);
        }// end if

        break;

        //================ left =====================
    case goLeft:
        if (pellet[temp.get_y()][temp.get_x()-1]!=NULL)
        {
            pellet[temp.get_y()][temp.get_x()-1]->die(pellet);
        }// end if
        break;

    default:
        break;
    }// end switch
}

