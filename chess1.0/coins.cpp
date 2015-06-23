//
//  coins.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "coins.h"
string pawn::tostring(){
    return "pawn";
}
string rook::tostring(){
    return "rook";
}
string knight::tostring(){
    return "kni";
}
string bishop::tostring(){
    return "bis";
}
string queen::tostring(){
    return "quen";
}
string king::tostring(){
    return "king";
}
class::move piece::usermove,piece::computermove;
position piece::whiteKing(2,4),piece::blackKing(9,4);
piece::piece(bool colour,position my):mine(my){
    this->colour=colour;
}
pawn::pawn(bool colour,position my):piece(colour,my){
    
}
rook::rook(bool colour,position my):piece(colour,my){

}
knight::knight(bool colour,position my):piece(colour,my){
    
}
bishop::bishop(bool colour,position my):piece(colour,my){
    
}
queen::queen(bool colour,position my):piece(colour,my),temp1(colour,my),temp2(colour,my){
    
}
king::king(bool colour,position my):piece(colour,my){
    
}

bool piece::haswhitekingmoved=false,piece::haswhiterook1moved=false,piece::haswhiterook2moved=false,piece::hasblackkingmoved=false,piece::hasblackrook1moved=false,piece::hasblackrook2moved=false;

position pawn::deadpos(piece *board[12][8])
{
    position result;
    if(colour==1)
        result.x=10;
    else
        result.x=1;
    int i;
    for (i=0;board[result.x][i]!=nullptr;i++) {
        
    }
    result.y=i;
    return result;
}
position rook::deadpos(piece *board[12][8]){
    position result;
    if(colour==1)
        result.x=11;
    else
        result.x=0;
    if (board[result.x][0]==nullptr) {
        result.y=0;
    }
    else{
        result.y=7;
    }
    return result;
}
position knight::deadpos(piece *board[12][8]){
    position result;
    if(colour==1)
        result.x=11;
    else
        result.x=0;
    if (board[result.x][1]==nullptr) {
        result.y=1;
    }
    else{
        result.y=6;
    }
    return result;
}
position bishop::deadpos(piece *board[12][8]){
    position result;
    if(colour==1)
        result.x=11;
    else
        result.x=0;
    if (board[result.x][2]==nullptr) {
        result.y=2;
    }
    else{
        result.y=5;
    }
    return result;
}
position queen::deadpos(piece *board[12][8]){
    position result;
    if(colour==1)
    {
        result.x=11;
    }else
    {
        result.x=0;
    }
    result.y=3;
    return result;
}
position king::deadpos(piece *board[12][8]){
    position result;
    if(colour==1)
    {
        result.x=11;
    }else
    {
        result.x=0;
    }
    result.y=4;
    return result;
}

void piece::update_position(position present){
    mine=present;
}
void king::update_position(position present){
    mine=present;
    if (colour==1) {
        piece::whiteKing=present;
    }
    else if (colour==0) {
        piece::blackKing=present;
    }
}


