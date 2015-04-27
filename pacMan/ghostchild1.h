#ifndef GHOSTCHILD1_H
#define GHOSTCHILD1_H
#include "ghost.h"

class ghostChild1:public ghost
{
public:
    ghostChild1(coords position);
    ~ghostChild1();

private:
    char* _fileName;

};

#endif // GHOSTCHILD1_H
