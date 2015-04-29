#ifndef WARP_H
#define WARP_H
#include "object.h"

class warp: public object
{
public:
    warp(coords position);
    ~warp();

private:
    char* _fileName;
    warp* other; //have this warp point to the other warp, ask David

};

#endif // WARP_H
