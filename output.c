#include <stdlib.h>
#include <stdio.h>

#include "monster.h"
#include "player.h"
#include "output.h"


void showing(int field[TMAP][TMAP], monsterList_t* m, player_t* j)
{   
    for(int i = 0; i < TMAP; i++) {
        for(int j = 0; j < TMAP; j++) {
            printf("%*d", 5, field[i][j]);
        }
        printf("\n");
    }
}

