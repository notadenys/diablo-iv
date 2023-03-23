/// @file       output.c
/// @author     Ivan OSADTSIV, Denys SHCHERBA
/// @brief      Output of game deck

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "monster.h"
#include "player.h"
#include "output.h"


void showing(char field[TMAP][TMAP], monsterList_t* m, player_t* j)
{   
    for(int k=0; k < m->nbMst; k++)
    {
        field [m->listM[k]->pos_x][m->listM[k]->pos_y] = 'M';
    }
    field [j->pos_x][j->pos_y] = 'P';
    for(int i=0; i < TMAP; i++) 
    {
        printf("\n ");
        for(int j=0; j < TMAP; j++) 
        {
            printf("%*c", 5, field[i][j]);
            
        }
        printf("\n");
    }
}

// gcc -c output.c -o output.o
// gcc -c monster.c -o monster.o
// gcc -c player.c -o player.o
// gcc output_test.c monster.o player.o output.o -o main  
// ./main