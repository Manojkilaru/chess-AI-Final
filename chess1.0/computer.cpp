//
//  computer.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "computer.h"
#include "evaluation.h"
#include "temp_display.h"
const long POSITIVEINFINITE =9223372036854775806;
const long NEGATIVEINFINITE =-9223372036854775806;
long negamax(piece *board[12][8],short depth,long alpha,long beta,short color,class::move &bestmove){
    if(depth==0){
        return color*valueofboard(board);
    }
    if (color==1) {
        if (piece::whiteKing.isDead()) {
            return NEGATIVEINFINITE;
        }
        
    }
    else{
        if (piece::blackKing.isDead()) {
            return POSITIVEINFINITE;
        }
    }
    bool decide=true;
    long bestValue=NEGATIVEINFINITE;
    for(int i=2;i<10;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!=nullptr){
                if (color==1) {
                    if (board[i][j]->colour==true) {
                        short workdone=-1;
                        position moved_position,workingpostion;
                        for(int k=0;;k++){
                            class::move temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                            if (temp.final.x==-7&&temp.final.y==-7) {
                                break;
                            }
                            else{
                                decide=false;
                            }
                            temp.moveit(board);
                            long val=-negamax(board,depth-1,-beta,-alpha,-color,bestmove);
                            bestValue=max(bestValue,val);
                            if (bestValue==val&&depth==5) {
                                
                                bestmove=temp;
                            }
                            temp.undoit(board);
                            alpha=max(alpha,val);
                            if(alpha>beta)
                            {
                                break;
                            }
                        }
                    }
                }
                else{
                    if (board[i][j]->colour==false) {
                        short workdone=-1;
                        position moved_position,workingpostion;
                        for(int k=0;;k++){
                            class::move temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                            if (temp.final.x==-7&&temp.final.y==-7) {
                                break;
                            }
                            else{
                                decide=false;
                            }
                            temp.moveit(board);
                            long val=-negamax(board,depth-1,-beta,-alpha,-color,bestmove);
                            
                            bestValue=max(bestValue,val);
                            if (bestValue==val&&depth==5) {
                                bestmove=temp;
                            }
                            temp.undoit(board);
                            alpha=max(alpha,val);
                            if(alpha>beta)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if(alpha>beta){
                break;
            }
        }
        if(alpha>beta){
            break;
        }
    }
    if (decide) {
        return color*valueofboard(board);
    }
    return bestValue;
}
long minimax(piece *board[12][8],short depth,long alpha,long beta,bool maximizingPlayer,class::move &bestmove){
    if(depth==0){
        return valueofboard(board);
    }
    bool decide = true;
    long v;
    if (maximizingPlayer) {
        v=NEGATIVEINFINITE;
    }
    else{
        v=POSITIVEINFINITE;
    }
    for(int i=2;i<10;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]!=nullptr){
                if (maximizingPlayer) {
                    if (board[i][j]->colour==true) {
                        short workdone=-1;
                        position moved_position,workingpostion;
                        for(int k=0;;k++){
                            class::move temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                            if (temp.final.x==-7&&temp.final.y==-7) {
                                break;
                            }
                            else{
                                decide=false;
                            }
                            temp.moveit(board);
                            long val=minimax(board,depth-1,alpha,beta,false,bestmove);
                            v = max(v,val);
                            if (v==val&&depth==5) {
                                bestmove=temp;
                            }
                            temp.undoit(board);
                            alpha=max(alpha,val);
                            if(beta<=alpha)
                                break;
                        }
                    }
                }
                else{
                    if (board[i][j]->colour==false) {
                        short workdone=-1;
                        position moved_position,workingpostion;
                        for(int k=0;;k++){
                            class::move temp=board[i][j]->generate(board,workdone,moved_position,workingpostion);
                            if (temp.final.x==-7&&temp.final.y==-7) {
                                break;
                            }
                            else{
                                decide=false;
                            }
                            temp.moveit(board);
                            long val=minimax(board,depth-1,alpha,beta,true,bestmove);
                            v = min(v,val);
                            if (v==val&&depth==5) {
                                bestmove=temp;
                            }
                            temp.undoit(board);
                            beta=min(beta,val);
                            if(beta<=alpha)
                                break;
                        }
                    }
                }
            }
        }
    }
    if (decide) {
        return valueofboard(board);
    }
    return v;
}
void promote_pawn(piece *board[12][8],position present,bool colour){
    class::move temp;
    int best=1;
    long val,tempval;
    if (colour==1) {
        board[present.x][present.y]=new knight(true,present);
        val=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,1,temp);
        delete board[present.x][present.y];
        board[present.x][present.y]=new bishop(true,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,1,temp);
        if (tempval>val) {
            val=tempval;
            best=2;
        }
        delete board[present.x][present.y];
        board[present.x][present.y]=new rook(true,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,1,temp);
        if (tempval>val) {
            val=tempval;
            best=3;
        }
        delete board[present.x][present.y];
        board[present.x][present.y]=new queen(true,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,1,temp);
        if (tempval>val) {
            val=tempval;
            best=4;
        }
        switch (best) {
            case 1:
                board[present.x][present.y]=new knight(true,present);
                break;
            case 2:
                board[present.x][present.y]=new bishop(true,present);
                break;
            case 3:
                board[present.x][present.y]=new rook(true,present);
                break;
            case 4:
                board[present.x][present.y]=new queen(true,present);
                break;
        }
    }
    else{
        board[present.x][present.y]=new knight(false,present);
        val=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,-1,temp);
        delete board[present.x][present.y];
        board[present.x][present.y]=new bishop(false,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,-1,temp);
        if (tempval>val) {
            val=tempval;
            best=2;
        }
        delete board[present.x][present.y];
        board[present.x][present.y]=new rook(false,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,-1,temp);
        if (tempval>val) {
            val=tempval;
            best=3;
        }
        delete board[present.x][present.y];
        board[present.x][present.y]=new queen(false,present);
        tempval=negamax(board,6,NEGATIVEINFINITE,POSITIVEINFINITE,-1,temp);
        if (tempval>val) {
            val=tempval;
            best=4;
        }
        switch (best) {
            case 1:
                board[present.x][present.y]=new knight(false,present);
                break;
            case 2:
                board[present.x][present.y]=new bishop(false,present);
                break;
            case 3:
                board[present.x][present.y]=new rook(false,present);
                break;
            case 4:
                board[present.x][present.y]=new queen(false,present);
                break;
        }
    }
}
bool nextmove(piece *board[12][8],bool user_colour){
    class::move bestmove;
    if (ischeckmate(!user_colour,board)) {
        cout<<"player has won\n";
        return true;
    }
    if (stalemate(board,!user_colour)) {
        cout<<"draw";
        return true;
    }
    if (user_colour) {
        negamax(board,5,NEGATIVEINFINITE,POSITIVEINFINITE,-1,bestmove);
        //minimax(board,5, NEGATIVEINFINITE, POSITIVEINFINITE, false, bestmove);
    }
    else{
        negamax(board,5,NEGATIVEINFINITE,POSITIVEINFINITE,1,bestmove);
        //minimax(board,5, NEGATIVEINFINITE, POSITIVEINFINITE, true, bestmove);
    }
    bestmove.moveit(board);
    if ((bestmove.final.x==2||bestmove.final.x==9)&&board[bestmove.final.x][bestmove.final.y]->tostring()=="pawn") {
        if (bestmove.final.x==9) {
            delete board[bestmove.final.x][bestmove.final.y];
            promote_pawn(board,bestmove.final,1);
            //board[bestmove.final.x][bestmove.final.y]=new queen(true,bestmove.final);
        }
        else{
            delete board[bestmove.final.x][bestmove.final.y];
            promote_pawn(board,bestmove.final,0);
            //board[bestmove.final.x][bestmove.final.y]=new queen(false,bestmove.final);
        }
    }
    piece::computermove=bestmove;
    cout<<endl<<board[bestmove.final.x][bestmove.final.y]->tostring()<<endl;
    cout<<char(bestmove.initial.y+97)<<char(bestmove.initial.x-1+48)<<"-"<<char(bestmove.final.y+97)<<char(bestmove.final.x-1+48)<<endl;
    return false;
}