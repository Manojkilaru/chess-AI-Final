//
//  generation.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 02/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "generation.h"
class::move pawn::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(colour==1) {
        if(workdone==-1){
            working_postion=mine;
            if (isalive(mine.x+1,mine.y+1)&&board[mine.x+1][mine.y+1]!=nullptr&&board[mine.x+1][mine.y+1]->colour!=colour)
            {
                next.x=mine.x+1;
                next.y=mine.y+1;
                workdone=1;
            }
            else if (isalive(mine.x+1,mine.y-1)&&board[mine.x+1][mine.y-1]!=nullptr&&board[mine.x+1][mine.y-1]->colour!=colour)
            {
                next.x=mine.x+1;
                next.y=mine.y-1;
                workdone=2;
            }
            else if (mine.x==3&&board[mine.x+2][mine.y]==nullptr) {
                next.x=mine.x+2;
                next.y=mine.y;
                workdone=3;
            }
            else if (isalive(mine.x+1,mine.y)&&board[mine.x+1][mine.y]==nullptr) {
                next.x=mine.x+1;
                next.y=mine.y;
                workdone=4;
            }
        }
        else if (workdone==1){
            if (isalive(working_postion.x+1,working_postion.y-1)&&board[working_postion.x+1][working_postion.y-1]!=nullptr&&board[working_postion.x+1][working_postion.y-1]->colour!=colour)
            {
                next.x=working_postion.x+1;
                next.y=working_postion.y-1;
                workdone=2;
            }
            else if (working_postion.x==3&&board[working_postion.x+2][working_postion.y]==nullptr) {
                next.x=working_postion.x+2;
                next.y=working_postion.y;
                workdone=3;
            }
            else if (isalive(working_postion.x+1,working_postion.y)&&board[working_postion.x+1][working_postion.y]==nullptr) {
                next.x=working_postion.x+1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        else if (workdone==2)
        {
            if (working_postion.x==3&&board[working_postion.x+2][working_postion.y]==nullptr) {
                next.x=working_postion.x+2;
                next.y=working_postion.y;
                workdone=3;
            }
            else if (isalive(working_postion.x+1,working_postion.y)&&board[working_postion.x+1][working_postion.y]==nullptr) {
                next.x=working_postion.x+1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        else if (workdone==3)
        {
            if (isalive(working_postion.x+1,working_postion.y)&&board[working_postion.x+1][working_postion.y]==nullptr) {
                next.x=working_postion.x+1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        class::move result(mine,next,board);
        return result;
        
    }
    else{
        if(workdone==-1){
            working_postion=mine;
            if (isalive(mine.x-1,mine.y+1)&&board[mine.x-1][mine.y+1]!=nullptr&&board[mine.x-1][mine.y+1]->colour!=colour)
            {
                next.x=mine.x-1;
                next.y=mine.y+1;
                workdone=1;
            }
            else if (isalive(mine.x-1,mine.y-1)&&board[mine.x-1][mine.y-1]!=nullptr&&board[mine.x-1][mine.y-1]->colour!=colour)
            {
                next.x=mine.x-1;
                next.y=mine.y-1;
                workdone=2;
            }
            else if (mine.x==8&&board[mine.x-2][mine.y]==nullptr) {
                next.x=mine.x-2;
                next.y=mine.y;
                workdone=3;
            }
            else if (isalive(mine.x-1,mine.y)&&board[mine.x-1][mine.y]==nullptr) {
                next.x=mine.x-1;
                next.y=mine.y;
                workdone=4;
            }
        }
        else if (workdone==1){
            if (isalive(working_postion.x-1,working_postion.y-1)&&board[working_postion.x-1][working_postion.y-1]!=nullptr&&board[working_postion.x-1][working_postion.y-1]->colour!=colour)
            {
                next.x=working_postion.x-1;
                next.y=working_postion.y-1;
                workdone=2;
            }
            else if (working_postion.x==8&&board[working_postion.x-2][working_postion.y]==nullptr) {
                next.x=working_postion.x-2;
                next.y=working_postion.y;
                workdone=3;
            }
            else if (isalive(working_postion.x-1,working_postion.y)&&board[working_postion.x-1][working_postion.y]==nullptr) {
                next.x=working_postion.x-1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        else if (workdone==2)
        {
            if (working_postion.x==8&&board[working_postion.x-2][working_postion.y]==nullptr) {
                next.x=working_postion.x-2;
                next.y=working_postion.y;
                workdone=3;
            }
            else if (isalive(working_postion.x-1,working_postion.y)&&board[working_postion.x-1][working_postion.y]==nullptr) {
                next.x=working_postion.x-1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        else if (workdone==3)
        {
            if (isalive(working_postion.x-1,working_postion.y)&&board[working_postion.x-1][working_postion.y]==nullptr) {
                next.x=working_postion.x-1;
                next.y=working_postion.y;
                workdone=4;
            }
        }
        class::move result(mine,next,board);
        return result;
    }
}
class::move king::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(workdone==-1){
        working_postion=mine;
        if (isalive(mine.x+1,mine.y+1)&&(board[mine.x+1][mine.y+1]==nullptr||board[mine.x+1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y+1;
            workdone=1;
        }
        else if (isalive(mine.x+1,mine.y)&&(board[mine.x+1][mine.y]==nullptr||board[mine.x+1][mine.y]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y;
            workdone=2;
        }
        else if (isalive(mine.x+1,mine.y-1)&&(board[mine.x+1][mine.y-1]==nullptr||board[mine.x+1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y-1;
            workdone=3;
        }
        else if (isalive(mine.x,mine.y-1)&&(board[mine.x][mine.y-1]==nullptr||board[mine.x][mine.y-1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y-1;
            workdone=4;
        }
        else if (isalive(mine.x-1,mine.y-1)&&(board[mine.x-1][mine.y-1]==nullptr||board[mine.x-1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y-1;
            workdone=5;
        }
        else if (isalive(mine.x-1,mine.y)&&(board[mine.x-1][mine.y]==nullptr||board[mine.x-1][mine.y]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y;
            workdone=6;
        }
        else if (isalive(mine.x-1,mine.y+1)&&(board[mine.x-1][mine.y+1]==nullptr||board[mine.x-1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y+1;
            workdone=7;
        }
        else if (isalive(mine.x,mine.y+1)&&(board[mine.x][mine.y+1]==nullptr||board[mine.x][mine.y+1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y+1;
            workdone=8;
        }
        
    }
    else{
        switch (workdone) {
            case 1:
                if (isalive(working_postion.x+1,working_postion.y)&&(board[working_postion.x+1][working_postion.y]==nullptr||board[working_postion.x+1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y;
                    workdone=2;
                }
                else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-1;
                    workdone=3;
                }
                else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y-1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y;
                    workdone=6;
                }
                else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                
                break;
                
            case 2:
                if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-1;
                    workdone=3;
                }
                else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y-1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y;
                    workdone=6;
                }
                else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                
                break;
            case 3:
                if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y-1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y;
                    workdone=6;
                }
                else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                break;
            case 4:
                if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y;
                    workdone=6;
                }
                else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                break;
            case 5:
                if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y;
                    workdone=6;
                }
                else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                break;
            case 6:
                if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+1;
                    workdone=7;
                }
                else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                break;
            case 7:
                if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x;
                    next.y=working_postion.y+1;
                    workdone=8;
                }
                break;
        }
    }
    moved_position=next;
    class::move result(mine,next,board);
    return result;

}
class::move queen::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(workdone==-1){
        working_postion=mine;
        if (isalive(mine.x+1,mine.y)&&(board[mine.x+1][mine.y]==nullptr||board[mine.x+1][mine.y]->colour!=colour))
        {
            workdone=1;
            next.x=mine.x+1;
            next.y=mine.y;
        }
        else if (isalive(mine.x-1,mine.y)&&(board[mine.x-1][mine.y]==nullptr||board[mine.x-1][mine.y]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y;
            workdone=2;
        }
        else if (isalive(mine.x,mine.y+1)&&(board[mine.x][mine.y+1]==nullptr||board[mine.x][mine.y+1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y+1;
            workdone=3;
        }
        else if (isalive(mine.x,mine.y-1)&&(board[mine.x][mine.y-1]==nullptr||board[mine.x][mine.y-1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y-1;
            workdone=4;
        }
        else if (isalive(mine.x+1,mine.y+1)&&(board[mine.x+1][mine.y+1]==nullptr||board[mine.x+1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y+1;
            workdone=5;
        }
        else if (isalive(mine.x-1,mine.y-1)&&(board[mine.x-1][mine.y-1]==nullptr||board[mine.x-1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x-1;
            workdone=6;
        }
        else if (isalive(mine.x-1,mine.y+1)&&(board[mine.x-1][mine.y+1]==nullptr||board[mine.x-1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y+1;
            workdone=7;
        }
        else if (isalive(mine.x+1,mine.y-1)&&(board[mine.x+1][mine.y-1]==nullptr||board[mine.x+1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if (workdone==1){
        if (isalive(moved_position.x+1,moved_position.y)&&(board[moved_position.x+1][moved_position.y]==nullptr||board[moved_position.x+1][moved_position.y]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y;
            workdone=1;
        }
        else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y;
            workdone=2;
        }
        else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else if (isalive(working_postion.x+1,working_postion.y+1)&&(board[working_postion.x+1][working_postion.y+1]==nullptr||board[working_postion.x+1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y+1;
            workdone=5;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=6;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if (workdone==2)
    {
        if (isalive(moved_position.x-1,moved_position.y)&&(board[moved_position.x-1][moved_position.y]==nullptr||board[moved_position.x-1][moved_position.y]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y;
            workdone=2;
        }
        
        else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else if (isalive(working_postion.x+1,working_postion.y+1)&&(board[working_postion.x+1][working_postion.y+1]==nullptr||board[working_postion.x+1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y+1;
            workdone=5;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=6;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if (workdone==3)
    {
        if (isalive(moved_position.x,moved_position.y+1)&&(board[moved_position.x][moved_position.y+1]==nullptr||board[moved_position.x][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x;
            next.y=moved_position.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else if (isalive(working_postion.x+1,working_postion.y+1)&&(board[working_postion.x+1][working_postion.y+1]==nullptr||board[working_postion.x+1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y+1;
            workdone=5;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=6;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if (workdone==4)
    {
        if (isalive(moved_position.x,moved_position.y-1)&&(board[moved_position.x][moved_position.y-1]==nullptr||board[moved_position.x][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x;
            next.y=moved_position.y-1;
            workdone=4;
        }
        else if (isalive(working_postion.x+1,working_postion.y+1)&&(board[working_postion.x+1][working_postion.y+1]==nullptr||board[working_postion.x+1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y+1;
            workdone=5;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=6;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if(workdone==5){
        if (isalive(moved_position.x+1,moved_position.y+1)&&(board[moved_position.x+1][moved_position.y+1]==nullptr||board[moved_position.x+1][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y+1;
            workdone=5;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=6;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if(workdone==6){
        if (isalive(moved_position.x-1,moved_position.y-1)&&(board[moved_position.x-1][moved_position.y-1]==nullptr||board[moved_position.x-1][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y-1;
            workdone=6;
        }
        
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if(workdone==7){
        if (isalive(moved_position.x-1,moved_position.y+1)&&(board[moved_position.x-1][moved_position.y+1]==nullptr||board[moved_position.x-1][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y+1;
            workdone=7;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    else if(workdone==8){
        if (isalive(moved_position.x+1,moved_position.y-1)&&(board[moved_position.x+1][moved_position.y-1]==nullptr||board[moved_position.x+1][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y-1;
            workdone=8;
        }
        else{
            workdone=9;
        }
    }
    if (next.x!=-7&&next.y!=-7&&board[next.x][next.y]!=nullptr) {
        workdone++;
    }
    moved_position=next;
    class::move result(mine,next,board);
    return result;
}
class::move rook::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(workdone==-1){
        working_postion=mine;
        if (isalive(mine.x+1,mine.y)&&(board[mine.x+1][mine.y]==nullptr||board[mine.x+1][mine.y]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y;
            workdone=1;
        }
        else if (isalive(mine.x-1,mine.y)&&(board[mine.x-1][mine.y]==nullptr||board[mine.x-1][mine.y]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y;
            workdone=2;
        }
        else if (isalive(mine.x,mine.y+1)&&(board[mine.x][mine.y+1]==nullptr||board[mine.x][mine.y+1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y+1;
            workdone=3;
        }
        else if (isalive(mine.x,mine.y-1)&&(board[mine.x][mine.y-1]==nullptr||board[mine.x][mine.y-1]->colour!=colour))
        {
            next.x=mine.x;
            next.y=mine.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==1){
        if (isalive(moved_position.x+1,moved_position.y)&&(board[moved_position.x+1][moved_position.y]==nullptr||board[moved_position.x+1][moved_position.y]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y;
            workdone=1;
        }
        else if (isalive(working_postion.x-1,working_postion.y)&&(board[working_postion.x-1][working_postion.y]==nullptr||board[working_postion.x-1][working_postion.y]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y;
            workdone=2;
        }
        else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==2)
    {
        if (isalive(moved_position.x-1,moved_position.y)&&(board[moved_position.x-1][moved_position.y]==nullptr||board[moved_position.x-1][moved_position.y]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y;
            workdone=2;
        }
        
        else if (isalive(working_postion.x,working_postion.y+1)&&(board[working_postion.x][working_postion.y+1]==nullptr||board[working_postion.x][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==3)
    {
        if (isalive(moved_position.x,moved_position.y+1)&&(board[moved_position.x][moved_position.y+1]==nullptr||board[moved_position.x][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x;
            next.y=moved_position.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x,working_postion.y-1)&&(board[working_postion.x][working_postion.y-1]==nullptr||board[working_postion.x][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==4)
    {
        if (isalive(moved_position.x,moved_position.y-1)&&(board[moved_position.x][moved_position.y-1]==nullptr||board[moved_position.x][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x;
            next.y=moved_position.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    if (next.x!=-7&&next.y!=-7&&board[next.x][next.y]!=nullptr) {
        workdone++;
    }
    moved_position=next;
    class::move result(mine,next,board);
    return result;
}
class::move knight::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(workdone==-1){
        working_postion=mine;
        if (isalive(mine.x+2,mine.y+1)&&(board[mine.x+2][mine.y+1]==nullptr||board[mine.x+2][mine.y+1]->colour!=colour))
        {
            next.x=mine.x+2;
            next.y=mine.y+1;
            workdone=1;
        }
        else if (isalive(mine.x+1,mine.y+2)&&(board[mine.x+1][mine.y+2]==nullptr||board[mine.x+1][mine.y+2]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y+2;
            workdone=2;
        }
        else if (isalive(mine.x-1,mine.y+2)&&(board[mine.x-1][mine.y+2]==nullptr||board[mine.x-1][mine.y+2]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y+2;
            workdone=3;
        }
        else if (isalive(mine.x-2,mine.y+1)&&(board[mine.x-2][mine.y+1]==nullptr||board[mine.x-2][mine.y+1]->colour!=colour))
        {
            next.x=mine.x-2;
            next.y=mine.y+1;
            workdone=4;
        }
        else if (isalive(mine.x-2,mine.y-1)&&(board[mine.x-2][mine.y-1]==nullptr||board[mine.x-2][mine.y-1]->colour!=colour))
        {
            next.x=mine.x-2;
            next.y=mine.y-1;
            workdone=5;
        }
        else if (isalive(mine.x-1,mine.y-2)&&(board[mine.x-1][mine.y-2]==nullptr||board[mine.x-1][mine.y-2]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y-2;
            workdone=6;
        }
        else if (isalive(mine.x+1,mine.y-2)&&(board[mine.x+1][mine.y-2]==nullptr||board[mine.x+1][mine.y-2]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y-2;
            workdone=7;
        }
        else if (isalive(mine.x+2,mine.y-1)&&(board[mine.x+2][mine.y-1]==nullptr||board[mine.x+2][mine.y-1]->colour!=colour))
        {
            next.x=mine.x+2;
            next.y=mine.y-1;
            workdone=8;
        }
        
    }
    else{
        switch (workdone) {
            case 1:
                if (isalive(working_postion.x+1,working_postion.y+2)&&(board[working_postion.x+1][working_postion.y+2]==nullptr||board[working_postion.x+1][working_postion.y+2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y+2;
                    workdone=2;
                }
                else if (isalive(working_postion.x-1,working_postion.y+2)&&(board[working_postion.x-1][working_postion.y+2]==nullptr||board[working_postion.x-1][working_postion.y+2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+2;
                    workdone=3;
                }
                else if (isalive(working_postion.x-2,working_postion.y+1)&&(board[working_postion.x-2][working_postion.y+1]==nullptr||board[working_postion.x-2][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y+1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-2,working_postion.y-1)&&(board[working_postion.x-2][working_postion.y-1]==nullptr||board[working_postion.x-2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y-2)&&(board[working_postion.x-1][working_postion.y-2]==nullptr||board[working_postion.x-1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-2;
                    workdone=6;
                }
                else if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
                
            case 2:
                if (isalive(working_postion.x-1,working_postion.y+2)&&(board[working_postion.x-1][working_postion.y+2]==nullptr||board[working_postion.x-1][working_postion.y+2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y+2;
                    workdone=3;
                }
                else if (isalive(working_postion.x-2,working_postion.y+1)&&(board[working_postion.x-2][working_postion.y+1]==nullptr||board[working_postion.x-2][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y+1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-2,working_postion.y-1)&&(board[working_postion.x-2][working_postion.y-1]==nullptr||board[working_postion.x-2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y-2)&&(board[working_postion.x-1][working_postion.y-2]==nullptr||board[working_postion.x-1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-2;
                    workdone=6;
                }
                else if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
            case 3:
                if (isalive(working_postion.x-2,working_postion.y+1)&&(board[working_postion.x-2][working_postion.y+1]==nullptr||board[working_postion.x-2][working_postion.y+1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y+1;
                    workdone=4;
                }
                else if (isalive(working_postion.x-2,working_postion.y-1)&&(board[working_postion.x-2][working_postion.y-1]==nullptr||board[working_postion.x-2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y-2)&&(board[working_postion.x-1][working_postion.y-2]==nullptr||board[working_postion.x-1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-2;
                    workdone=6;
                }
                else if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
            case 4:
                if (isalive(working_postion.x-2,working_postion.y-1)&&(board[working_postion.x-2][working_postion.y-1]==nullptr||board[working_postion.x-2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x-2;
                    next.y=working_postion.y-1;
                    workdone=5;
                }
                else if (isalive(working_postion.x-1,working_postion.y-2)&&(board[working_postion.x-1][working_postion.y-2]==nullptr||board[working_postion.x-1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-2;
                    workdone=6;
                }
                else if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
            case 5:
                if (isalive(working_postion.x-1,working_postion.y-2)&&(board[working_postion.x-1][working_postion.y-2]==nullptr||board[working_postion.x-1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x-1;
                    next.y=working_postion.y-2;
                    workdone=6;
                }
                else if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
            case 6:
                if (isalive(working_postion.x+1,working_postion.y-2)&&(board[working_postion.x+1][working_postion.y-2]==nullptr||board[working_postion.x+1][working_postion.y-2]->colour!=colour))
                {
                    next.x=working_postion.x+1;
                    next.y=working_postion.y-2;
                    workdone=7;
                }
                else if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
            case 7:
                if (isalive(working_postion.x+2,working_postion.y-1)&&(board[working_postion.x+2][working_postion.y-1]==nullptr||board[working_postion.x+2][working_postion.y-1]->colour!=colour))
                {
                    next.x=working_postion.x+2;
                    next.y=working_postion.y-1;
                    workdone=8;
                }
                break;
        }
    }
    moved_position=next;
    class::move result(mine,next,board);
    return result;
}
class::move bishop::generate(piece *board[12][8],short &workdone,position &moved_position,position &working_postion){
    position next;
    if(workdone==-1){
        working_postion=mine;
        if (isalive(mine.x+1,mine.y+1)&&(board[mine.x+1][mine.y+1]==nullptr||board[mine.x+1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y+1;
            workdone=1;
        }
        else if (isalive(mine.x-1,mine.y-1)&&(board[mine.x-1][mine.y-1]==nullptr||board[mine.x-1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y-1;
            workdone=2;
        }
        else if (isalive(mine.x-1,mine.y+1)&&(board[mine.x-1][mine.y+1]==nullptr||board[mine.x-1][mine.y+1]->colour!=colour))
        {
            next.x=mine.x-1;
            next.y=mine.y+1;
            workdone=3;
        }
        else if (isalive(mine.x+1,mine.y-1)&&(board[mine.x+1][mine.y-1]==nullptr||board[mine.x+1][mine.y-1]->colour!=colour))
        {
            next.x=mine.x+1;
            next.y=mine.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==1){
        if (isalive(moved_position.x+1,moved_position.y+1)&&(board[moved_position.x+1][moved_position.y+1]==nullptr||board[moved_position.x+1][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y+1;
            workdone=1;
        }
        else if (isalive(working_postion.x-1,working_postion.y-1)&&(board[working_postion.x-1][working_postion.y-1]==nullptr||board[working_postion.x-1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y-1;
            workdone=2;
        }
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==2)
    {
        if (isalive(moved_position.x-1,moved_position.y-1)&&(board[moved_position.x-1][moved_position.y-1]==nullptr||board[moved_position.x-1][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y-1;
             workdone=2;
        }
        
        else if (isalive(working_postion.x-1,working_postion.y+1)&&(board[working_postion.x-1][working_postion.y+1]==nullptr||board[working_postion.x-1][working_postion.y+1]->colour!=colour))
        {
            next.x=working_postion.x-1;
            next.y=working_postion.y+1;
             workdone=3;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
             workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==3)
    {
        if (isalive(moved_position.x-1,moved_position.y+1)&&(board[moved_position.x-1][moved_position.y+1]==nullptr||board[moved_position.x-1][moved_position.y+1]->colour!=colour))
        {
            next.x=moved_position.x-1;
            next.y=moved_position.y+1;
            workdone=3;
        }
        else if (isalive(working_postion.x+1,working_postion.y-1)&&(board[working_postion.x+1][working_postion.y-1]==nullptr||board[working_postion.x+1][working_postion.y-1]->colour!=colour))
        {
            next.x=working_postion.x+1;
            next.y=working_postion.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    else if (workdone==4)
    {
        if (isalive(moved_position.x+1,moved_position.y-1)&&(board[moved_position.x+1][moved_position.y-1]==nullptr||board[moved_position.x+1][moved_position.y-1]->colour!=colour))
        {
            next.x=moved_position.x+1;
            next.y=moved_position.y-1;
            workdone=4;
        }
        else{
            workdone=5;
        }
    }
    if (next.x!=-7&&next.y!=-7&&board[next.x][next.y]!=nullptr) {
        workdone++;
    }
    moved_position=next;
    class::move result(mine,next,board);
    return result;
}