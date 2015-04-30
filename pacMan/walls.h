#ifndef WALLS_H
#define WALLS_H
#include "object.h"
#include <SFML/Graphics.hpp>

class walls: public object
{
public:
    walls(coords position);
    ~walls();

    void die(object *board[][X_DIMENSION]);

private:
    char* _fileName;

};

#endif // WALLS_H
