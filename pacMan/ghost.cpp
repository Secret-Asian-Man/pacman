#include "ghost.h"
#include "constants.h"
ghost::ghost(coords position,char ghostType):object(position,GHOST)
{
    _ghostType=ghostType;
}

ghost::~ghost()
{

}

char ghost::get_objectType()
{
    return _ghostType;
}

