//
//  main.c
//  Tetris
//
//  Created by PlugN on 02/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#include "fonctions_essentielles.h"


int main(int argc, const char * argv[]) {
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
     depose_block(mon_plateau, L, C, Block, 13, 6, MAX_BLOCK, MAX_BLOCK);
     //display_2D_array(mon_plateau, 15, 21);
     display_ascii(mon_plateau, L, C);
     free_2D_array(mon_plateau,L,C);
     free_2D_array(Block, MAX_BLOCK, MAX_BLOCK);
     return 0;
}
