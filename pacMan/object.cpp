#include "object.h"


object::object(coords position, char objectType, int age, bool hasMoved, int speed)
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

void object::move()
{

}

void object::die()
{

}

