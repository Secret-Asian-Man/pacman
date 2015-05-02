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


void object::move(object* board[][X_DIMENSION],object* pellets[][X_DIMENSION], coords newDirect){

cout<<"DEBUG newDirect: ";newDirect.print_xy();cout<<endl;
    if(isNULL(board, newDirect)){
        board[newDirect.get_y()][newDirect.get_x()] = board[_position.get_y()][_position.get_x()];

        board[_position.get_y()][_position.get_x()] = NULL;
        _position.set_x(newDirect.get_x());
        _position.set_y(newDirect.get_y());

        //set has moved to true;
    }// end if
    else
    {

    }


}
void object::move(object* board[][X_DIMENSION],object* pellets[][X_DIMENSION], directions direction)
{

    coords newPos(_position.get_x(),_position.get_y()); //starts at pacman's current position
    // up = 0, right = 1, down = 2, left = 3
    switch(direction){

    case goUp:
        newPos.set_y(newPos.get_y()-1);
        break;

    case goRight:
        newPos.set_x(newPos.get_x()+1);
        break;

    case goDown:
        newPos.set_y(newPos.get_y()+1);
        break;

    case goLeft:
        newPos.set_x(newPos.get_x()-1);
        break;

    default:
        break;
    }// end switch

    if(isNULL(board, newPos)){
        board[newPos.get_y()][newPos.get_x()] = board[_position.get_y()][_position.get_x()];

        board[_position.get_y()][_position.get_x()] = NULL;
        _position.set_x(newPos.get_x());
        _position.set_y(newPos.get_y());
    }// end if
}
bool object::isNULL(object* board[][X_DIMENSION], coords checkHere){
    if(board[checkHere.get_y()][checkHere.get_x()] == NULL)
    {
        cout<<"DEBUG RETURNING TRUE: "<<endl;
        return true;
    }
    else
    {
        cout<<"DEBUG RETURNING false: "<<endl;

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

void object::reset_age()
{
    _age=0;
}

void object::increment_age()
{
    _age++;
}

void object::decrement_age()
{
    _age--;
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
    _sprite.setOrigin(BOX_SIZE/2,BOX_SIZE/2);

}
