#include "game.h"
#include "constants.h"
#include "grid.h"

game::game()
{
    _time=Time::Zero;

    setWindow();
    gameStart();

}

game::~game()
{

}

void game::setWindow()
{
    _window.create(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT+HUD_SIZE),GAME_TITLE);
}

void game::gameStart()
{
    initialMove();



    while (_window.isOpen()) //and game is not paused do these. The keyEvents() is what changes the movement input, and then afterwards is it simply displayed in sfml
    {
        while(_window.pollEvent(_event))
        {
            keyEvents();
        }

        _time=_clock.getElapsedTime();
        if (_time.asMilliseconds()>=RATE-_time.asMilliseconds())
        {
            _gameBoard.step(); //the brains
            _clock.restart();

            draw();
            display();

        }

    }
}

void game::initialMove()
{
    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            if (_gameBoard._board[i][j]!=NULL)
            {
                //the line below needs to be in a diff functions to initialize, no looping allowed@@@@
                // _gameBoard._board[i][j]->get_position().print_xy();
                _gameBoard._board[i][j]->_sprite.setPosition(_gameBoard._board[i][j]->get_position().get_x()*BOX_SIZE,
                                                             _gameBoard._board[i][j]->get_position().get_y()*BOX_SIZE);
            }

            if (_gameBoard._pellets[i][j]!=NULL)
            {
                //the line below needs to be in a diff functions to initialize, no looping allowed@@@@
                // _gameBoard._board[i][j]->get_position().print_xy();
                _gameBoard._pellets[i][j]->_sprite.setPosition(_gameBoard._pellets[i][j]->get_position().get_x()*BOX_SIZE,
                                                             _gameBoard._pellets[i][j]->get_position().get_y()*BOX_SIZE);
            }
        }
    }
}

void game::keyEvents()
{
    while(_window.pollEvent(_event))
    {
        if (_event.type==Event::Closed) //if X button is pressed close the window
        {
            _window.close();
            cout<<"close button click"<<endl;
        }

        switch (_event.key.code) //takes in user inputs and performs actions
        {
        case Keyboard::Escape:
            cout<<"esc button pressed"<<endl;
            _window.close();
            break;

        case Keyboard::A:
        case Keyboard::Left:
            cout<<"Left button pressed"<<endl;
            _gameBoard.set_directions(goLeft); //send int 3
            break;

        case Keyboard::D:
        case Keyboard::Right:
            cout<<"Right button pressed"<<endl;
            _gameBoard.set_directions(goRight); //send int 1
            break;

        case Keyboard::W:
        case Keyboard::Up:
            cout<<"Up button pressed"<<endl;
            _gameBoard.set_directions(goUp); //sends int 0
            break;

        case Keyboard::S:
        case Keyboard::Down:
            cout<<"Down button pressed"<<endl;
            _gameBoard.set_directions(goDown); //sends int 2
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

    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            if (_gameBoard._board[i][j]!=NULL)
            {

                _window.draw(_gameBoard._board[i][j]->_sprite);
            }
            if (_gameBoard._pellets[i][j]!=NULL)
            {
                _window.draw(_gameBoard._pellets[i][j]->_sprite);
            }
        }
    }
}

void game::display()
{
    _window.display();
}

