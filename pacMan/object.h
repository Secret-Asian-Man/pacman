#ifndef OBJECT_H
#define OBJECT_H
#include "coords.h"
#include "constants.h"
class object
{
public:
    object(coords xy, char objectType, int age=0, bool hasMoved=false, int speed=1);
    ~object();

    void virtual move(object* board[][Y_DIMENSION],int direction);
    void virtual die();
    bool virtual isNULL(object* board[][Y_DIMENSION], coords checkHere);
    int getType();


private:
    coords _xy;
    int _objectType;
    int _age;
    bool _hasMoved;
    int _speed;

};

#endif // OBJECT_H
