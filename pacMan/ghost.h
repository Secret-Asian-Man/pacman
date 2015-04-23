#ifndef GHOST_H
#define GHOST_H
#include "object.h"

class ghost: public object
{
public:
    ghost(coords position);
    ~ghost();
};

#endif // GHOST_H
