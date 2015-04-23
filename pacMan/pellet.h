#ifndef PELLET_H
#define PELLET_H
#include "object.h"

class pellet: public object
{
public:
    pellet(coords position);
    ~pellet();
};

#endif // PELLET_H
