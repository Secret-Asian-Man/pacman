#include "object.h"
#include <iostream>
using namespace std;


//might be possible to have the child give the parent a char[](cstring), so the parent can load the correct data.
//1.) parent is created with no textures.
//2.) child is created with data about the texture.
//3.) child constructor calls the parent's loadTexture(), giving the parent a cstring.
//4.) child calls the parents loadSprite()
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

sf::Sprite object::get_sprite()
{
    return _sprite;
}

sf::Texture object::get_texture()
{
    return _texture;
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

void object::move(object* board[][X_DIMENSION],object* pellets[][X_DIMENSION], directions direction)
{
    //    std::cout<<"DEBUG object::move: "<<std::endl;
    coords newPos(_position.get_x(),_position.get_y()); //starts at pacman's current position
    // up = 0, right = 1, down = 2, left = 3
    switch(direction){


    //================ up =====================
    case goUp:

        newPos.set_y(newPos.get_y()-1);


        break;


        //================ right =====================
    case goRight:
        cout<<"DEBUG goRight: "<<endl;

        cout<<"old position: ";_position.print_xy();
        newPos.set_x(newPos.get_x()+1);
        cout<<"new position: ";newPos.print_xy(); cout<<endl;

        break;

        //================ down =====================
    case goDown:

        newPos.set_y(newPos.get_y()+1);

        break;

        //================ left =====================
    case goLeft:
        newPos.set_x(newPos.get_x()-1);
        break;

    default:

        // direction is incorrect
        //cout<<"*** move error ***"<<endl;
        break;



    }// end switch

    //std::cin.get();

    if(isNULL(board, newPos)/*true*/){
        board[newPos.get_y()][newPos.get_x()] = board[_position.get_y()][_position.get_x()];

        board[_position.get_y()][_position.get_x()] = NULL;
        _position.set_x(newPos.get_x());
        _position.set_y(newPos.get_y());




        //set has moved to true;
        // _hasMoved = true;

    }// end if

}
bool object::isNULL(object* board[][X_DIMENSION], coords checkHere){
    if(board[checkHere.get_y()][checkHere.get_x()] == NULL)
    {
        cout<<"DEBUG returning TRUE "<<endl;

        return true;
    }
    else
    {
        cout<<"DEBUG returning FALSE "<<endl;
        return false;
    }
}// end check pos

void object::die(object* board[][X_DIMENSION])
{
    delete board[_position.get_y()][_position.get_x()];
    board[_position.get_y()][_position.get_x()]=NULL;
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
