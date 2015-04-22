#include "random.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

random::random()
{

    _lo=0;
    _hi=1000;

    _randomNumber=randomize(_lo,_hi);

}

random::random(int lo,int hi)
{

    _lo=lo;
    _hi=hi;

    _randomNumber=randomize(_lo,_hi);

}

int random::getRandomNumber()
{
    return _randomNumber;
}

int random::setLow(int input)
{
    _lo=input;
}

int random::setHigh(int input)
{
    _hi=input;
}

void random::newRandom()
{
    _randomNumber=randomize(_lo,_hi);

}

void random::printRandom()
{
    std::cout<<_randomNumber;
}


/***********************************
 * Function: Random
 * Purpose: generates a random number
 * Parameters: int lo, int hi
 * Returns: a random number
 * Notes: Needs   declaration: "srand(time(0));", " #include <time.h>", "#include <cstdlib>"
 * ***********************************/
int random::randomize(int lo, int hi)
{
    int range = hi-lo+1;
    int randomNumber = lo + (rand() % range);

    //    int randomNumber= rand()%hi+lo; //gives a random number between lo and hi, inclusive.

    return randomNumber;
}


