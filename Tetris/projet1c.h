#ifndef projet1c_h
#define projet1c_h



// Bibliothèques
#define MAX_BLOCK 5

#define INJOUABLE -1
#define LIBRE 0
#define OCCUPE 1

#define LIGNE 0
#define COLONNE 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Fonctions de bases
int** create_2D_Array(int nb_lig, int nb_col);
void fill_2D_plateau_Carre(int** P, int nb_lig, int nb_col);
void fill_Forme_T(int** P, int nb_lig, int nb_col);
void display_2D_array(int** P, int nb_lig, int nb_col);
void display_ascii(int** P, int nb_lig, int nb_col);
void depose_block(int** P, int nb_lig, int nb_col, int** B, int Px, int Py, int size);
void getDim2Darray(int *l, int*c);
void free_2D_array(int **A, int l, int c);


// gestion des blocks
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
void printBlocks(Blocks blocks);
void printBlocker(Block block);


#endif /* projet1c_h */