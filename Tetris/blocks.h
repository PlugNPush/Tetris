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
#include "fonctions_essentielles.h"

typedef struct Block {
    int appartenance;
    int** content;
    int size;
}Block;

typedef struct Blocks {
    Block* blocks;
    int size;
}Blocks;

Blocks getBlocks(int forAppartenance);
Blocks getStandardizedBlocks(int forAppartenance);
Block convertBlock(Block block);
int getSize(int forAppartenance);
void printBlock(Block block);
void fillBlock(Block* s1, int content[][5]);

#endif /* blocks_h */
