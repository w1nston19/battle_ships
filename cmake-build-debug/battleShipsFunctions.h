//
// Created by MISHO on 12/23/2020.
//
using namespace std;
struct player{
    int board[10][10];
    int guessesBoard[10][10];
    int allShips=10, smallShips=4,middleShips=3,bigShips=2,hugeShip=1;
    int foundAllShips=0,foundSmallShips=0,foundMiddleShips=0,foundBigShips=0,foundHugeShip=0;
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
void printLine()
{
    char ch=(char)196;
    for(int i=0;i<11;i++)
    {
        cout<<" "<<ch<<ch<<ch;
    }
    cout<<endl;
}
void printBoard(int a[10][10])
{
    system("cls");
    printLine();
    cout<<"|   |";
    for(int i=65;i<=74;i++)
    {
        cout<<" "<<(char)i<<" |";
    }
    cout<<endl;
    printLine();
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
        printLine();
    }
}
void printGuessesBoard(int a[10][10])
{
    printLine();
    cout<<"|   |";
    for(int i=65;i<=74;i++)
    {
        cout<<" "<<(char)i<<" |";
    }
    cout<<endl;
    printLine();
    for(int i=0;i<10;i++)
    {
        if(i<9)
        {
            cout<<"| "<<i+1<<" |";
        }
        else {cout<<"|"<<i+1<<" |";}

        for(int j=0;j<10;j++)
        {
            if(a[i][j]==0){cout<<" "<<" "<<" |";}//places that havent been guessed
            if(a[i][j]==1){cout<<" "<<"Y"<<" |";}//correct guessed places
            if(a[i][j]==2){cout<<" "<<"X"<<" |";}//wrong guessed places
        }
        cout<<endl;
        printLine();

    }
}
int shipSize(int type)
{   //returns the size of the ship depending on its type
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
void placeShip(int a[10][10],int type, int first_coordinate, int second_coordinate,int direction)
{   //places a ship on the board
    switch(direction)
    {
        case 1:for(int i=0;i<shipSize(type);i++){a[first_coordinate-i][second_coordinate]=type;};break; //up
        case 2:for(int i=0;i<shipSize(type);i++){a[first_coordinate+i][second_coordinate]=type;};break;//down
        case 3:for(int i=0;i<shipSize(type);i++){a[first_coordinate][second_coordinate-i]=type;};break;//left
        case 4:for(int i=0;i<shipSize(type);i++){a[first_coordinate][second_coordinate+i]=type;};break;//right
        default:return;
    }
}
bool areThereAny(player playerX,int type) //checks if the player has any ships left from the type
{
    int number_left;
    switch(type)
    {
        case 1:number_left=playerX.smallShips;break;
        case 2:number_left=playerX.middleShips;break;
        case 3:number_left=playerX.bigShips;break;
        case 4:number_left=playerX.hugeShip;break;
    }
    return number_left>0;
}
bool isInit(int i,int j) // checks if the element on i,j position is inside the board
{
    return i>=0&&i<=9&&j>=0&&j<=9;
}
bool coordinatesValidation(int arr[10][10],int firstCoordinate,int secondCoordinate)
{   //checks if the element arr[firstCoordinate][secondCoordinate] is not too close to other ships
    for(int i=firstCoordinate-1;i<=firstCoordinate+1;i++)
    {
        for(int j=secondCoordinate-1;j<=secondCoordinate+1;j++)
        {
            if(arr[i][j]>=1&&arr[i][j]<=4&&isInit(i,j)) return false;
        }
    }
    return true;
}
bool isAvailable(int arr[10][10],int type,int firstCoordinate, int secondCoordinate,int direction)
{   //checks if a the input ship can be placed on the board
    // (is not outside and is not close to other ships)
    switch(direction)
    {
        case 1:for(int i=0;i<shipSize(type);i++)
        {if(!coordinatesValidation(arr,firstCoordinate-i,secondCoordinate))return false;}
        return true;break;
        case 2:for(int i=0;i<shipSize(type);i++)
        {if(!coordinatesValidation(arr,firstCoordinate+i,secondCoordinate))return false;}
        return true;break;
        case 3:for(int i=0;i<shipSize(type);i++)
        {if(!coordinatesValidation(arr,firstCoordinate,secondCoordinate-i))return false;}
        return true;break;
        case 4:for(int i=0;i<shipSize(type);i++)
        {if(!coordinatesValidation(arr,firstCoordinate,secondCoordinate+i))return false;}
        return true;break;
        default:return false;
    }
}
bool isNotOutOfBounds(int type,int firstCoordinate,int secondCoordinate,int direction)
{   //checks if the ship is not being placed outside the board
    int size=shipSize(type);
    switch(direction)
    {
        case 1:return (firstCoordinate-size+1)>=0;
        case 2:return (firstCoordinate+size-1)<=9;
        case 3:return (secondCoordinate-size+1)>=0;
        case 4:return (secondCoordinate+size-1)<=9;
        default:return false;
    }
}
int reworkCoordinate(char letterCoordinate)
{   //reworks the letter coordinate to number
    int numberCoordinate;
    if(letterCoordinate>='a'&&letterCoordinate<='z')
    {
        letterCoordinate-=32;
    }
    numberCoordinate=(int)letterCoordinate-65;
    return numberCoordinate;
}
void placeAllShips(player &playerX)
{   //places all 10 ships on the board
    int type,firstCoordinate,secondCoordinate,direction;
    char letterCoordinate;
    do {
        do {
            cout << "Enter the type of your ship : " << endl;
            do {
                cin >> type;
            } while (type < 1 || type > 4 || !areThereAny(playerX, type));
            cout << "Choose starting point " << endl;
            do {
                cin >> letterCoordinate;
                cin >> firstCoordinate;
            } while (!isalpha(letterCoordinate) || firstCoordinate < 1 || firstCoordinate > 10);
            cout << "Enter direction" << endl;
            do {
                cin >> direction;
            } while (direction < 1 || direction > 4);
            secondCoordinate = reworkCoordinate(letterCoordinate);
            firstCoordinate--;
        } while (!isAvailable(playerX.board, type, firstCoordinate, secondCoordinate, direction) ||
                 !isNotOutOfBounds(type, firstCoordinate, secondCoordinate, direction));
        placeShip(playerX.board, type, firstCoordinate, secondCoordinate, direction);
        switch (type) {
            case 1:
                playerX.smallShips--;
                break;
            case 2:
                playerX.middleShips--;
                break;
            case 3:
                playerX.bigShips--;
                break;
            case 4:
                playerX.hugeShip--;
                break;
        }
        playerX.allShips--;
        printBoard(playerX.board);
    }while(playerX.allShips>0);
}
void seeGuessedShips(player &playerX)
{
    printGuessesBoard(playerX.guessesBoard);
    cout<<"Guessed ships - "<<playerX.foundAllShips<<endl;
    cout<<"Small ships - "<<playerX.foundSmallShips<<endl;
    cout<<"Middle ships - "<<playerX.foundMiddleShips<<endl;
    cout<<"Big ships - "<<playerX.foundBigShips<<endl;
    cout<<"Huge ships - "<<playerX.foundHugeShip<<endl;
}

void turn(player &playerOne,player &playerTwo)
{
    int choice;
    cout<<"What would you like to do?"<<endl;
    cout<<"1-See already guessed ships and coordinates(not available if you haven't guessed yet"<<endl;
    cout<<"2-Guess by entering coordinates"<<endl;
    cout<<"3-Guess by moving by one square up/down/left/right from you last guess"<<endl;
    do{
        cin>>choice;
    }while(choice<1||choice>3);
    switch(choice)
    {
        case 1:seeGuessedShips(playerOne);break;
        case 2: ;break;
        case 3: ;break;
    }
}
#ifndef BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
#define BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H

#endif //BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
