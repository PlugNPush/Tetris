//
//  blocks.h
//  Tetris
//
//  Created by PlugN on 17/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#ifndef blocks_h
#define blocks_h

#include "global.h"

typedef struct Block {
    int appartenance;
    int content[5][5];
    int size;
}Block;

Block* getBlocks(int forAppartenance);
void printBlock(Block block);
void fillBlock(Block* s1, int content[][5]);

#endif /* blocks_h */
