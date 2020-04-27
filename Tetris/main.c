//
//  main.c
//  Tetris
//
//  Created by PlugN on 02/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#include "fonctions_essentielles.h"
#include "blocks.h"
#include "global.h"

void initGame(int*** gamepad, int* lines, int* col, int* gamestyle, int* pickerstyle) {
    *gamestyle = 0;
    *pickerstyle = -1;
    while (*gamestyle != 1 && *gamestyle != 2 && *gamestyle != 3) {
        printf("What style do you want (1 - Circle, 2 - Losange, 3 - Triangle) ? ");
        scanf("%d", gamestyle);
    }
    
    while (*pickerstyle != 0 && *pickerstyle != 1) {
        printf("What style do you want (0 - Show all blocks, 1 - Select 3 random blocks) ? ");
        scanf("%d", pickerstyle);
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
    
    return 1;
}

void game(Blocks blocks, int*** gamepad, int lines, int col, int gamestyle, int pickerstyle, int* score, int attempts) {
    // TODO: La fonction. Récursive.
    // MARK: Demander la saisie, ne pas oublier de convertir en chiffre partant de 0, vérifier et placer, ou répéter. Inclure le random pour choisir 3 blocs dans la liste.
    
    printf("\n\n\n");
    
    display_2D_array(*gamepad, lines, col);
    
    if (attempts >= 3) {
        printf("Fin de la partie ! Score : %d\n", *score);
        return;
    }
    
    int selected = 0;
    int select = 0;
    Block selector;
    selector.appartenance = 0;
    selector.size = 0;
    int content[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };
    fillBlock(&selector, content);
    
    while (selected == 0) {
    
        if (pickerstyle == 0) {
            printBlocks(blocks);
            printf("Choisissez un bloc parmis tous ceux proposés.");
            scanf("%d", &selected);
            if (selected < blocks.size) {
                selected = 1;
                selector = blocks.blocks[select];
            }
        } else {
            int r1 = rand() % blocks.size;
            int r2 = rand() % blocks.size;
            int r3 = rand() % blocks.size;
                
            printBlocker(blocks.blocks[r1]);
            printf("^ Bloc n°1 ^\n\n");
            printBlocker(blocks.blocks[r2]);
            printf("^ Bloc n°2 ^\n\n");
            printBlocker(blocks.blocks[r3]);
            printf("^ Bloc n°3 ^\n\n");
        
            int select;
            printf("Choisissez un bloc parmis tous ceux proposés.\n");
            scanf("%d", &select);
            if (select == 1) {
                selected = 1;
                selector = blocks.blocks[r1];
            } else if (select == 2) {
                selected = 1;
                selector = blocks.blocks[r2];
            } else if (select == 3) {
                selected = 1;
                selector = blocks.blocks[r3];
            }
        }
    }
    
    display_2D_array(*gamepad, lines, col);
    
    char sca;
    int scb;
    fflush(stdin);
    printf("Veuillez saisir les coordonnées de placement du block (lettre): ");
    scanf("%c", &sca);
    fflush(stdin);
    printf("Veuillez saisir les coordonnées de placement du block (nombre): ");
    scanf("%d", &scb);
    fflush(stdin);
    
    int x, y;
    
    x = sca-65;
    y = scb - 1;
    
    if (verifBlock(selector, *gamepad, lines, col, x, y) == 1) {
        depose_block(*gamepad, lines, col, selector.content, x, y, selector.size);
        game(blocks, gamepad, lines, col, gamestyle, pickerstyle, score, attempts);
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    
    int** gamepad = NULL;
    int gamestyle;
    int lines, col;
    int score = 0;
    int pickerstyle;
    
    srand((unsigned int)time(NULL));

    initGame(&gamepad, &lines, &col, &gamestyle, &pickerstyle);
    
    Blocks blocks = getStandardizedBlocks(gamestyle);

    game(blocks, &gamepad, lines, col, gamestyle, pickerstyle, &score, 0);
    
    free_2D_array(gamepad, lines, col);
    
     return 0;
}
