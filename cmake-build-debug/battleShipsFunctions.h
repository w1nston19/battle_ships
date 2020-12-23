//
// Created by MISHO on 12/23/2020.
//
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
                board[i][j]=0;
                guessesBoard[i][j]=0;
            }
        }
    }
};
#ifndef BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
#define BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H

#endif //BATTLE_SHIPS_BATTLESHIPSFUNCTIONS_H
