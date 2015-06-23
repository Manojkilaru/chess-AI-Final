//
//  endGame.h
//  chess1.0
//
//  Created by Manoj kilaru on 01/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#ifndef __chess1_0__endGame__
#define __chess1_0__endGame__

#include <stdio.h>
#include "coins.h"
bool istherecheckforking(bool colour,piece *board[12][8]);
bool ischeckmate(bool colour,piece *board[12][8]);
bool stalemate(piece *board[12][8],bool colour);
#endif /* defined(__chess1_0__endGame__) */
