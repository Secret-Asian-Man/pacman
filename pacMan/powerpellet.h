#ifndef POWERPELLET_H
#define POWERPELLET_H
#include "pellet.h"

class powerPellet: public object
{
public:
    powerPellet(coords position);
    ~powerPellet();

private:
    char* _fileName;

};

#endif // POWERPELLET_H
