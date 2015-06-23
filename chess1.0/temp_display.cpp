//
//  temp_display.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "temp_display.h"
void print(piece *board[12][8]){
    for (int i=11;i>=0;i--) {
        for (int j=0; j<8; j++) {
            if(board[i][j]!=nullptr){
                std::cout<<char(j+97)<<char(i-1+48)<<board[i][j]->tostring()<<board[i][j]->colour<<"\t\t";
            }
            else{
                std::cout<<char(j+97)<<char(i-1+48)<<"null"<<"\t\t";
            }
        }
        std::cout<<std::endl;
    }
}