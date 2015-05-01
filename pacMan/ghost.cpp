#include "ghost.h"
#include "constants.h"
ghost::ghost(coords position,char ghostType):object(position,GHOST)
{
    _ghostType=ghostType;
    _emotionalState=chase;
}

ghost::~ghost()
{

}

char ghost::get_objectType()
{
    return _ghostType;
}

ghostEmotionalState ghost::get_emotionalState()
{
    return _emotionalState;
}

void ghost::set_emotionalState(ghostEmotionalState other)
{
    _emotionalState=other;
}

void ghost::move(object *board[][X_DIMENSION],object* pellets[][X_DIMENSION], directions direction)
{
    //pacmancheck(); // make pacman die
    coords newDirect;
    if(atIntersection(board,direction)){
        newDirect = Intersection(board,direction);
        checkPacMan(board, newDirect);
        object::move(board, pellets, newDirect);
    }// end if
    else
        object::move( board, pellets, direction);
    checkPacMan(board, newDirect);

}

coords ghost::Intersection(object *board[][X_DIMENSION], directions direction)
{
    // checks surrounding positions for more than 1 exit.
    // cannot be opposite direction that it is going
    std::vector<coords> exits;

    // should be able to call RIGHT==NULL || RIGHT=PACMAN

    int exitCount = 0;

    // will check all positions except the opposite of the direction it is going
    // ex: if going left, right is not a move option

    // UP = 0; RIGHT = 1; DOWN = 2, LEFT = 3

    switch(direction)
    {
    case goUp:
        // UP
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()+1][_position.get_x()]->get_position());
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()+1]->get_position());
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()-1]->get_position());

        break;

    case goRight:
        // UP
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()+1][_position.get_x()]->get_position());
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()+1]->get_position());
        // DOWN
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()-1][_position.get_x()]->get_position());
        break;

    case goDown:
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()+1]->get_position());
        // DOWN
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()-1][_position.get_x()]->get_position());
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()-1]->get_position());
        break;

    case goLeft:
        // UP
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()+1][_position.get_x()]->get_position());
        // DOWN
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()-1][_position.get_x()]->get_position());
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(board[_position.get_y()][_position.get_x()-1]->get_position());
        break;

    }// end switch


        coords newCoord = choseDirection(exits, exits.size());
        return newCoord;



}

coords ghost::choseDirection(vector<coords> exits, int vectorSize)
{

}

double ghost::findDistance(coords positions)
{

}

void ghost::checkPacMan(object *board[][X_DIMENSION], coords newDirect)
{

}

void ghost::checkPacMan(object *board[][X_DIMENSION], directions direction)
{

}

bool ghost::atIntersection(object* board[][X_DIMENSION], directions direction){

    int exits = 0;
    // UP
    if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;
    // RIGHT
    if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;
    // DOWN
    if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;
    // LEFT
    if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;
    if(exits > 2)
        return true;
    else
        return false;

}// end atIntersection
