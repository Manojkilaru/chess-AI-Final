//
//  start_game.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "start_game.h"
#include "input.h"
#include "computer.h"
#include "evaluation.h"
void startGame(){
    piece *board[12][8];
    initiate(board);
    print(board);
    cout<<"which colour do you want\n";
    bool user_colour;
    cin>>user_colour;
    bool isover=false;
    int i = 1;
    for (;!isover; i++) {
        if (i%2==user_colour) {
            isover=input(board,user_colour);
        }
        else{
            isover=nextmove(board,user_colour);
        }
        cout<<endl;
        print(board);
    }
}
//void startGame(){
//    piece *board[12][8];
//    initiate_testing(board);
//    print(board);
//    nextmove(board,0);
//    print(board);
//}