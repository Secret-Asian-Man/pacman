#ifndef GHOSTCHILD2_H
#define GHOSTCHILD2_H
#include "ghost.h"

class ghostChild2:public ghost
{
public:
    ghostChild2(coords position);
    ~ghostChild2();

private:
    char* _fileName;

};

#endif // GHOSTCHILD2_H
