//
//  board_Creation.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "board_Creation.h"
void initiate(piece *board[12][8]){
    for (int i=0; i<12; i++) {
        for (int j=0; j<8; j++) {
            if (i==3||i==8) {
                position temp(i,j);
                if (i==3) {
                    board[i][j]=new pawn(true,temp);
                }
                else{
                    board[i][j]=new pawn(false,temp);
                }
                continue;
            }
            board[i][j]=nullptr;
        }
    }
    position temp(2,0);
    board[2][0]=new rook(true,temp);
    temp.y=1;
    board[2][1]=new knight(true,temp);
    temp.y=2;
    board[2][2]=new bishop(true,temp);
    temp.y=3;
    board[2][3]=new queen(true,temp);
    temp.y=4;
    board[2][4]=new king(true,temp);
    temp.y=5;
    board[2][5]=new bishop(true,temp);
    temp.y=6;
    board[2][6]=new knight(true,temp);
    temp.y=7;
    board[2][7]=new rook(true,temp);
    temp.x=9;
    temp.y=0;
    board[9][0]=new rook(false,temp);
    temp.y=1;
    board[9][1]=new knight(false,temp);
    temp.y=2;
    board[9][2]=new bishop(false,temp);
    temp.y=3;
    board[9][3]=new queen(false,temp);
    temp.y=4;
    board[9][4]=new king(false,temp);
    temp.y=5;
    board[9][5]=new bishop(false,temp);
    temp.y=6;
    board[9][6]=new knight(false,temp);
    temp.y=7;
    board[9][7]=new rook(false,temp);
}

void initiate_testing(piece *board[12][8]){
    for (int i=0; i<12; i++) {
        for (int j=0; j<8; j++) {
            board[i][j]=nullptr;
        }
    }
    position temp(8,4);
    board[8][4]=new pawn(true,temp);
//    position temp1(9,7);
//    board[9][7]=new king(false,temp1);
//    position temp2(9,0);
//    board[9][0]=new king(true,temp2);

}