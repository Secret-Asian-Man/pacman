#include "grid.h"
using namespace std;


grid::grid()
{
    initializeToNull();
    loadMap();


}

grid::~grid()
{
    //    for (int i=0;i<Y_DIMENSION;i++)
    //    {
    //        for (int j=0;j<X_DIMENSION;j++)
    //        {
    //            delete _board[i][j];
    //        }
    //    }

}

void grid::step()
{

}

void grid::show()
{

}

void grid::loadFile()
{
    _mapData.open("PacManMap.txt");

    if (_mapData.fail()) //checks file
    {
        cout<<endl<<"****** Could not open file ******"<<endl;
        exit(0);
    }

}

void grid::loadMap()
{
    loadFile();

    while(!_mapData.eof())
    {
        _mapData.get(_singleChar);
        if (_singleChar==13) //13 is the enter key
        {
            cout<<endl;
            //increment the row if it isn't past the MAX

        }
        else
        {
            cout<<_singleChar;
            //have a switch case that points to the correct object.

        }
    }

    _mapData.close();

    /* DEFAULT MAP:
BBBBBBBBBBBBBBBBBBBBBBBBBBBB
BPPPPPPPPPPPPWWPPPPPPPPPPPPB
BPWWWWPWWWWWPWWPWWWWWPWWWWPB
BUWWWWPWWWWWPWWPWWWWWPWWWWUB
BPWWWWPWWWWWPWWPWWWWWPWWWWPB
BPPPPPPPPPPPPPPPPPPPPPPPPPPB
BPWWWWPWWPWWWWWWWWPWWPWWWWPB
BPWWWWPWWPWWWWWWWWPWWPWWWWPB
BPPPPPPWWPPPPWWPPPPWWPPPPPPB
BWWWWWPWWWWW.WW.WWWWWPWWWWWB
BWWWWWPWWWWW.WW.WWWWWPWWWWWB
BWWWWWPWW..........WWPWWWWWB
BWWWWWPWW.WWWDDWWW.WWPWWWWWB
BWWWWWPWW.W......W.WWPWWWWWB
BR....P...W...G..W...P....RB
BWWWWWPWW.W......W.WWPWWWWWB
BWWWWWPWW.WWWWWWWW.WWPWWWWWB
BWWWWWPWW..........WWPWWWWWB
BWWWWWPWW.WWWWWWWW.WWPWWWWWB
BWWWWWPWW.WWWWWWWW.WWPWWWWWB
BPPPPPPPPPPPPWWPPPPPPPPPPPPB
BPWWWWPWWWWWPWWPWWWWWPWWWWPB
BPWWWWPWWWWWPWWPWWWWWPWWWWPB
BUPPWWPPPPPPP.MPPPPPPPWWPPUB
BWWPWWPWWPWWWWWWWWPWWPWWPWWB
BWWPWWPWWPWWWWWWWWPWWPWWPWWB
BPPPPPPWWPPPPWWPPPPWWPPPPPPB
BPWWWWWWWWWWPWWPWWWWWWWWWWPB
BPWWWWWWWWWWPWWPWWWWWWWWWWPB
BPPPPPPPPPPPPPPPPPPPPPPPPPPB
BBBBBBBBBBBBBBBBBBBBBBBBBBBB

M=pacman
W=walls
P=pebble
U=powerUp
D=door
N=null
H=wormHole
G=ghost
R=Warp
     */
}

void grid::initializeToNull()
{
    for (int i=0;i<Y_DIMENSION;i++)
    {
        for (int j=0;j<X_DIMENSION;j++)
        {
            _board[i][j]==NULL;
        }
    }
}

