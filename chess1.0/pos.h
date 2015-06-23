//
//  pos.h
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#ifndef __chess1_0__pos__
#define __chess1_0__pos__

#include <stdio.h>
class position{
public:
    int x,y;
    position();
    position(int x, int y);
    bool isDead();
    bool isalive();
};
bool isalive(int x,int y);
bool isDead(int x,int y);
#endif /* defined(__chess1_0__pos__) */
