/// @file       main.c
/// @author     Ivan OSADTSIV, Denys SHCHERBA.
/// @brief      main file of the game

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "const.h"
#include "monster.h"
#include "player.h"
#include "output.h"


/// @brief attacks monster if standing in same cell
/// @param player pointer to player
/// @param monster pointer to monster
/// @return 1 if monster is dead, 0 else
int attack(player_t* player, monster_t* monster)
{
    if((player->pos_x != monster->pos_x) || (player->pos_y != monster->pos_y))
    {
        printf("There is no monster in this cell!\n");
        return 0;
    }

    monster->HP -= rand() % (HPMAX - (HPMAX / 2) + 2);

    if(monster->HP > 0)
    {
        return 0;  // monseter is alive
    }
    else
    {
        return 1;  // monster is dead
    }
}

/// @brief    creates a field with size TMAP*TMAP
/// @return   pointer to list of pointers with size TMAP*TMAP
int** creationField()
{
    int** field = (int**)malloc(TMAP*sizeof(int*));
    for(size_t i = 0; i < TMAP; i++)
    {
        field[i] = malloc(TMAP*sizeof(int));
    }
    return field;
}

int main()
{
    srand(time(NULL));

    return EXIT_SUCCESS;
}

// gcc -c monster.c -o monster.o
// gcc -c player.c -o player.o
// gcc -c output.c -o output.o
// gcc -c const.c -o const.o
// gcc main.c monster.o player.o output.o const.o -o main        
// ./main