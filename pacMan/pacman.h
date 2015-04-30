#ifndef PACMAN_H
#define PACMAN_H
#include "object.h"
#include "coords.h"

class pacman: public object
{
public:
    pacman(coords position);
    ~pacman();

    void die(object* board[][X_DIMENSION]);
    void move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice);
    void checkPellet(object* pellet[][X_DIMENSION], directions choice);

private:

    int _direction;
    int _lives;
    char* _fileName;
};

#endif // PACMAN_H
