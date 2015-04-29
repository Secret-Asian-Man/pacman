#ifndef PACMAN_H
#define PACMAN_H
#include "object.h"
#include "coords.h"

class pacman: public object
{
public:
    pacman(coords position);
    ~pacman();

    int checkValid(int direction);
    void command(object *board[][X_DIMENSION], int direction);
    void die(object* board[][X_DIMENSION]);
    void move(object *board[][X_DIMENSION], int direction);

private:

    int _direction;
    int _lives;
    char* _fileName;
};

#endif // PACMAN_H
