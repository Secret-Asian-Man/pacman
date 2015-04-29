#ifndef GHOST_H
#define GHOST_H
#include "object.h"
enum ghostEmotionalState{
    invalid=-1,
    chase=0,
    scatter=1,
    scared=2
};
class ghost: public object
{
public:
    ghost(coords position, char ghostType);
    ~ghost();

    //accessors
    char get_objectType();
    ghostEmotionalState get_emotionalState();

    //mutators
    void set_emotionalState(ghostEmotionalState other);

private:
    char _ghostType;
    ghostEmotionalState _emotionalState;
};

#endif // GHOST_H
