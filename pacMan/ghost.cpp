#include "ghost.h"
#include "constants.h"
ghost::ghost(coords position,char ghostType):object(position,GHOST)
{
    _ghostType=ghostType;
    _emotionalState=chase;
}

ghost::~ghost()
{

}

char ghost::get_objectType()
{
    return _ghostType;
}

ghostEmotionalState ghost::get_emotionalState()
{
    return _emotionalState;
}

void ghost::set_emotionalState(ghostEmotionalState other)
{
    _emotionalState=other;
}

