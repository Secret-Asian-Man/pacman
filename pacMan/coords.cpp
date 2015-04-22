#include "coords.h"
#include <iostream>

coords::coords()
{

    _x=0;
    _y=0;

}

coords::coords(int x, int y)
{
    _x=x;
    _y=y;
}

coords::coords(const coords &other)
{
    _x=other._x;
    _y=other._y;
}

coords& coords::operator =(const coords& other)
{
    _x=other._x;
    _y=other._y;
}
bool coords::operator ==(const coords& other)
{
    if (_x==other._x && _y==other._y)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool coords::operator !=(const coords& other)
{
    if (_x==other._x && _y==other._y)
    {
        return false;
    }

    else
    {
        return true;
    }
}


int coords::get_x()
{
    return _x;
}

int coords::get_y()
{
    return _y;
}


void coords::set_x(int x)
{
    _x=x;
}

void coords::set_y(int y)
{
    _y=y;
}

void coords::set_xy(int x, int y)
{
    _x=x;
    _y=y;
}


void coords::print_x()
{
    std::cout<<_x;
}

void coords::print_y()
{
    std::cout<<_y;
}

void coords::print_xy()
{
    std::cout<<"("<<_x<<","<<_y<<")";
}
