#ifndef GAME_H
#define GAME_H
#include "grid.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "constants.h"
#include <vector>

using namespace std;
using namespace sf;

class game
{
public:
    game();
    ~game();

    //accessors

    //mutators


    grid _gameBoard;

private:
    //private variables
    RenderWindow _window;
    Music _music;
    Event _event;
    Clock _clock;
    Time _time;
    bool _paused;
    //RectangleShape ; //gotta be a better way to draw the shapes

    //private functions
    void setWindow(); //initializes the window
    void gameStart(); //the actual game loop (High level)
    void updateLocation();
    void keyEvents(); //takes user inputs to do actions
    void draw(); //draws figures to the screen
    void display(); //displays the screen
};

#endif // GAME_H
