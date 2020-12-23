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
int ship_size(int type)
{
    int size_ship;
    switch (type)
    {
        case 1:size_ship=2;break;
        case 2:size_ship=3;break;
        case 3:size_ship=4;break;
        case 4:size_ship=6;break;
    }
    return size_ship;
}
void place_a_ship(int a[10][10],int type, int first_coordinate, int second_coordinate,int direction)
{
    int size_ship=ship_size(type);
    switch(direction)
    {
        case 1:for(int i=0;i<size_ship;i++){a[first_coordinate-i][second_coordinate]=type;};break; //up
        case 2:for(int i=0;i<size_ship;i++){a[first_coordinate+i][second_coordinate]=type;};break;//down
        case 3:for(int i=0;i<size_ship;i++){a[first_coordinate][second_coordinate-i]=type;};break;//left
        case 4:for(int i=0;i<size_ship;i++){a[first_coordinate][second_coordinate+i]=type;};break;//right
    }
}
#ifndef BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
#define BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H

#endif //BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
