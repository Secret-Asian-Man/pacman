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
//    std::cout<<"DEBUG pacman::move: "<<std::endl;

//    checkPellet(pellets, choice);
    object::move(board, pellets, choice);

}

void pacman::checkPellet(object* pellet[][X_DIMENSION], directions choice)
{

   coords temp(object::get_position()); //pacman's position

    // up = 0, right = 1, down = 2, left = 3
    switch(choice){

        //================ up =====================
        case goUp:

        if(pellet[temp.get_y()][temp.get_x()+1]->getType() == PELLET ){
            pellet[temp.get_y()][temp.get_x()+1]->die(pellet);
            // decrement pellet
        }// end if

        break;


        //================ right =====================
        case goRight:

        if(pellet[temp.get_y()+1][temp.get_x()]->getType() == PELLET ){
            pellet[temp.get_y()+1][temp.get_x()]->die(pellet);
            // decrement pellet
        }// end if


        break;

        //================ down =====================
        case goDown:

        if(pellet[temp.get_y()][temp.get_x()-1]->getType() == PELLET ){
            pellet[temp.get_y()][temp.get_x()-1]->die(pellet);
            // decrement pellet
        }// end if

        break;

        //================ left =====================
        case goLeft:

        if(pellet[temp.get_y()-1][temp.get_x()]->getType() == PELLET ){
            pellet[temp.get_y()-1][temp.get_x()]->die(pellet);
            // decrement pellet
        }// end if
        break;

        default:

            // direction is incorrect
            //cout<<"*** eat pellet error ***"<<endl;
            break;



    }// end switch
}

