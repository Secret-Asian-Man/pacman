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

};

#endif // WARP_H
