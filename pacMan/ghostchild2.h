#ifndef GHOSTCHILD2_H
#define GHOSTCHILD2_H
#include "ghost.h"

class ghostChild2:public ghost
{
public:
    ghostChild2(coords position/*,pacman* pacptr*/);
    ~ghostChild2();

    //main functions
    void move(object *board[][X_DIMENSION], object *pellets[][X_DIMENSION], directions direction);

private:
    char* _fileName;

};

#endif // GHOSTCHILD2_H
