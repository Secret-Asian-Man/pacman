#include "object.h"
#include <iostream>

object::object(coords xy, char objectType, int age, bool hasMoved, int speed)
{
    _xy=xy;
    _objectType=objectType;
    _age=age;
    _hasMoved=hasMoved;
    _speed=speed;

}

object::~object()
{

}

void object::move(object* board[][Y_DIMENSION], int direction)
{
    coords temp(_xy.get_x(),_xy.get_y());

    // up = 0, right = 1, down = 2, left = 3
    switch(direction){


        //================ up =====================
        case '0':

            board[temp.get_x()][temp.get_y()+1] = board[_xy.get_x()][_xy.get_y()];
            if(isNULL(board, temp)){
                board[_xy.get_x()][_xy.get_y()] = NULL;
                _xy.set_x(temp.get_x());
                _xy.set_y(temp.get_y());

                //set has moved to true;
                _hasMoved = true;
            }// end if

        break;


        //================ right =====================
        case '1':

            board[temp.get_x()+1][temp.get_y()] = board[_xy.get_x()][_xy.get_y()];
            if(isNULL(board, temp)){
                board[_xy.get_x()][_xy.get_y()] = NULL;
                _xy.set_x(temp.get_x());
                _xy.set_y(temp.get_y());

                //set has moved to true;
                _hasMoved = true;
            }// end if


        break;

        //================ down =====================
        case '2':

            board[temp.get_x()][temp.get_y()-1] = board[_xy.get_x()][_xy.get_y()];
           if(isNULL(board, temp)){
               board[_xy.get_x()][_xy.get_y()] = NULL;
               _xy.set_x(temp.get_x());
               _xy.set_y(temp.get_y());

               //set has moved to true;
               _hasMoved = true;
           }// end if

        break;

        //================ left =====================
        case '3':

            board[temp.get_x()-1][temp.get_y()] = board[_xy.get_x()][_xy.get_y()];
            if(isNULL(board, temp)){
              board[_xy.get_x()][_xy.get_y()] = NULL;
              _xy.set_x(temp.get_x());
              _xy.set_y(temp.get_y());

              //set has moved to true;
              _hasMoved = true;
            }// end if
        break;

        default:

            // direction is incorrect
            //cout<<"*** move error ***"<<endl;
            break;



    }// end switch

}
bool object::isNULL(object* board[][Y_DIMENSION], coords checkHere){
    if(board[checkHere.get_x()][checkHere.get_y()] == NULL)
        return true;
    else
        return false;
}// end check pos

void object::die()
{

}

int object::getType(){
    return _objectType;
}
