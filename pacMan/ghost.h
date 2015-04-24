#ifndef GHOST_H
#define GHOST_H
#include "object.h"

class ghost: public object
{
public:
    ghost(coords position, char ghostType);
    ~ghost();
    char get_objectType();

private:
    char _ghostType;
};

#endif // GHOST_H
