//
//  blocks.c
//  Tetris
//
//  Created by PlugN on 17/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#include "blocks.h"

void deprecated() {
    printf("This function is deprecated and should not be called anymore.\n");
}

void obsoleted() {
    printf("This function is obsoleted and will not work as expected.\n");
}

void developement() {
    printf("This function is for developement purposes only and should not be called in production.\n");
}

void fillBlock(Block* s1, int content[][5]) {
    s1->content = create_2D_Array(5, 5);
    fill_2D_plateau_Carre(s1->content, 5, 5);
    int i, j;
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            s1->content[i][j] = content[i][j];
        }
    }
}

void diagBlock(Block block) {
    developement();
    int i, j;
    for (i=0; i < 5; i++) {
            for (j=0; j < 5; j++) {
                printf("%d ", block.content[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

int appartenanceSize(Block block) {
    deprecated();
    return block.size;
}

void printBlock(Block block) {
    int i, j;
    int size = block.size;
    int startpoint = 5 - size;
    int endpoint = 5;
    printf((size == 1) ? "-\n" : (size == 2) ? "- -\n" : (size == 3) ? "- - -\n" : (size == 4) ? "- - - -\n" : "- - - - -\n");
    for (i = startpoint; i < endpoint ; i++) {
        for (j=0; j < size; j++) {
            if (block.content[i][j] == 1) {
                printf("x ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    printf((size == 1) ? "-\n\n" : (size == 2) ? "- -\n\n" : (size == 3) ? "- - -\n\n" : (size == 4) ? "- - - -\n\n" : "- - - - -\n\n");
}

Block convertBlock(Block block) {
    Block s1;
    s1.size = block.size;
    s1.appartenance = block.appartenance;
    s1.content = create_2D_Array(block.size, block.size);
    //printf("Size : %d", block.size);
    int i, j, k;
    int size = block.size;
    int startpoint = 5 - size;
    int endpoint = 5;

    for (i = startpoint, k = 0; i < endpoint ; i++, k++) {
        for (j=0; j < size; j++) {
            s1.content[i-startpoint][j] = block.content[i][j];
        }
    }
    
    return s1;
    
}

Blocks getStandardizedBlocks(int forAppartenance) {
    Blocks blocklist = getBlocks(forAppartenance);
    Blocks blocks;
    blocks.size = blocklist.size;
    blocks.blocks = (Block*) malloc(sizeof(Block) * blocks.size);
    int i;
    for (i=0; i<blocks.size; i++) {
        blocks.blocks[i] = convertBlock(blocklist.blocks[i]);
    }
    
    return blocks;
}

int getSize(int forAppartenance) {
    int size;
    if (forAppartenance == 0) {
        size = 17;
    } else if (forAppartenance == 1) {
        size = 29;
    } else if (forAppartenance == 2) {
        size = 31;
    } else {
        size = 28;
    }
    
    size = size + 2;
    return size;
}

Blocks getBlocks(int forAppartenance) {
    Blocks blocklist;
    blocklist.size = getSize(forAppartenance);
    blocklist.blocks = (Block*) malloc(sizeof(Block) * blocklist.size);
    int i = -1;
    int stop = 0;

    while (stop == 0) {
        Block s1;
        s1.appartenance = 0;
        s1.size = 3;
        // Universal Block
        if (i == -1) {
        s1.size = 1;
        int content[5][5] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0}
        };
        fillBlock(&s1, content);
        }
        
        // Global blocks
        else if (i == 0) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 1) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 2) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 1, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 3) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 4) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 0, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 5) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 1, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 6) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 1, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 7) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 8) {
            s1.size = 4;
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 9) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 10) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 11) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 0, 0, 0, 0}
             };
             fillBlock(&s1, content);
        } else if (i == 12) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {1, 1, 1, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 13) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 14) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 15) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 1, 0, 0},
                {0, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 16) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 1, 0, 0},
                {1, 1, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 16) {
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 0, 0, 0, 0}
            };
            fillBlock(&s1, content);
        } else if (i == 17) {
            s1.size = 4;
            int content[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 1, 1, 0}
            };
            fillBlock(&s1, content);
        }
        
        else {
            stop = 1;
        }
        diagBlock(s1);
        printBlock(s1);
        blocklist.blocks[i] = s1;
        i++;
    }
    
    i--;
    
    // Blocks for Circle
    if (forAppartenance == 1) {
        stop = 0;
        
        while (stop == 0) {
            Block s1;
            s1.appartenance = 1;
            s1.size = 4;
            
            if (i == 18) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 19) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {0, 1, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 20) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 1, 0},
                    {1, 0, 0, 1, 0},
                    {1, 0, 0, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 21) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 22) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 23) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 24) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 25) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 26) {
                s1.size = 5;
                int content[5][5] = {
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 27) {
                s1.size = 5;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1},
                    {1, 0, 0, 0, 1}
                };
                fillBlock(&s1, content);
            } else if (i == 28) {
                s1.size = 5;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1}
                };
                fillBlock(&s1, content);
            } else if (i == 29) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            }
            
            
            else {
                stop = 1;
            }
            
            printBlock(s1);
            blocklist.blocks[i] = s1;
            i++;
        }
    }
    
    // Blocks for Losange
    else if (forAppartenance == 2) {
        stop = 0;
        
        while (stop == 0) {
            Block s1;
            s1.appartenance = 2;
            s1.size = 4;
            
            if (i == 18) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 19) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 0, 0, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 20) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 21) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {1, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 22) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 23) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 1, 0, 0},
                    {1, 0, 0, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 24) {
                s1.size = 5;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1},
                    {0, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 25) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 26) {
                s1.size = 5;
                int content[5][5] = {
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 27) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 28) {
                s1.size = 5;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1}
                };
                fillBlock(&s1, content);
            } else if (i == 29) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 30) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 31) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            }
            
            
            else {
                stop = 1;
            }
            
            printBlock(s1);
            blocklist.blocks[i] = s1;
            i++;
        }
    }
    
    // Blocks for Triangle
    else if (forAppartenance == 3){
        stop = 0;
        
        while (stop == 0) {
            Block s1;
            s1.appartenance = 3;
            s1.size = 3;
            
            if (i == 18) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0},
                    {0, 0, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 19) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 20) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {1, 1, 1, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 21) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 22) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 1, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 23) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 24) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 25) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 26) {
                s1.size = 2;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 27) {
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {1, 1, 1, 0, 0},
                    {0, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            } else if (i == 28) {
                s1.size = 2;
                int content[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0}
                };
                fillBlock(&s1, content);
            }
            
            else {
                stop = 1;
            }
            
            printBlock(s1);
            blocklist.blocks[i] = s1;
            i++;
        }
    }
    
    return blocklist;
}
