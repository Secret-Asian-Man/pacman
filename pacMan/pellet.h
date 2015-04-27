#ifndef PELLET_H
#define PELLET_H
#include "object.h"

class pellet: public object
{
public:
    pellet(coords position);
    ~pellet();

private:
    char* _fileName;

};

#endif // PELLET_H
