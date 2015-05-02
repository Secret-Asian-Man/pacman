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
    pacManState get_pacState();

    //mutators
    void set_pacmanDirection(directions other);
    void set_lives(int other);
    void set_pacState(pacManState other);


    void die(object* board[][X_DIMENSION]);
    void move(object *board[][X_DIMENSION], object* pellets[][X_DIMENSION], directions choice);
    char checkPellet(object* pellet[][X_DIMENSION], directions choice);

private:

    int _lives;
    pacManState _pacState;
    char* _fileName;
    directions _pacmanDirection;

};

#endif // PACMAN_H
