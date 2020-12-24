#include <iostream>
#include "battleShipsFunctions.h"
using namespace std;
int main()
{
    player playerOne,playerTwo;
    cout<<"Welcome to the game of battle ships!"<<endl;
    system("pause");
    cout<<"Its player 1's turn to choose ships"<<endl;
    placeAllShips(playerOne);
    system("cls");
    printBoard(playerOne.board);
    system("pause");
    system("cls");
    cout<<"It's player 2's turn to choose ships"<<endl;
    placeAllShips(playerTwo);
    system("cls");
    printBoard(playerTwo.board);
    system("pause");
    system("cls");
    int round=1;
    while(playerOne.destroyed_ships!=10&&playerTwo.destroyed_ships!=10)
    {
        cout<<"It is round "<<round<<endl;
    }
    return 0;
}

