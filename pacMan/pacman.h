#ifndef PACMAN_H
#define PACMAN_H
#include "object.h"
#include "coords.h"

class pacman: public object
{
public:
    pacman(coords position);
    ~pacman();

    //accessors
    directions get_pacmanDirection();
    int get_lives();

    //mutators
    void set_pacmanDirection(directions other);
    void set_lives(int other);



    void die(object* board[][X_DIMENSION]);
    void move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice);
    void checkPellet(object* pellet[][X_DIMENSION], directions choice);

private:

    int _lives;
    char* _fileName;
    directions _pacmanDirection;

};

#endif // PACMAN_H
