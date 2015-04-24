#ifndef OBJECT_H
#define OBJECT_H
#include "coords.h"

class object
{
public:
    //constructors
    object(coords position, char objectType, int age=0, bool hasMoved=false, int speed=1);

    //destructor
    ~object();

    //accessors
    coords get_position();
    char virtual get_objectType();
    int get_age();
    bool get_hasmoved();
    int get_speed();

    //mutators
    void set_position(coords position);
    void set_objectType(char objectType);
    void set_age(int age);
    void set_hasMoved(bool hasMoved);
    void set_speed(int speed);

    //main functions
    void virtual move();
    void virtual die();

private:
    coords _position;
    char _objectType;
    int _age;
    bool _hasMoved;
    int _speed;

};

#endif // OBJECT_H