bool pawn::valid_move(piece *board[12][8],position final){
    if (colour==1) {
        if(final.x==mine.x+1&&final.y==mine.y)
            if (board[final.x][final.y]==nullptr)
            {
                return true;
            }
        if(final.x==mine.x+1&&final.y==mine.y+1)
            if (board[final.x][final.y]!=nullptr&&board[final.x][final.y]->colour==false)
                return true;
        if(final.x==mine.x+1&&final.y==mine.y-1)
            if (board[final.x][final.y]!=nullptr&&board[final.x][final.y]->colour==false)
                return true;
        if(final.x==mine.x+2&&final.y==mine.y)
            if (mine.x==3&&board[final.x][final.y]==nullptr) {
                return true;
            }
        return false;
    }
    else{
        if(final.x==mine.x-1&&final.y==mine.y)
            if (board[final.x][final.y]==nullptr)
            {
                return true;
            }
        if(final.x==mine.x-1&&final.y==mine.y+1)
            if (board[final.x][final.y]!=nullptr&&board[final.x][final.y]->colour==true)
                return true;
        if(final.x==mine.x-1&&final.y==mine.y-1)
            if (board[final.x][final.y]!=nullptr&&board[final.x][final.y]->colour==true)
                return true;
        if(final.x==mine.x-2&&final.y==mine.y)
            if (mine.x==8&&board[final.x][final.y]==nullptr) {
                return true;
            }
        return false;
    }
}
bool rook::valid_move(piece *board[12][8],position final){
    if (final.x==mine.x) {
        int i=-7;
        if (final.y>mine.y) {
            for (i=mine.y+1; board[final.x][i]==nullptr&&i<final.y; i++) {
                
            }
        }
        else if (final.y<mine.y) {
            for (i=mine.y-1; board[final.x][i]==nullptr&&i>final.y; i--) {
                
            }
        }
        if (i==final.y) {
            if (board[final.x][final.y]==nullptr||board[final.x][final.y]->colour!=colour) {
                return true;
            }
        }
    }
    else if (final.y==mine.y){
        int i=-7;
        if (final.x>mine.x) {
            for (i=mine.x+1; board[i][final.y]==nullptr&&i<final.x; i++) {
                
            }
        }
        else if (final.x<mine.x) {
            for (i=mine.x-1; board[i][final.y]==nullptr&&i>final.x; i--) {
                
            }
        }
        if (i==final.x) {
            if (board[final.x][final.y]==nullptr||board[final.x][final.y]->colour!=colour) {
                return true;
            }
        }
    }
    return false;
}
bool knight::valid_move(piece *board[12][8],position final){
    if (abs(final.x-mine.x)+abs(final.y-mine.y)==3&&final.x!=mine.x&&final.y!=mine.y) {
        if (board[final.x][final.y]==nullptr||board[final.x][final.y]->colour!=colour) {
            return true;
        }
    }
    return false;
}
bool bishop::valid_move(piece *board[12][8],position final){
    if (final.x-mine.x==final.y-mine.y) {
        int i=-7;
        if (final.y>mine.y) {
            for (i=1; board[mine.x+i][mine.y+i]==nullptr&&i<final.y-mine.y; i++) {
                
            }
        }
        else if (final.y<mine.y) {
            for (i=-1; board[mine.x+i][mine.y+i]==nullptr&&i>final.y-mine.y; i--) {
                
            }
        }
        if (i==final.y-mine.y) {
            if (board[final.x][final.y]==nullptr||board[final.x][final.y]->colour!=colour) {
                return true;
            }
        }
    }
    else if (final.x-mine.x==-final.y+mine.y){
        int i=-7;
        if (final.x>mine.x) {
            for (i=1; board[mine.x+i][mine.y-i]==nullptr&&i<final.x-mine.x; i++) {
                
            }
        }
        else if (final.x<mine.x) {
            for (i=-1; board[mine.x+i][mine.y-i]==nullptr&&i>final.x-mine.x; i--) {
                
            }
        }
        if (i==final.x-mine.x) {
            if (board[final.x][final.y]==nullptr||board[final.x][final.y]->colour!=colour) {
                return true;
            }
        }
    }
    return false;
}
bool queen::valid_move(piece *board[12][8],position final){
    temp1.mine=mine;
    if(temp1.valid_move(board, final))
        return true;
    else
    {
        temp2.mine=mine;
        if(temp2.valid_move(board, final))
            return true;
    }
    return false;
}
bool king::valid_move(piece *board[12][8],position final){
    class::move temp(mine,final,board);
    if (abs(mine.x-final.x)<=1&&abs(mine.y-final.y)<=1) {
        return true;
    }
    else if (mine.x==final.x&&abs(mine.y-final.y)==2) {
        if (final.y>mine.y) {
            if (colour==1) {
                if (!piece::haswhitekingmoved&&!piece::haswhiterook2moved) {
                    if (board[2][5]==nullptr&&board[2][6]==nullptr) {
                        position temp1(2,7),temp2(2,5);
                        class::move forrook(temp1,temp2,board);
                        forrook.moveit(board);
                        return true;
                    }
                }
            }
            else{
                if (!piece::hasblackkingmoved&&!piece::hasblackrook2moved) {
                    if (board[9][5]==nullptr&&board[9][6]==nullptr) {
                        position temp1(9,7),temp2(9,5);
                        class::move forrook(temp1,temp2,board);
                        forrook.moveit(board);
                        return true;
                    }
                }
            }
        }
        else if(final.y<mine.y){
            if (colour==1) {
                if (!piece::haswhitekingmoved&&!piece::haswhiterook1moved) {
                    if (board[2][1]==nullptr&&board[2][2]==nullptr&&board[2][3]==nullptr) {
                        position temp1(2,0),temp2(2,3);
                        class::move forrook(temp1,temp2,board);
                        forrook.moveit(board);
                        return true;
                    }
                }
            }
            else{
                if (!piece::hasblackkingmoved&&!piece::hasblackrook1moved) {
                    if (board[9][1]==nullptr&&board[9][2]==nullptr&&board[9][3]==nullptr) {
                        position temp1(9,0),temp2(9,3);
                        class::move forrook(temp1,temp2,board);
                        forrook.moveit(board);
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
}

short piece::blackcoins=16,piece::whitecoins=16;
short piece::number(bool colour){
    if (colour) {
        return whitecoins;
    }
    else{
        return blackcoins;
    }
}