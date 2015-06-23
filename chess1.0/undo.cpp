//
//  undo.cpp
//  chess1.0
//
//  Created by Manoj kilaru on 13/06/15.
//  Copyright (c) 2015 Manoj kilaru. All rights reserved.
//

#include "undo.h"
void undo(piece *board[12][8]){
    class::move forComputer,forUser;
    forComputer.initial=piece::computermove.final;
    forComputer.final=piece::computermove.initial;
    forComputer.moveit(board);
    forUser.initial=piece::usermove.final;
    forUser.final=piece::usermove.initial;
    forUser.moveit(board);
}