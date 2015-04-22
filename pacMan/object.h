#ifndef OBJECT_H
#define OBJECT_H
#include "coords.h"

class object: public object
{
public:
    object();
    ~object();

    void virtual move();
    void virtual die();

private:
    coords _xy;
    bool _hasMoved;
};

#endif // OBJECT_H
