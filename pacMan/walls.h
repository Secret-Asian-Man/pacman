#ifndef WALLS_H
#define WALLS_H
#include "object.h"

class walls: public object
{
public:
    walls(coords position);
    ~walls();
};

#endif // WALLS_H
