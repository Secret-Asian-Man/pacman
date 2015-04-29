#include "grid.h"
#include "boarders.h"
#include "door.h"
#include "ghostchild1.h"
#include "ghostchild2.h"
#include "pacman.h"
#include "pellet.h"
#include "powerpellet.h"
#include "walls.h"
#include "warp.h"


using namespace std;


grid::grid()
{
    _pelletCount=0;
    _gameState=normal;
    _pacmanDirection=none;
    initializeToNull();
    loadMap();


}

grid::~grid()
{
    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            //cout<<i<<","<<j<<endl;
            delete _board[i][j];
            delete _pellets[i][j];
        }
    }

}

int grid::get_pelletCount()
{
    return _pelletCount;
}

gameState grid::get_gameState()
{
    return _gameState;
}

directions grid::get_directions()
{
    return _pacmanDirection;
}

void grid::set_pelletCount(int other)
{
    _pelletCount=other;
}

void grid::set_gameState(gameState other)
{
    _gameState=other;
}

void grid::set_directions(directions other)
{
    _pacmanDirection=other;
}

void grid::step()
{
    if (_gameState==normal)
    {
        //before calling die function, check the oject's type. If the object is a pellet run decrement_pelletcount(),
        //else die normally.

        //call move pacMan's move function in here using _pacmanDirection
    }


}


void grid::show()
{
    cout<<"DEBUG grid::show() FIRED!!!: "<<endl;

    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            if (_board[i][j]!=NULL)
            {
                cout<<_board[i][j]->get_objectType();
            }
            else
                cout<<".";
        }
        cout<<endl;
    }

    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            if (_pellets[i][j]!=NULL)
            {
                cout<<_pellets[i][j]->get_objectType();
            }
            else
                cout<<".";
        }
        cout<<endl;
    }
}

void grid::increment_pelletCount()
{
    _pelletCount++;
}

void grid::decrement_pelletCount()
{
    _pelletCount--;
}

void grid::loadFile()
{
    //_mapData.open("Users\Les\Desktop\pacman\build-pacMan-Desktop_Qt_5_4_0_MinGW_32bit-Debug\PacManMap.txt");
    //_pelletData.open("Users\Les\Desktop\pacman\build-pacMan-Desktop_Qt_5_4_0_MinGW_32bit-Debug\PacManPellets.txt");
    _mapData.open("PacManMap.txt");
    _pelletData.open("PacManPellets.txt");

    if (_mapData.fail()) /*|| _pelletData.fail()) //checks file*/
    {
        cout<<endl<<"****** Could not open map file ******"<<endl;
        exit(0);
    }

    if (_pelletData.fail()) /*|| _pelletData.fail()) //checks file*/
    {
        cout<<endl<<"****** Could not open pellet file ******"<<endl;
        exit(0);
    }


}

void grid::loadMap()
{
    char singleChar;
    int x=0;
    int y=0;

    loadFile();

    while(!_mapData.eof()) //count starts from y:1-28, and x:1-31
    {
        _mapData.get(singleChar);

        switch (singleChar)
        {
        case PACMAN:
            _board[y][x]=new pacman(coords(x,y));
            x++;
            break;

        case GHOST_PELLET_POOPER:
            _board[y][x]=new ghostChild1(coords(x,y));
            x++;
            break;

        case GHOST_GATE_DROPPER:
            _board[y][x]=new ghostChild2(coords(x,y));
            x++;
            break;

        case WALLS:
            _board[y][x]=new walls(coords(x,y));
            x++;
            break;

        case DOOR:
            _board[y][x]=new door(coords(x,y));
            x++;
            break;

        case NULLED:
            _board[y][x]=NULL;
            x++;
            break;

        case WARP:
            _board[y][x]=new warp(coords(x,y));
            x++;
            break;

        case BOARDERS:
            //cout<<"DEBUG coords: "<<x<<","<<y<<endl; //x and y is smaller by 1 (need to add one)@@@@@@@
            _board[y][x]=new boarders(coords(x,y));
            x++;
            break;

        case NEXT_LINE:
            x=0; //collumn
            y++; //rows
            break;

        default:
            cout<<"Invalid key..."<<endl;
            break;
        }

        //cout<<"("<<x<<","<<y<<") ";

    }

    x=0;
    y=0;

    while(!_pelletData.eof())
    {
        _pelletData.get(singleChar);

        switch (singleChar)
        {
        case PELLET:
            _pellets[y][x]=new pellet(coords(x,y));
            x++;
            increment_pelletCount();
            break;

        case POWER_PELLET:
            _pellets[y][x]=new powerPellet(coords(x,y));
            increment_pelletCount();
            x++;
            break;

        case NULLED:
            _pellets[y][x]=NULL;
            x++;
            break;

        case NEXT_LINE:
            x=0; //collumn
            y++; //rows
            break;

        default:
            //cout<<"Invalid key..."<<endl;
            break;
        }
    }
    _mapData.close();
    _pelletData.close();

}


void grid::initializeToNull()
{
    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            _board[i][j]==NULL;
            _pellets[i][j]==NULL;
        }
    }
}

