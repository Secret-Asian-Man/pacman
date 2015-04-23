#ifndef BOARDERS_H
#define BOARDERS_H
#include "object.h"
#include "coords.h"

class boarders: public object
{
public:
    boarders(coords xy);
    ~boarders();
};

#endif // BOARDERS_H
