#include "projet1c.h"

//------------------------- Fonctions des blocks--------------------------//
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





void printBlocker(Block block) {
    int i, j;
    int size = block.size;
    printf((size == 1) ? "-\n" : (size == 2) ? "- -\n" : (size == 3) ? "- - -\n" : (size == 4) ? "- - - -\n" : "- - - - -\n");
    for (i = 0; i < size ; i++) {
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

void printBlocks(Blocks blocks) {
    int i;
    for (i=0; i<blocks.size; i++) {
        printBlocker(blocks.blocks[i]);
        printf("^ Bloc n°%d ^\n\n", i);
    }
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
            
            blocklist.blocks[i] = s1;
            i++;
        }
    }
    
    return blocklist;
}











//-----------------------Fonction essentiels à partir de moodle---------------------------------------//




/*---------- Fonction qui créee un tableau dynamique à deux dimenstions -------*/
int** create_2D_Array(int nb_lig, int nb_col)
{
    int i;
    int** plateau=(int**)malloc(nb_lig*sizeof(int*));
    for (i=0;i<nb_col; i++)
    {
        plateau[i]=(int*)malloc(nb_col*sizeof(int));
    }
    return plateau;
}

/* ---- une fonction qui remplit le plateau de jeu avec une zonne de jeu carrée */
void fill_2D_plateau_Carre(int** P, int nb_lig, int nb_col)
{
    int i, j;
    for (i=0;i<nb_lig; i++)
    {
        for (j=0;j<nb_col; j++)
        {
            P[i][j]=0;
        }
    }
    // placer les valeurs 1

//    for (i=3;i<nb_lig-3; i++)
//    {
//        for (j=3;j<nb_col-3; j++)
//        {
//            P[i][j]=1;
//        }
//    }
}

/*------- Remplissage d'un Block (Tableau 2D) avec la forme T  --------*/
void fill_Forme_T(int** P, int nb_lig, int nb_col)
{
    int i, j;
    for (i=0;i<nb_lig; i++)
    {
        for (j=0;j<nb_col; j++)
        {
            P[i][j]=0;
        }
    }
    // placer les valeurs 1

    for (i=1;i<nb_lig-1; i++)
    {
            P[nb_lig-1][i]=1;
    }
    for (i=1;i<nb_lig-1; i++)
    {
            P[i][nb_col/2]=1;
    }
}


/*------- Affichage d'un Tableau 2D  --------*/

void display_2D_array(int** P, int nb_lig, int nb_col)
{
    int i, j;
    printf("   ");
    for (j=0; j<nb_col; j++) {
        printf("%c ", j+65);
    }
    printf("\n");
    
    for (i=0;i<nb_lig; i++)
    {
        if (i+1 < 10) {
            printf("%d  ", i+1);
        } else {
            printf("%d ", i+1);
        }
        
        for (j=0;j<nb_col; j++)
        {
            if (P[i][j] == OCCUPE){
                printf("■ ");
            } else {
                printf("* ");
            }
            //printf("%3d", P[i][j]) ;
        }
        printf("\n");
    }
}

/*------- Affichage d'un Tableau 2D associant des codes asccii au chiffres 0, 1 et 2, vous choisirez le caractère que vous voulez pour 1 et 2 --------*/

void display_ascii(int** P, int nb_lig, int nb_col)
{
    int i, j;
    for (i=0;i<nb_lig; i++)
    {
        for (j=0;j<nb_col; j++)
        {
            if(P[i][j]==0)
            {
                printf("%3c", ' ');
            }
            else
            {
               if (P[i][j]==1)
               {
                    printf("%3c", '*');
               }
               else
               {
                   printf("%3c", '#');
               }

            }

        }
        printf("\n");
    }
}


/*------- Déposer un bloc B sur le plateau P à une position (Px,Py) 2D --------*/

void depose_block(int** P, int nb_lig, int nb_col, int** B, int Px, int Py, int size)
{
    int nb_lig_B = size;
    int nb_col_B = size;
    
    int i=0;
    int j;
    while(i<nb_lig_B)
    {
        j=0;
        while(j<nb_col_B)
        {
            P[Px-i][Py+j]=P[Px-i][Py+j]+ B[nb_lig_B-i-1][nb_col_B-j-1];
            j++;
        }
        i++;
    }
}
/*------- Saisie sécurisée des dimenstions d'un Tableau 2D --------*/
void getDim2Darray(int *l, int*c)
{
    int n,ch;
    do{
        printf("Entrez le nombre de lignes (>=21) et de colonnes (>=21) de votre plateau \n");
        n=scanf(" %d%d",l,c);
        while ((ch = (int)getchar()) != '\n' && ch != EOF);
    }while (n!=2 || (n==2 && (*l<21 ||*c<21)));
}

/* ------- Free 2D array ------*/

void free_2D_array(int **A, int l, int c)
{
    int i;
    for(i=0;i<l;i++)
        free (A[i]);
    free (A);
}

int main_copy1()
{

    //   _____________________
    //  |    ----------      |
    //  |    ----------      |
    //  |    ----------      |
    //  |____________________|
    int** mon_plateau;
    int L,C;
    int **Block;
    getDim2Darray(&L,&C);
    mon_plateau=create_2D_Array(L, C);
    fill_2D_plateau_Carre(mon_plateau, L, C);
    //display_2D_array(mon_plateau, L, C);
    Block=create_2D_Array(MAX_BLOCK, MAX_BLOCK);
    fill_Forme_T(Block, MAX_BLOCK, MAX_BLOCK);
    //display_2D_array(Block, MAX_BLOCK, MAX_BLOCK);
    // placer le bloc T à la position (13, 6)
    depose_block(mon_plateau, L, C, Block, 13, 6, MAX_BLOCK);
    //display_2D_array(mon_plateau, 15, 21);
   display_ascii(mon_plateau, L, C);
    free_2D_array(mon_plateau,L,C);
    free_2D_array(Block, MAX_BLOCK, MAX_BLOCK);
    return 0;
}
