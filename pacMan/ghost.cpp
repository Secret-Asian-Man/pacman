#include "ghost.h"
#include "constants.h"
#include <cmath>
#include <deque>

ghost::ghost(coords position, char ghostType/*, pacman *pacptr*/):object(position,GHOST)
{
    _ghostType=ghostType;
    _ghostState=chaseMode;
    _ghostDirection=goUp;
    //    _pacptr=pacptr;
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
        _ghostState=scaredMode;
    }
    else
    {
        //cout<<"age: "<<object::get_age()<<endl;
        if(object::get_age()<SCATTER_TIME)
        {
            //scatter
            _ghostState=scatterMode;

        }

        if (object::get_age()>SCATTER_TIME && object::get_age()<SCATTER_TIME+CHASE_TIME)
        {
            //chase
            _ghostState=chaseMode;
        }
        if(object::get_age()>=SCATTER_TIME+CHASE_TIME)
        {
            object::reset_age();

        }
    }

    coords newDirect;
    if(atIntersection(board))
    {
//        cout<<"at Inter : "<<endl;
        newDirect = Intersection(board,_ghostDirection);

        if (_ghostState!=scaredMode)
        {
//            cout<<"";newDirect.print_xy();cout<<endl;
            directions hold = findDirection(newDirect);
            checkPacMan(board, hold);
        }

        object::move(board, pellets, newDirect);
    }// end if
    else
    {
        if (_ghostState!=scaredMode)
        {
            checkPacMan(board, _ghostDirection);
        }

        object::move( board, pellets, _ghostDirection);
    }

    object::increment_age();




}

coords ghost::Intersection(object *board[][X_DIMENSION], directions ghostDirection)
{
    // checks surrounding positions for more than 1 exit.
    // cannot be opposite direction that it is going
    std::deque<coords> exits;

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

//    for (int i=0;i<exits.size();i++)
//    {
//        cout<<"coord: "; exits[i].print_xy();
//        cout<<" distance: "<<findDistance(exits[i],coords(0,0));
//        cout<<" direction: "<<findDirection(exits[i]);
//        cout<<endl<<endl;

//    }



    coords newCoord = choseDirection(exits, exits.size());

    _ghostDirection=findDirection(newCoord);

    //    cout<<"DEBUG ghost direction: ";cout<<_ghostDirection<<endl;
    //    cout<<"DEBUG oldCoord: ";_position.print_xy();cout<<endl;cout<<endl;
    //    cout<<"DEBUG newCoord: ";newCoord.print_xy();cout<<endl;cout<<endl;



    return newCoord;
}


coords ghost::choseDirection(deque<coords> exits, int vectorSize)
{
    double shortestDistance=0;
    double compare=0;
    coords nearestCoords;

    coords hold = exits.front();
    exits.pop_front();
    vectorSize--;


    if(_ghostState == chaseMode){
        compare = findDistance(hold, coords(26,29));//previously object::get_spawnPosition()
    }
    if(_ghostState == scatterMode){
        compare = findDistance(hold, object::get_spawnPosition());//previously coords(26,29)
    }

    shortestDistance = compare;
    nearestCoords = hold;

    // get a set of coords from vector
    while(vectorSize > 0){

//        cout<<_ghostState<<endl;
        // check front  - get the coords
        hold = exits.front();

        // pop that set of coords
        exits.pop_front();
        // decrease vector size
        vectorSize--;

        if(_ghostState == chaseMode)
        {

            compare = findDistance(hold, object::get_spawnPosition());//previously coords(26,29)
        }
        if(_ghostState == scatterMode)
        {

            compare = findDistance(hold, coords(26,29));//previously object::get_spawnPosition()
        }

//        cout<<"DEBUG shortestDistance: "<<shortestDistance<<endl;
//        cout<<"DEBUG compare: "<<compare<<endl;

        if(compare < shortestDistance){
            shortestDistance = compare;
            // cout<<"DEBUG shortestDistance: "<<shortestDistance<<endl;
            nearestCoords = hold;
        }


    }// end while


//    cout<<"coord2: "; nearestCoords.print_xy();
//    cout<<" distance2: "<<findDistance(nearestCoords,coords (0,0));
//    cout<<" direction2: "<<findDirection(nearestCoords);
//    cout<<endl<<endl;


    return nearestCoords;


}

double ghost::findDistance(coords fromHere, coords toHere)
{
    double distance;
    return distance = sqrt(pow(toHere.get_x() - fromHere.get_x(),2) + pow(toHere.get_y() - fromHere.get_y(),2));


}


void ghost::checkPacMan(object *board[][X_DIMENSION], directions direction)
{

    // up = 0, right = 1, down = 2, left = 3
    switch(direction){

    //================ up =====================
    case goUp:

        if (board[_position.get_y()-1][_position.get_x()]!=NULL)
        {
            if(board[_position.get_y()-1][_position.get_x()]->getType() == PACMAN ){
                board[_position.get_y()-1][_position.get_x()]->die(board);
                // decrement pellet
            }// end if
        }


        break;


        //================ right =====================
    case goRight:

        if (board[_position.get_y()][_position.get_x()+1]!=NULL)
        {
            if(board[_position.get_y()][_position.get_x()+1]->getType() == PACMAN )
            {
                board[_position.get_y()][_position.get_x()+1]->die(board);
            }
        }// end if


        break;

        //================ down =====================
    case goDown:

        if (board[_position.get_y()+1][_position.get_x()]!=NULL)
        {
            if(board[_position.get_y()+1][_position.get_x()]->getType() == PACMAN ){
                board[_position.get_y()+1][_position.get_x()]->die(board);

            }

        }// end if

        break;

        //================ left =====================
    case goLeft:

        if (board[_position.get_y()][_position.get_x()-1]!=NULL)
        {
            if(board[_position.get_y()][_position.get_x()-1]->getType() == PACMAN ){
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

bool ghost::atIntersection(object* board[][X_DIMENSION])
{

    int exits = 0;
    // UP
    if(_ghostDirection == goUp && board[_position.get_y()-1][_position.get_x()]!=NULL)
        exits++;

    if(board[_position.get_y()-1][_position.get_x()]==NULL || board[_position.get_y()-1][_position.get_x()]->getType()==PACMAN){

        exits++;
    }// end if

    // RIGHT
    if(_ghostDirection == goRight && board[_position.get_y()][_position.get_x()+1]!=NULL)
        exits++;
    if(board[_position.get_y()][_position.get_x()+1]==NULL || board[_position.get_y()][_position.get_x()+1]->getType()==PACMAN)
        exits++;

    // DOWN
    if(_ghostDirection == goDown && board[_position.get_y()+1][_position.get_x()]!=NULL)
        exits++;
    if(board[_position.get_y()+1][_position.get_x()]==NULL || board[_position.get_y()+1][_position.get_x()]->getType()==PACMAN)
        exits++;

    // LEFT
    if(_ghostDirection == goLeft && board[_position.get_y()][_position.get_x()-1]!=NULL)
        exits++;
    if(board[_position.get_y()][_position.get_x()-1]==NULL || board[_position.get_y()][_position.get_x()-1]->getType()==PACMAN)
        exits++;
    if(exits < 2 ){
        if (/*next position is not NULL*/true)
        {

        }
    }

    if(exits > 2)
        return true;
    else
        return false;
}

void ghost::scatter(object *board[][X_DIMENSION], coords scatterPoint)
{

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
