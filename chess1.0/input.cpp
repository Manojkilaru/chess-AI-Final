//
//  input.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "input.h"
#include "undo.h"
#include "temp_display.h"

bool input(piece *board[12][8],bool usercolour){
    bool ischeck;
    if(istherecheckforking(usercolour,board)){
        ischeck=true;
        cout<<"you have check\n";
        if (ischeckmate(usercolour,board)) {
            cout<<"computer won\n";
            return true;
        }
    }
    else
        ischeck=false;
    if (stalemate(board,usercolour)) {
        cout<<"draw\n";
        return true;
    }
    
    std::string s;
    class::move present;
    do{
        cout<<"enter\n";
        std::cin>>s;
        if (s=="undo") {
            undo(board);
            print(board);
            return input(board,usercolour);
        }
        if (s[0]<97||s[0]>104||s[3]<97||s[3]>104||s[1]<49||s[1]>56||s[4]<49||s[4]>56) {
            continue;
        }
        present.initial.x=s[1]-49+2;
        present.initial.y=s[0]-97;
        present.final.x=s[4]-49+2;
        present.final.y=s[3]-97;
        present.set(board);
        if (!present.initial.isalive()||!present.final.isalive()) {
            continue;
        }
        else if (board[present.initial.x][present.initial.y]==nullptr) {
            continue;
        }
        else if (board[present.initial.x][present.initial.y]->colour!=usercolour) {
            continue;
        }
        else if(board[present.initial.x][present.initial.y]->valid_move(board,present.final)){
            present.moveit(board);
            if (istherecheckforking(usercolour, board)) {
                present.undoit(board);
                continue;
            }
            else{
                break;
            }
        }
    }while (true);
    piece::usermove=present;
    if (board[present.final.x][present.final.y]->tostring()=="rook") {
        if (present.initial.x==2&&present.initial.y==0) {
            if (!piece::haswhiterook1moved) {
                piece::haswhiterook1moved=true;//======================================================================================== if can be removed
            }
        }
        else if (present.initial.x==2&&present.initial.y==7){
            if (!piece::haswhiterook2moved) {
                piece::haswhiterook2moved=true;
            }
        }
        else if (present.initial.x==9&&present.initial.y==0) {
            if (!piece::hasblackrook1moved) {
                piece::hasblackrook1moved=true;
            }
        }
        else if (present.initial.x==9&&present.initial.y==7){
            if (!piece::hasblackrook2moved) {
                piece::hasblackrook2moved=true;
            }
        }
    }
    else if (board[present.final.x][present.final.y]->tostring()=="king") {
        if (present.initial.x==9&&present.initial.y==4) {
            if (!piece::hasblackkingmoved) {
                piece::hasblackkingmoved=true;
            }
        }
        else if (present.initial.x==2&&present.initial.y==4){
            if (!piece::haswhitekingmoved) {
                piece::haswhitekingmoved=true;
            }
        }
    }
    if ((present.final.x==2||present.final.x==9)&&board[present.final.x][present.final.y]->tostring()=="pawn") {
        if (usercolour==1) {
            if (present.final.x==9) {
                while (true) {
                    cout<<"which coin do you want"<<endl;
                    cin>>s;
                    if (s=="queen") {
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new queen(true,present.final);
                        break;
                    }
                    else if(s=="rook"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new rook(true,present.final);
                        break;
                    }
                    else if(s=="knight"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new knight(true,present.final);
                        break;
                    }
                    else if(s=="bishop"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new bishop(true,present.final);
                        break;
                    }
                }
            }
        }
        else{
            if (present.final.x==2) {
                while (true) {
                    cout<<"which coin do you want"<<endl;
                    cin>>s;
                    if (s=="queen") {
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new queen(false,present.final);
                        break;
                    }
                    else if(s=="rook"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new rook(false,present.final);
                        break;
                    }
                    else if(s=="knight"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new knight(false,present.final);
                        break;
                    }
                    else if(s=="bishop"){
                        delete board[present.final.x][present.final.y];
                        board[present.final.x][present.final.y]=new bishop(false,present.final);
                        break;
                    }
                }
            }
        }
        
    }
    return false;
}