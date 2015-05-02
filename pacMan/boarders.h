#ifndef BOARDERS_H
#define BOARDERS_H
#include "object.h"
#include "coords.h"

class boarders: public object
{
public:
    boarders(coords position);
    ~boarders();

    void move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice);

    char* _fileName;
};

#endif // BOARDERS_H
