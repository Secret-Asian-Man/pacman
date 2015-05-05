#include "pacman.h"
#include "constants.h"
#include <iostream>
#include <windows.h>

using namespace std;

pacman::pacman(coords position):object(position,PACMAN)
{
    char fileName[]="pacman.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
    object::loadSprite();

    _pacState=normalPacman;
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

pacManState pacman::get_pacState()
{
    return _pacState;
}

void pacman::set_pacmanDirection(directions other)
{
    _pacmanDirection=other;
}

void pacman::set_lives(int other)
{
    _lives=other;
}

void pacman::set_pacState(pacManState other)
{
    _pacState=other;
}


void pacman::die(object *board[][X_DIMENSION])
{
    _lives--;
    //remember to move pacman and the ghost to start locations using the mapFile(dont touch the pelletFile), after calling this function

    if (_lives<0)
    {
        object::die(board);
    }
    else
    {
        // move pacman and ghosts back to spawn.
        //make ghosts poop pellets and gates
        coords spawn(object::get_spawnPosition());
        coords pos(object::get_position());

        board[spawn.get_y()][spawn.get_x()]=board[pos.get_y()][pos.get_x()];
        board[pos.get_y()][pos.get_x()]=NULL;

        object::set_position(spawn);
    }

}

void pacman::move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice)
{

    coords pacPosition(object::get_position());//makes a copy of pacman's current position

    switch (choice) //enforces a precondition, that spot must be empty to change pacman's direction
    {
    case goUp:
        if (board[pacPosition.get_y()-1][pacPosition.get_x()]==NULL)
        {
            _pacmanDirection=choice;
            _sprite.setRotation(-90);

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

    case goLeft:
        if (board[pacPosition.get_y()][pacPosition.get_x()-1]==NULL)
        {
            _pacmanDirection=choice;
            _sprite.setRotation(180);

        }
        break;

    default:
        break;

    }//end switch

    //================================
    if (checkPellet(pellets, _pacmanDirection)==POWER_PELLET) //eats the pellet and returns the type of pellet just eaten.
    {
        _pacState=superPacman;
        object::reset_age(); //restarts countdown
    }

    if (object::get_age()>=SUPER_PACMAN_DURATION)
    {
        _pacState=normalPacman;
    }

    if (_pacState==superPacman)
    {

        Beep(5000,2);
        Beep(3000,2);
        Beep(5000,2);



        //cout<<"SUPERPACMAN!!!!!!!"<<endl;
        checkGhost(board, _pacmanDirection); //FIXXXXX checkGhost(board, _pacmanDirection) //have ghosts spawn back at house when ghost::die() is run
    }
    else
    {
        //cout<<"normal pacman..."<<endl;

    }

    //Have this checkPellet function return the type of the pellet.
    //If the type is a powerPellet, change pacman's mode to superPacMan (REMEMBER TO COUNTDOWN!!), which will enable checkGhost().
    //The ghost will check if pacman is superPacman with the _pacPtr, if he is, change ghost to frightened mode, which will disable checkPacman().
    //================================

    object::move(board, pellets, _pacmanDirection);

    object::increment_age();
}

char pacman::checkPellet(object* pellet[][X_DIMENSION], directions choice)
{

    coords temp(object::get_position()); //pacman's position
    char pelletType;

    // up = 0, right = 1, down = 2, left = 3
    switch(choice)
    {

    //================ up =====================
    case goUp:

        if (pellet[temp.get_y()-1][temp.get_x()]!=NULL)
        {
            pelletType=pellet[temp.get_y()-1][temp.get_x()]->getType();
            pellet[temp.get_y()-1][temp.get_x()]->die(pellet);
        }// end if
        break;


        //================ right =====================
    case goRight:

        if (pellet[temp.get_y()][temp.get_x()+1]!=NULL )
        {
            pelletType=pellet[temp.get_y()][temp.get_x()+1]->getType();
            pellet[temp.get_y()][temp.get_x()+1]->die(pellet);
        }// end if
        break;

        //================ down =====================
    case goDown:

        if (pellet[temp.get_y()+1][temp.get_x()]!=NULL)
        {
            pelletType=pellet[temp.get_y()+1][temp.get_x()]->getType();
            pellet[temp.get_y()+1][temp.get_x()]->die(pellet);
        }// end if

        break;

        //================ left =====================
    case goLeft:
        if (pellet[temp.get_y()][temp.get_x()-1]!=NULL)
        {
            pelletType=pellet[temp.get_y()][temp.get_x()-1]->getType();
            pellet[temp.get_y()][temp.get_x()-1]->die(pellet);
        }// end if
        break;

    default:
        break;
    }// end switch

    return pelletType; //returns the pellet type;
}

void pacman::checkGhost(object *board[][X_DIMENSION], directions choice)
{
    // up = 0, right = 1, down = 2, left = 3
    switch(choice){

    //================ up =====================
    case goUp:

        if (board[_position.get_y()-1][_position.get_x()]!=NULL)
        {
            if(board[_position.get_y()-1][_position.get_x()]->getType() == GHOST ){
                board[_position.get_y()-1][_position.get_x()]->die(board);
                // decrement pellet
            }// end if
        }


        break;


        //================ right =====================
    case goRight:

        if (board[_position.get_y()][_position.get_x()+1]!=NULL)
        {
            if(board[_position.get_y()][_position.get_x()+1]->getType() == GHOST )
            {
                board[_position.get_y()][_position.get_x()+1]->die(board);
            }
        }// end if


        break;

        //================ down =====================
    case goDown:

        if (board[_position.get_y()+1][_position.get_x()]!=NULL)
        {
            if(board[_position.get_y()+1][_position.get_x()]->getType() == GHOST ){
                board[_position.get_y()+1][_position.get_x()]->die(board);

            }

        }// end if

        break;

        //================ left =====================
    case goLeft:

        if (board[_position.get_y()][_position.get_x()-1]!=NULL)
        {
            if(board[_position.get_y()][_position.get_x()-1]->getType() == GHOST ){
                board[_position.get_y()][_position.get_x()-1]->die(board);
        }

        }// end if
        break;

    default:

        // direction is incorrect
        //cout<<"*** eat pellet error ***"<<endl;
        break;



    }// end switch

}

