//
//  main.c
//  Tetris
//
//  Created by PlugN on 02/04/2020.
//  Copyright © 2020 PlugN. All rights reserved.
//

#include "projet1c.h"


void initGame(int*** gamepad, int* lines, int* col, int* gamestyle, int* pickerstyle) {
    *gamestyle = 0;
    *pickerstyle = -1;
    while (*gamestyle != 1 && *gamestyle != 2 && *gamestyle != 3) {
        printf("Quel type de terrain voulez-vous ? (1 - Circle, 2 - Losange, 3 - Triangle) ? ");
        scanf("%d", gamestyle);
    }
    
    while (*pickerstyle != 0 && *pickerstyle != 1) {
        printf("Quel style de jeu voulez-vous ? (0 - Montrez tout les blocks, 1 - Montrez 3 blocks aléatoires) ? ");
        scanf("%d", pickerstyle);
    }
    
    
    getDim2Darray(lines, col);
    *gamepad = create_2D_Array(*lines, *col);
    fill_2D_plateau_Carre(*gamepad, *lines, *col);
    
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
    
    // Ré-ajustement des coordonnées pour simplifier la vérification
    y = y - block.size + 1;
    
    // Vérifications de dépassement
    if (x < 0) {
        printf("DA");
        return 0;
    } else if (y < 0) {
        printf("DB");
        return 0;
    } else if (x + block.size > lines) {
        printf("DC");
        return 0;
    } else if (y + block.size > col) {
        printf("DD");
        return 0;
    }
    
    // Vérifications superpositions et sorties
    int i, j;
    for (i=0;i<block.size; i++)
    {
        for (j=0;j<block.size; j++)
        {
            if (gamepad[x+i][y+j] == -1 || (gamepad[x+i][y+j] == 1 && block.content[i][j] == 1)) {
                printf("ERROR ON x = %d, y = %d i = %d j = %d", x, y, i, j);
                return 0;
            }
        }
    }
    
    y = y + block.size - 1;
    //Failsafe  --> vérification suplémentaire 
    while(i<block.size)
       {
           j=0;
           while(j<block.size)
           {
               if (x-i < 0) {
                   return 0;
               } else if (y+j > col) {
                   return 0;
               } else if (block.size-i-1 < 0) {
                   return 0;
               } else if (block.size-j-1 < 0) {
                   return 0;
               }
               j++;
           }
           i++;
       }
    
    return 1;
}

void game(Blocks blocks, int*** gamepad, int lines, int col, int gamestyle, int pickerstyle, int* score) {
    
    printf("\n\n\n");
    
    int i, j;
    for (i=0;i<lines; i++)
    {
        for (j=0;j<col; j++)
        {
            if (etat_ligne(*gamepad, col, i) == 1) {
                annuler_ligne(gamepad, lines, col, i);
            }
            if (etat_colonne(*gamepad, lines, j) == 1) {
                annuler_colonne(gamepad, lines, col, j);
            }
        }
    }
    
    int attempts = 0;
    
    display_2D_array(*gamepad, lines, col);
    
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
    
    int round = 0;
    
    while (round == 0) {
    
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
            round = 1;
            game(blocks, gamepad, lines, col, gamestyle, pickerstyle, score);
        } else {
            attempts++;
            printf("Vous ne pouvez pas jouer ici !\n");
            
            if (attempts >= 3) {
                printf("Fin de la partie ! Score : %d\n", *score);
                return;
            }
        }
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

    game(blocks, &gamepad, lines, col, gamestyle, pickerstyle, &score);
    
    free_2D_array(gamepad, lines, col);
    
     return 0;
}
