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
    cout<<"MAP"<<endl;
    for(int i = 0; i < Y_DIMENSION; i++){
        for(int j = 0; j < X_DIMENSION; j++){

            if(_board[i][j] != NULL){
                cout<<_board[i][j]->getType();
            }// end if
            else
                cout<<" ";
        }// end inner for
        cout<<endl;
    }// end outer for


}

void grid::loadFile()
{
    _mapData.open("Users\Les\Desktop\pacman\build-pacMan-Desktop_Qt_5_4_0_MinGW_32bit-Debug\PacManMap.txt");
    _pelletData.open("Users\Les\Desktop\pacman\build-pacMan-Desktop_Qt_5_4_0_MinGW_32bit-Debug\PacManPellets.txt");

    if (_mapData.fail()) /*|| _pelletData.fail()) //checks file*/
    {
        cout<<endl<<"****** Could not open msp file ******"<<endl;
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

    loadFile();

    while(!_mapData.eof())
    {
        _mapData.get(singleChar);
        if (singleChar==13) //13 is the enter key
        {
            cout<<endl;
            //increment the row if it isn't past the MAX

        }
        else
        {
            cout<<singleChar;
            //have a switch case that points to the correct object.

        }
    }

    while(!_pelletData.eof())
    {
        _pelletData.get(singleChar);
        if (singleChar==13) //13 is the enter key
        {
            cout<<endl;
            //increment the row if it isn't past the MAX

        }
        else
        {
            cout<<singleChar;
            //have a switch case that points to the correct object.

        }
    }

    _mapData.close();
    _pelletData.close();

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
            _pellets[i][j]==NULL;
        }
    }
}

