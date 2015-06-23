//
//  endGame.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "endGame.h"
#include "coins.h"
#include "move.h"
bool istherecheckforking(bool colour,piece *board[12][8]){
    for (int i=2;i<10;i++) {
        for (int j=0; j<8; j++) {
            if(board[i][j]!=nullptr&&board[i][j]->colour!=colour){
                if (board[i][j]->is_check(board)) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool ischeckmate(bool colour,piece *board[12][8]){
    class::move temp;
        for (int i=9;i>=2;i--) {
            for (int j=0; j<8; j++) {
                if(board[i][j]!=nullptr&&board[i][j]->colour==colour){
                    short workdone=-1;
                    position moved_position,workingpostion;
                    do{
                        temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                        if (temp.final.x!=-7&&temp.final.y!=-7) {
                            temp.moveit(board);
                            if (!istherecheckforking(colour,board)) {
                                temp.undoit(board);
                                return false;
                            }
                            temp.undoit(board);
                        }
                        else{
                            break;
                        }
                    }while (true);
                }
            }
        
        }
    return true;
}
bool pawn::is_check(piece *board[12][8]){
    if (colour==1) {
        if(isalive(mine.x+1,mine.y+1)&&board[mine.x+1][mine.y+1]!=nullptr&&board[mine.x+1][mine.y+1]->tostring()=="king"&&board[mine.x+1][mine.y+1]->colour!=colour)
            return true;
        if (isalive(mine.x+1,mine.y-1)&&board[mine.x+1][mine.y-1]!=nullptr&&board[mine.x+1][mine.y-1]->tostring()=="king"&&board[mine.x+1][mine.y-1]->colour!=colour) {
            return true;
    }
    return false;
    }
    else{
        if(isalive(mine.x-1,mine.y+1)&&board[mine.x-1][mine.y+1]!=nullptr&&board[mine.x-1][mine.y+1]->tostring()=="king"&&board[mine.x-1][mine.y+1]->colour!=colour)
            return true;
        if (isalive(mine.x-1,mine.y-1)&&board[mine.x-1][mine.y-1]!=nullptr&&board[mine.x-1][mine.y-1]->tostring()=="king"&&board[mine.x-1][mine.y-1]->colour!=colour) {
            return true;
        }
        return false;
    }
}
bool rook::is_check(piece *board[12][8]){
    int i;
    for (i=mine.x+1;isalive(i,mine.y)&&board[i][mine.y]==nullptr;i++) {
        
    }
    if(isalive(i,mine.y)&&board[i][mine.y]->tostring()=="king"&&board[i][mine.y]->colour!=colour){
        return true;
    }
    for (i=mine.x-1;isalive(i,mine.y)&&board[i][mine.y]==nullptr;i--) {
        
    }
    if(isalive(i,mine.y)&&board[i][mine.y]->tostring()=="king"&&board[i][mine.y]->colour!=colour){
        return true;
    }
    for (i=mine.y+1;isalive(mine.x,i)&&board[mine.x][i]==nullptr;i++) {
        
    }
    if(isalive(mine.x,i)&&board[mine.x][i]->tostring()=="king"&&board[mine.x][i]->colour!=colour){
        return true;
    }
    for (i=mine.y-1;isalive(mine.x,i)&&board[mine.x][i]==nullptr;i--) {
        
    }
    if(isalive(mine.x,i)&&board[mine.x][i]->tostring()=="king"&&board[mine.x][i]->colour!=colour){
        return true;
    }
    return false;
}
bool knight::is_check(piece *board[12][8]){
    if (isalive(mine.x+2,mine.y+1)&&board[mine.x+2][mine.y+1]!=nullptr&&board[mine.x+2][mine.y+1]->colour!=colour&&board[mine.x+2][mine.y+1]->tostring()=="king")
    {
        return true;
    }
    else if (isalive(mine.x+1,mine.y+2)&&board[mine.x+1][mine.y+2]!=nullptr&&board[mine.x+1][mine.y+2]->colour!=colour&&board[mine.x+1][mine.y+2]->tostring()=="king")
    {
        return true;
    }
    else if (isalive(mine.x-1,mine.y+2)&&board[mine.x-1][mine.y+2]!=nullptr&&board[mine.x-1][mine.y+2]->colour!=colour&&board[mine.x-1][mine.y+2]->tostring()=="king")
    {
        return true;
    }
    else if (isalive(mine.x-2,mine.y+1)&&(board[mine.x-2][mine.y+1]!=nullptr&&board[mine.x-2][mine.y+1]->colour!=colour&&board[mine.x-2][mine.y+1]->tostring()=="king"))
    {
        return true;
    }
    else if (isalive(mine.x-2,mine.y-1)&&(board[mine.x-2][mine.y-1]!=nullptr&&board[mine.x-2][mine.y-1]->colour!=colour&&board[mine.x-2][mine.y-1]->tostring()=="king"))
    {
        return true;
    }
    else if (isalive(mine.x-1,mine.y-2)&&(board[mine.x-1][mine.y-2]!=nullptr&&board[mine.x-1][mine.y-2]->colour!=colour&&board[mine.x-1][mine.y-2]->tostring()=="king"))
    {
        return true;
    }
    else if (isalive(mine.x+1,mine.y-2)&&(board[mine.x+1][mine.y-2]!=nullptr&&board[mine.x+1][mine.y-2]->colour!=colour&&board[mine.x+1][mine.y-2]->tostring()=="king"))
    {
        return true;
    }
    else if (isalive(mine.x+2,mine.y-1)&&(board[mine.x+2][mine.y-1]!=nullptr&&board[mine.x+2][mine.y-1]->colour!=colour&&board[mine.x+2][mine.y-1]->tostring()=="king"))
    {
        return true;
    }
    
    return false;
}
bool bishop::is_check(piece *board[12][8]){
    int i;
    for (i=1;isalive(mine.x+i,mine.y+i)&&board[mine.x+i][mine.y+i]==nullptr;i++) {
        
    }
    if(isalive(mine.x+i,mine.y+i)&&board[mine.x+i][mine.y+i]->tostring()=="king"&&board[mine.x+i][mine.y+i]->colour!=colour){
        return true;
    }
    for (i=-1;isalive(mine.x+i,mine.y+i)&&board[mine.x+i][mine.y+i]==nullptr;i--) {
        
    }
    if(isalive(mine.x+i,mine.y+i)&&board[mine.x+i][mine.y+i]->tostring()=="king"&&board[mine.x+i][mine.y+i]->colour!=colour){
        return true;
    }
    for (i=1;isalive(mine.x+i,mine.y-i)&&board[mine.x+i][mine.y-i]==nullptr;i++) {
        
    }
    if(isalive(mine.x+i,mine.y-i)&&board[mine.x+i][mine.y-i]->tostring()=="king"&&board[mine.x+i][mine.y-i]->colour!=colour){
        return true;
    }
    for (i=1;isalive(mine.x-i,mine.y+i)&&board[mine.x-i][mine.y+i]==nullptr;i++) {
        
    }
    if(isalive(mine.x-i,mine.y+i)&&board[mine.x-i][mine.y+i]->tostring()=="king"&&board[mine.x-i][mine.y+i]->colour!=colour){
        return true;
    }
    return false;
}
bool queen::is_check(piece *board[12][8]){
    bishop temp1(colour,mine);
    if (temp1.is_check(board)) {
        return true;
    }
    else
    {
        rook temp2(colour,mine);
        return temp2.is_check(board);
    }
}
bool king::is_check(piece *board[12][8]){
    return false;
}



bool stalemate(piece *board[12][8],bool colour){
    if (piece::whitecoins==1&&piece::blackcoins==1) {
        return true;
    }
    bool decide=true;
    for (int i=9;i>=2;i--) {
        for (int j=0; j<8; j++) {
            if(board[i][j]!=nullptr&&board[i][j]->colour==colour){
                short workdone=-1;
                position moved_position,workingpostion;
                class::move temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                if (temp.final.x!=-7&&temp.final.y!=-7) {
                    decide=false;
                }
            }
        }
    }
    return decide;
}