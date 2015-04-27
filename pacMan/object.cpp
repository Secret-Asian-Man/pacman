#include "object.h"
#include <iostream>



//might be possible to have the child give the parent a char[](cstring), so the parent can load the correct data.
//1.) parent is created with no textures.
//2.) child is created with data about the texture.
//3.) child constructor calls the parent's loadTexture(), giving the parent a cstring.
//4.) parent creates a sprite from the texture
object::object(coords position, char objectType,int age, bool hasMoved, int speed)
{
    _position=position;
    _objectType=objectType;
    _age=age;
    _hasMoved=hasMoved;
    _speed=speed;
}

object::~object()
{

}

coords object::get_position()
{
    return _position;
}

char object::get_objectType()
{
    return _objectType;
}

int object::get_age()
{
    return _age;
}

bool object::get_hasmoved()
{
    return _hasMoved;
}

int object::get_speed()
{
    return _speed;
}

void object::set_position(coords position)
{
    _position=position;
}

void object::set_objectType(char objectType)
{
    _objectType=objectType;
}

void object::set_age(int age)
{
    _age=age;
}

void object::set_hasMoved(bool hasMoved)
{
    _hasMoved=hasMoved;
}

void object::set_speed(int speed)
{
    _speed=speed;
}

void object::move(object* board[][Y_DIMENSION], int direction)
{
//    coords temp(_position.get_x(),_position.get_y());

//    // up = 0, right = 1, down = 2, left = 3
//    switch(direction){


//        //================ up =====================
//        case '0':

//            board[temp.get_x()][temp.get_y()+1] = board[_position.get_x()][_position.get_y()];
//            if(isNULL(board, temp)){
//                board[_position.get_x()][_position.get_y()] = NULL;
//                _position.set_x(temp.get_x());
//                _position.set_y(temp.get_y());

//                //set has moved to true;
//                _hasMoved = true;
//            }// end if

//        break;


//        //================ right =====================
//        case '1':

//            board[temp.get_x()+1][temp.get_y()] = board[_position.get_x()][_position.get_y()];
//            if(isNULL(board, temp)){
//                board[_position.get_x()][_position.get_y()] = NULL;
//                _position.set_x(temp.get_x());
//                _position.set_y(temp.get_y());

//                //set has moved to true;
//                _hasMoved = true;
//            }// end if


//        break;

//        //================ down =====================
//        case '2':

//            board[temp.get_x()][temp.get_y()-1] = board_position[_position.get_y()];
//           if(isNULL(board, temp)){
//               board[_position.get_x()][_position.get_y()] = NULL;
//               _position.set_x(temp.get_x());
//               _position.set_y(temp.get_y());

//               //set has moved to true;
//               _hasMoved = true;
//           }// end if

//        break;

//        //================ left =====================
//        case '3':

//            board[temp.get_x()-1][temp.get_y()] = board[_position.get_x()][_position.get_y()];
//            if(isNULL(board, temp)){
//              board[_position.get_x()][_position.get_y()] = NULL;
//              _position.set_x(temp.get_x());
//              _position.set_y(temp.get_y());

//              //set has moved to true;
//              _hasMoved = true;
//            }// end if
//        break;

//        default:

//            // direction is incorrect
//            //cout<<"*** move error ***"<<endl;
//            break;



//    }// end switch

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

void object::loadTexture(char* fileName)
{
    if (_texture.loadFromFile(fileName)==false)
    {
        std::cout<<"Error 401: File Not Found"<<std::endl;
    }
}

void object::loadSprite()
{
    _sprite.setTexture(_texture);
}
