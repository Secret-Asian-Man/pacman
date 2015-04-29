#include "game.h"
#include "constants.h"
#include "grid.h"

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
    initialMove();

    while (_window.isOpen())
    {
        keyEvents();
        draw();
        display();
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

        default:
            //do nothing
            break;
        }

    }
}

void game::draw()
{
    _window.clear();

    //    sf::CircleShape shape(100.f);
    //    shape.setFillColor(sf::Color::Green);
    //    _window.draw(shape);


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

