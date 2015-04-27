#ifndef DOOR_H
#define DOOR_H
#include "coords.h"
#include "object.h"
class door:public object
{
public:
    door(coords position);
    ~door();

private:
    char* _fileName;
};

#endif // DOOR_H
