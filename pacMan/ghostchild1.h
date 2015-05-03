#ifndef GHOSTCHILD1_H
#define GHOSTCHILD1_H
#include "ghost.h"

class ghostChild1:public ghost
{
public:
    ghostChild1(coords position);
    ~ghostChild1();

    //main functions
    void move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions direction);

private:
    char* _fileName;

};

#endif // GHOSTCHILD1_H
