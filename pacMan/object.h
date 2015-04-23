#ifndef OBJECT_H
#define OBJECT_H
#include "coords.h"

class object
{
public:
    object(coords xy, char objectType, int age=0, bool hasMoved=false, int speed=1);
    ~object();

    void virtual move();
    void virtual die();

private:
    coords _xy;
    char _objectType;
    int _age;
    bool _hasMoved;
    int _speed;

};

#endif // OBJECT_H
