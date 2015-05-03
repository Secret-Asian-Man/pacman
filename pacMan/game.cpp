#include "game.h"
#include "constants.h"
#include "grid.h"

game::game()
{

    _window.setFramerateLimit(FRAME_RATE);
    _time=Time::Zero;
    _paused=false;

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
    while (_window.isOpen()) //and game is not paused do these. The keyEvents() is what changes the movement input, and then afterwards is it simply displayed in sfml
    {


        _time=_clock.getElapsedTime();
        if (_time.asMilliseconds()>=RATE-_time.asMilliseconds())
        {
            while(_window.pollEvent(_event))
            {
                keyEvents();
            }

            _gameBoard.step(); //the brains
            updateLocation();

            draw();
            display();



            _clock.restart();
        }
    }
}

void game::updateLocation()
{
    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            if (_gameBoard._board[i][j]!=NULL)
            {
                _gameBoard._board[i][j]->_sprite.setPosition(_gameBoard._board[i][j]->get_position().get_x()*BOX_SIZE,
                                                             _gameBoard._board[i][j]->get_position().get_y()*BOX_SIZE);

            }

            if (_gameBoard._pellets[i][j]!=NULL)
            {
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
            exit(0);
            //cout<<"close button click"<<endl;
        }

        switch (_event.key.code) //takes in user inputs and performs actions
        {
        case Keyboard::Escape:
            //cout<<"esc button pressed"<<endl;
            _window.close();
            exit(0);
            break;

        case Keyboard::A:
        case Keyboard::Left:
            // cout<<"Left button pressed"<<endl;
            _gameBoard.set_requestedDirection(goLeft); //send int 3
            break;

        case Keyboard::D:
        case Keyboard::Right:
            //cout<<"Right button pressed"<<endl;
            _gameBoard.set_requestedDirection(goRight); //send int 1
            break;

        case Keyboard::W:
        case Keyboard::Up:
            // cout<<"Up button pressed"<<endl;
            _gameBoard.set_requestedDirection(goUp); //sends int 0
            break;

        case Keyboard::S:
        case Keyboard::Down:
            // cout<<"Down button pressed"<<endl;
            _gameBoard.set_requestedDirection(goDown); //sends int 2
            break;

        case Keyboard::P:

            if (_paused==true)
            {
                _gameBoard.set_gameState(paused);
                _paused=!_paused;
            }
            else
            {
                _gameBoard.set_gameState(normal);
                _paused=!_paused;
            }



            break;
        default:
            //do nothing
            break;
        }






        //        if (_event.type==Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) //if X button is pressed close the window
        //        {
        //            _window.close();
        //            exit(0);
        //            //cout<<"close button click"<<endl;
        //        }

        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //        {
        //            _gameBoard.set_requestedDirection(goLeft); //send int 3
        //        }

        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        //        {
        //            _gameBoard.set_requestedDirection(goRight); //send int 3
        //        }

        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        //        {
        //            _gameBoard.set_requestedDirection(goUp); //send int 3
        //        }

        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        //        {
        //            _gameBoard.set_requestedDirection(goDown); //send int 3
        //        }
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

