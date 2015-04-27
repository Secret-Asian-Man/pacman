#ifndef PACMAN_H
#define PACMAN_H
#include "object.h"
#include "coords.h"

class pacman: public object
{
public:
    pacman(coords position);
    ~pacman();

    void command(object *board[][Y_DIMENSION], int direction);
    int checkValid(int direction);

private:

    int _direction;
    char* _fileName;
};

#endif // PACMAN_H
