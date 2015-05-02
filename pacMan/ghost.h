#ifndef GHOST_H
#define GHOST_H
#include "object.h"
#include "pacman.h"
#include <vector>
using namespace std;

class ghost: public object
{
public:
    ghost(coords position, char ghostType);
    ~ghost();

    //accessors
    char get_objectType();
    ghostState get_ghostState();

    //mutators
    void set_ghostState(ghostState other);

    //main functions
    void move(object *board[][X_DIMENSION],object *pellets[][X_DIMENSION], directions direction);
    coords Intersection(object* board[][X_DIMENSION], directions ghostDirection);
    coords choseDirection(vector<coords> exits, int vectorSize);
    double findDistance(coords positions);
    void checkPacMan(object* board[][X_DIMENSION], coords newDirect);
    void checkPacMan(object* board[][X_DIMENSION], directions direction);
    bool atIntersection(object* board[][X_DIMENSION]);

private:
    char _ghostType;
    ghostState _ghostState;
    directions _ghostDirection;
    directions findDirection(coords newCoords);
    pacman* _pacptr;

};

#endif // GHOST_H
