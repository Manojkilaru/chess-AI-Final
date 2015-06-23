//
//  pos.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "pos.h"
position::position(){
    x=-7;y=-7;
}
position::position(int x, int y){
    this->x=x;
    this->y=y;
}
bool position::isDead(){
    if (((x>=0&&x<2)||(x>9&&x<12))&&(y>=0&&y<8)) {
        return true;
    }
    
    return false;
}
bool position::isalive(){
    if (x<2||x>9||y<0||y>7){
        return false;
    }
    return true;
}
bool isalive(int x,int y){
    if (x<2||x>9||y<0||y>7){
        return false;
    }
    return true;
}
bool isDead(int x,int y){
    if (((x>=0&&x<2)||(x>9&&x<12))&&(y>=0&&y<8)) {
        return true;
    }
    
    return false;
}