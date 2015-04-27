#include "game.h"
#include "constants.h"

game::game()
{
    setWindow();
    gameStart();

}

game::~game()
{

}


void game::setWindow()
{
    _window.create(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),GAME_TITLE);
}

void game::gameStart()
{
    while (_window.isOpen())
    {
        keyEvents();
        draw();
        display();
    }
}

void game::keyEvents()
{
    while(_window.pollEvent(_event))
    {
        if (_event.type==Event::Closed) //if X button is pressed close the window
        {
            _window.close();
        }

        switch (_event.key.code) //takes in user inputs and performs actions
        {
        case Keyboard::Escape:
            _window.close();
            break;

        default:
            //do nothing
            break;
        }

    }
}

void game::draw()
{
    _window.clear();

    //_window.draw();
}

void game::display()
{
    _window.display();
}

