#include "boarders.h"
#include "object.h"
#include "constants.h"

boarders::boarders(coords position):object(position,BOARDERS)
{
    char fileName[]="boarders.png";
    _fileName=fileName;
    object::loadTexture(_fileName);
}

boarders::~boarders()
{

}

