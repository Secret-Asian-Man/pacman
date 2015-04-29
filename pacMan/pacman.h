#ifndef PACMAN_H
#define PACMAN_H
#include "object.h"
#include "coords.h"

class pacman: public object
{
public:
    pacman(coords position);
    ~pacman();

    void command(object *board[][X_DIMENSION], int direction);
    int checkValid(int direction);

    void die(object* board[][X_DIMENSION]);

private:

    int _direction;
    int _lives;
    char* _fileName;
};

#endif // PACMAN_H
