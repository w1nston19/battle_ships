//
// Created by MISHO on 12/23/2020.
//
using namespace std;
struct player{
    int board[10][10];
    int guessesBoard[10][10];
    int all_ships=10, small_ships=4,middle_ships=3,big_ships=2,huge_ship=1;
    int found_all_ships=0,found_small_ships=0,found_middle_ships=0,found_big_ships=0,found_huge_ship=0;
    int destroyed_ships=0;
    player()
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                    this->board[i][j] = 0;
                    this->guessesBoard[i][j] = 0;
            }
        }
    }
};
void print_line()
{
    char ch=(char)196;
    for(int i=0;i<11;i++)
    {
        cout<<" "<<ch<<ch<<ch;
    }
    cout<<endl;
}
void print_board(int a[10][10])
{
    system("cls");
    print_line();
    cout<<"|   |";
    for(int i=65;i<=74;i++)
    {
        cout<<" "<<(char)i<<" |";
    }
    cout<<endl;
    print_line();
    for(int i=0;i<10;i++)
    {
        if(i<9)
        {
            cout<<"| "<<i+1<<" |";
        }
        else {cout<<"|"<<i+1<<" |";}

        for(int j=0;j<10;j++)
        {
            if(a[i][j]==0){cout<<" "<<" "<<" |";}
            else {cout<<" "<<(char)219<<" |";}

        }
        cout<<endl;
        print_line();
    }
}
#ifndef BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
#define BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H

#endif //BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
