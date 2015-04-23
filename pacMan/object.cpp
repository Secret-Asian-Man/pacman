#include "object.h"


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

void object::move()
{

}

void object::die()
{

}

