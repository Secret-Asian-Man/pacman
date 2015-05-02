#include "ghost.h"
#include "constants.h"
#include <cmath>

ghost::ghost(coords position, char ghostType):object(position,GHOST)
{
    _ghostType=ghostType;
    _ghostState=chase;
    _ghostDirection=goDown;
}

ghost::~ghost()
{

}

char ghost::get_objectType()
{
    return _ghostType;
}

ghostState ghost::get_ghostState()
{
    return _ghostState;
}

void ghost::set_ghostState(ghostState other)
{
    _ghostState=other;
}

void ghost::move(object *board[][X_DIMENSION],object* pellets[][X_DIMENSION], directions direction) //[direction] is not used
{
    if(/*_pacptr->get_pacState()==superPacman*/ false) //FIXXXXXXXXX _pacptr
    {
        _ghostState=scared;
    }
    else
    {
        _ghostState=chase;
    }

    coords newDirect;
    if(atIntersection(board))
    {
        newDirect = Intersection(board,_ghostDirection);

        if (_ghostState!=scared)
        {
            //checkPacMan(board, newDirect);
        }

        object::move(board, pellets, newDirect);
    }// end if
    else
    {
        if (_ghostState!=scared)
        {
            //checkPacMan(board, _ghostDirection);

        }

        object::move( board, pellets, _ghostDirection);
    }


    object::increment_age();
}

coords ghost::Intersection(object *board[][X_DIMENSION], directions ghostDirection)
{
    // checks surrounding positions for more than 1 exit.
    // cannot be opposite direction that it is going
    std::vector<coords> exits;

    // should be able to call RIGHT==NULL || RIGHT=PACMAN


    // will check all positions except the opposite of the direction it is going
    // ex: if going left, right is not a move option

    // UP = 0; RIGHT = 1; DOWN = 2, LEFT = 3

    switch(ghostDirection)
    {
    case goUp:
        // UP
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()-1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()-1));
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()][_position.get_x()+1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()+1,_position.get_y()));
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()][_position.get_x()-1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()-1,_position.get_y()));
        break;

    case goRight:
        // UP
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()-1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()-1));
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()][_position.get_x()+1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()+1,_position.get_y()));
        // DOWN
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()+1));
        break;

    case goLeft:
        // UP
        if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()-1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()-1));
        // DOWN
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()+1));
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()][_position.get_x()-1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()-1,_position.get_y()));
        break;

    case goDown:
        // RIGHT
        if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()][_position.get_x()+1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()+1,_position.get_y()));
        // DOWN
        if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x(),_position.get_y()+1));
        // LEFT
        if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()][_position.get_x()-1]->getType()==PACMAN)
            exits.push_back(coords (_position.get_x()-1,_position.get_y()));
        break;
    }// end switch

    if (exits.size()==0)
    {
        return _position;
    }

    coords newCoord = choseDirection(exits, exits.size());
    //    coords newCoord = _position;

    _ghostDirection=findDirection(newCoord);

    cout<<"DEBUG ghost direction: ";cout<<_ghostDirection<<endl;
    cout<<"DEBUG oldCoord: ";_position.print_xy();cout<<endl;cout<<endl;
    cout<<"DEBUG newCoord: ";newCoord.print_xy();cout<<endl;cout<<endl;



    return newCoord;
}


coords ghost::choseDirection(vector<coords> exits, int vectorSize)
{
    double shortestDistance;
    coords nearestCoords;

    coords hold = exits.front();
    exits.pop_back();
    vectorSize--;
    shortestDistance = findDistance(hold);
    nearestCoords = hold;
    // get a set of coords from vector
    while(vectorSize > 0){

        // check front  - get the coords
        coords hold = exits.front();

        // pop that set of coords
        exits.pop_back();

        // decrease vector size
        vectorSize--;

        double compare = findDistance(hold);


        if(compare < shortestDistance){
            shortestDistance = compare;
            nearestCoords = hold;
        }


    }// end while

    return nearestCoords;


}

double ghost::findDistance(coords positions)
{

    double distance;
    return distance = sqrt(pow(positions.get_x() - 1,2) + pow(positions.get_y() - 1,2));


}

void ghost::checkPacMan(object *board[][X_DIMENSION], coords newDirect)
{
    if(board[newDirect.get_y()][newDirect.get_x()]->getType() == PACMAN )
    {
        board[newDirect.get_y()][newDirect.get_x()]->die(board);
    }

}

void ghost::checkPacMan(object *board[][X_DIMENSION], directions direction)
{

    // up = 0, right = 1, down = 2, left = 3
    switch(direction){

    //================ up =====================
    case goUp:

        if(board[_position.get_y()-1][_position.get_x()]->getType() == PACMAN ){
            board[_position.get_y()-1][_position.get_x()]->die(board);
            // decrement pellet
        }// end if

        break;


        //================ right =====================
    case goRight:

        if(board[_position.get_y()][_position.get_x()+1]->getType() == PACMAN ){
            board[_position.get_y()][_position.get_x()+1]->die(board);
            // decrement pellet
        }// end if


        break;

        //================ down =====================
    case goDown:

        if(board[_position.get_y()][_position.get_x()-1]->getType() == PACMAN ){
            board[_position.get_y()][_position.get_x()-1]->die(board);
            // decrement pellet
        }// end if

        break;

        //================ left =====================
    case goLeft:

        if(board[_position.get_y()][_position.get_x()-1]->getType() == PACMAN ){
            board[_position.get_y()][_position.get_x()-1]->die(board);
            // decrement pellet
        }// end if
        break;

    default:

        // direction is incorrect
        //cout<<"*** eat pellet error ***"<<endl;
        break;



    }// end switch

}

bool ghost::atIntersection(object* board[][X_DIMENSION])
{

    int exits = 0;
    // UP
    if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()-1][_position.get_x()]->getType()==PACMAN)
        exits++;
    // RIGHT
    if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()][_position.get_x()+1]->getType()==PACMAN)
        exits++;
    // DOWN
    if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;
    // LEFT
    if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()][_position.get_x()-1]->getType()==PACMAN)
        exits++;

    if(exits > 1)
        return true;
    else
        return false;
}

directions ghost::findDirection(coords newCoords)
{
    if(newCoords.get_x() > _position.get_x()){
        return goRight;
    }
    if(newCoords.get_x() < _position.get_x()){
        return goLeft;
    }
    if(newCoords.get_y() > _position.get_y()){
        return goDown;
    }
    if(newCoords.get_y() < _position.get_y()){
        return goUp;
    }
}
