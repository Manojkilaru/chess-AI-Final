//
//  evaluation.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 02/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "evaluation.h"
long valueofboard(piece *board[12][8]){
    long result=0;
    for (int i=2;i<10;i++) {
        for (int j=0;j<8;j++) {
            if (board[i][j]!=nullptr) {
                result+=board[i][j]->evaluate(board);
            }
        }
    }
    return result;
}
long pawn::evaluate(piece *board[12][8] )
{
    long result=100;
    int Piece_Square[8][8]={{0, 0, 0, 0, 0, 0, 0, 0},
        {50,50,50,50,50,50,50,50},
        {10,10,20,30,30,20,10,10},
        {5, 5,10,25,25,10, 5, 5},
        {0, 0, 0,20,20, 0, 0, 0},
        {5,-5,-10, 0, 0,-10,-5, 5},
        {5,10,10,-20,-20,10,10, 5},
        {0,0,0,0,0,0,0,0}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
long rook::evaluate(piece *board[12][8] )
{
    long result=500;
    int Piece_Square[8][8]={{0, 0, 0, 0, 0, 0, 0, 0},
        {5,10,10,10,10,10,10, 5},
        {-5, 0, 0, 0, 0, 0, 0,-5},
        {-5, 0, 0, 0, 0, 0, 0,-5},
        {-5, 0, 0, 0, 0, 0, 0,-5},
        {-5, 0, 0, 0, 0, 0, 0,-5},
        {-5, 0, 0, 0, 0, 0, 0,-5},
        {0, 0, 0, 5, 5, 0, 0, 0}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
long knight::evaluate(piece *board[12][8] )
{
    long result=320;
    short Piece_Square[8][8]={{-50,-40,-30,-30,-30,-30,-40,-50},
        {-40,-20, 0, 0, 0, 0,-20,-40},
        {-30, 0,10,15,15,10, 0,-30},
        {-30, 5,15,20,20,15, 5,-30},
        {-30, 0,15,20,20,15, 0,-30},
        {-30, 5,10,15,15,10, 5,-30},
        {-40,-20, 0, 5, 5, 0,-20,-40},
        {-50,-40,-30,-30,-30,-30,-40,-50}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
long bishop::evaluate(piece *board[12][8] )
{
    long result=330;
    short Piece_Square[8][8]={{-20,-10,-10,-10,-10,-10,-10,-20},
        {-10, 0, 0, 0, 0, 0, 0,-10},
        {-10, 0, 5,10,10, 5, 0,-10},
        {-10, 5, 5,10,10, 5, 5,-10},
        {-10, 0,10,10,10,10, 0,-10},
        {-10,10,10,10,10,10,10,-10},
        {-10, 5, 0, 0, 0, 0, 5,-10},
        {-20,-10,-10,-10,-10,-10,-10,-20}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
long queen::evaluate(piece *board[12][8] )
{
    long result=975;
    short Piece_Square[8][8]={{-20,-10,-10,-5,-5,-10,-10,-20},
        {-10, 0, 0, 0, 0, 0, 0,-10},
        {-10, 0, 5, 5, 5, 5, 0,-10},
        {-5, 0, 5, 5, 5, 5, 0,-5},
        {0,0,5,5,5,5,0,-5},
        {-10, 5, 5, 5, 5, 5, 0,-10},
        {-10, 0, 5, 0, 0, 0, 0,-10},
        {-20,-10,-10,-5,-5,-10,-10,-20}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
long king::evaluate(piece *board[12][8] )
{
    long result=20000;
    short Piece_Square[8][8]={{-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-20,-30,-30,-40,-40,-30,-30,-20},
        {-10,-20,-20,-20,-20,-20,-20,-10},
        {20,20,0,0,0,0,20,20},
        {20,30,10,0,0,10,30,20}};
    if (colour==1)
        result+=Piece_Square[mine.x-2][mine.y];
    else
    {
        result=-result;
        result-=Piece_Square[9-mine.x][7-mine.y];
    }
    return result;
}
