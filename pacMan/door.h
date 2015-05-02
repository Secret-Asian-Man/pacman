#ifndef DOOR_H
#define DOOR_H
#include "coords.h"
#include "object.h"
class door:public object
{
public:
    door(coords position);
    ~door();

    //accessors


    //mutators

    //main functions
void move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice);

private:
    char* _fileName;
};

#endif // DOOR_H
