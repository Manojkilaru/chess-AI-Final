//
//  move.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "move.h"
move::move(position intial,position final,piece *board[12][8]):initial(intial),final(final)
{
    if(final.x!=-7&&board[final.x][final.y]!=NULL)
    {
        deadpos=board[final.x][final.y]->deadpos(board);
    }
}
void move::set(piece *board[12][8])
{
    if(final.x!=-7&&board[final.x][final.y]!=NULL)
    {
        deadpos=board[final.x][final.y]->deadpos(board);
    }
}
void move::undoit(piece *board[12][8]){
    board[initial.x][initial.y]=board[final.x][final.y];
    board[initial.x][initial.y]->update_position(initial);
    if (deadpos.x!=-7&&deadpos.y!=-7) {
        board[final.x][final.y]=board[deadpos.x][deadpos.y];
        board[final.x][final.y]->update_position(final);
        if (board[deadpos.x][deadpos.y]->colour) {
            piece::whitecoins++;
        }
        else{
            piece::blackcoins++;
        }
        board[deadpos.x][deadpos.y]=nullptr;
    }
    else{
        board[final.x][final.y]=nullptr;
    }
}

void move::moveit(piece *board[12][8]){
    if (board[final.x][final.y]==nullptr) {
        board[final.x][final.y]=board[initial.x][initial.y];
        board[final.x][final.y]->update_position(final);
        board[initial.x][initial.y]=nullptr;
    }
    else
    {
        board[deadpos.x][deadpos.y]=board[final.x][final.y];
        board[deadpos.x][deadpos.y]->update_position(deadpos);
        if (board[deadpos.x][deadpos.y]->colour) {
            piece::whitecoins--;
        }
        else{
            piece::blackcoins--;
        }
        board[final.x][final.y]=board[initial.x][initial.y];
        board[final.x][final.y]->update_position(final);
        board[initial.x][initial.y]=nullptr;
    }
}
