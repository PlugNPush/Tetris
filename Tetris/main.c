//
//  main.c
//  Tetris
//
//  Created by PlugN on 02/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#include "fonctions_essentielles.h"
#include "blocks.h"

void initGame(int*** gamepad, int* lines, int* col, int* gamestyle) {
    *gamestyle = 0;
    while (*gamestyle != 1 && *gamestyle != 2 && *gamestyle != 3) {
        printf("What style do you want (1 - Circle, 2 - Losange, 3 - Triangle) ? ");
        scanf("%d", gamestyle);
    }
    
    
    getDim2Darray(lines, col);
    *gamepad = create_2D_Array(*lines, *col);
    fill_2D_plateau_Carre(*gamepad, *lines, *col);
    
    //TODO: Generer les tableaux circulaires, losanges et triangulaires à partir d'ici en insérant des -1 sur les bordures externes
}

int etat_ligne(int** gamepad, int col, int ligne) {
    int i;
    for (i=0; i<col; i++) {
        if (gamepad[ligne][i] == LIBRE) {
            return 0;
        }
    }
    return 1;
}

int etat_colonne(int** gamepad, int lignes, int colonne) {
    int i;
    for (i=0; i<lignes; i++) {
        if (gamepad[i][colonne] == LIBRE) {
            return 0;
        }
    }
    return 1;
}

void calcul_score(int* score, int lignes, int col, int type) {
    if (type == COLONNE) {
        *score += col;
    } else {
        *score += lignes;
    }
}

void annuler_ligne(int*** gamepad, int lignes, int col, int ligne) {
    int i;
    for (i=0; i<col; i++) {
        if (*gamepad[ligne][i] == OCCUPE) {
            gamepad[ligne][i] = LIBRE;
        }
    }
}

void annuler_colonne(int*** gamepad, int lignes, int col, int colonne) {
    int i;
    for (i=0; i<lignes; i++) {
        if (*gamepad[i][colonne] == OCCUPE) {
            gamepad[i][colonne] = LIBRE;
        }
    }
}

int verifBlock(Block block, int** gamepad, int lines, int col, int x, int y) {
    //TODO: Vérifier que le block peut être placé
    
    //MARK: SPOILER - Pour simplifier le processus, on décale les coordonnes du block par sa taille pour retrouver un placement 0,0 et faciliter les vérifications.
    //MARK: La fonction de placement est déjà au bon format, inutile d'enregistrer la conversion 0,0.
    
    return 0;
}

void game(Blocks blocks, int*** gamepad, int lines, int col, int gamestyle, int score) {
    // TODO: La fonction. Récursive.
    // MARK: Demander la saisie, ne pas oublier de convertir en chiffre partant de 0, vérifier et placer, ou répéter. Inclure le random pour choisir 3 blocs dans la liste.
    
}

int main(int argc, const char * argv[]) {
    
    
    int** gamepad = NULL;
    int gamestyle;
    int lines, col;

    initGame(&gamepad, &lines, &col, &gamestyle);
    
    Blocks blocks = getStandardizedBlocks(gamestyle);

    display_2D_array(gamepad, lines, col);

    depose_block(gamepad, lines, col, blocks.blocks[5].content, 4, 4, blocks.blocks[5].size);

    printf("\n\n");
    display_2D_array(gamepad, lines, col);
    
    free_2D_array(gamepad, lines, col);
    
     return 0;
}
