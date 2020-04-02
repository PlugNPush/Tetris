//
//  fonctions_essentielles.h
//  Tetris
//
//  Created by PlugN on 02/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#ifndef fonctions_essentielles_h
#define fonctions_essentielles_h

#include "global.h"

int** create_2D_Array(int nb_lig, int nb_col);
void fill_2D_plateau_Carre(int** P, int nb_lig, int nb_col);
void fill_Forme_T(int** P, int nb_lig, int nb_col);
void display_2D_array(int** P, int nb_lig, int nb_col);
void display_ascii(int** P, int nb_lig, int nb_col);
void depose_block(int** P, int nb_lig, int nb_col, int** B, int Px, int Py, int nb_lig_B, int nb_col_B);
void getDim2Darray(int *l, int*c);
void free_2D_array(int **A, int l, int c);


#endif /* fonctions_essentielles_h */
