//
//  coins.h
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#ifndef __chess1_0__coins__
#define __chess1_0__coins__

#include <stdio.h>
#include "pos.h"
#include <iostream>
using namespace std;
class king;
class piece;
class move {
public:
    move(){}
    position initial,final,deadpos;
    void set(piece *board[12][8]);
    move (position intial,position final,piece *board[12][8]);
    void undoit(piece *board[12][8]);
    void moveit(piece *board[12][8]);
    
};


class piece{
public:
    static short whitecoins,blackcoins;
    static class::move usermove,computermove;
    static position whiteKing,blackKing;
    static bool haswhitekingmoved,haswhiterook1moved,haswhiterook2moved,hasblackkingmoved,hasblackrook1moved,hasblackrook2moved;
    position mine;
    bool colour;
    piece(bool colour,position my);
    virtual string tostring()=0;
    virtual position deadpos(piece *board[12][8])=0;
    virtual bool valid_move(piece *board[12][8],position final)=0;
    virtual void update_position(position present);
    virtual bool is_check(piece *board[12][8])=0;
    static short number(bool colour);
    virtual class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion)=0;
    virtual long evaluate(piece *board[12][8])=0;
    virtual ~piece(){
        
    }
};


class pawn:public piece{
public:
    pawn(bool colour,position my);
    string tostring();
    bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    bool is_check(piece *board[12][8]);
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
     
};
class rook:public piece{
public:
    rook(bool colour,position my);
    string tostring();bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    bool is_check(piece *board[12][8]);
     
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
};
class knight:public piece{
public:
    knight(bool colour,position my);
    string tostring();
    bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    bool is_check(piece *board[12][8]);
    
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
};
class bishop:public piece{
public:
    bishop(bool colour,position my);
    string tostring();
    bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    bool is_check(piece *board[12][8]);
     
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
};
class queen:public piece{
    bishop temp1;
    rook temp2;
    bool over;
public:
    queen(bool colour,position my);
    string tostring();
    bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    bool is_check(piece *board[12][8]);
     
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
};
class king:public piece{
public:
    king(bool colour,position my);
    string tostring();
    bool valid_move(piece *board[12][8],position final);
    position deadpos(piece *board[12][8]);
    void update_position(position present);
    bool is_check(piece *board[12][8]);
     
    class::move generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion);
    long evaluate(piece *board[12][8]);
};

#endif /* defined(__chess1_0__coins__) */
