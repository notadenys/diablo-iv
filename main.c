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

// /// @brief    creates a field with size TMAP*TMAP
// /// @return   pointer to list of pointers with size TMAP*TMAP
// char createField()
// {
//     char field[TMAP][TMAP] = {0};
//     return field;
// }

void play()
{
    srand(time(NULL));
    char field[TMAP][TMAP] = {0};
    player_t* player = createPlayer(TMAP/2, TMAP/2);
    monsterList_t* monster_list = createListM();

    // defines the number of monsters (doubles the difficulty numbers and adds 3)
    int difficulty;
    printf("Choose the difficulty:\n");
    scanf("%d", &difficulty);
    difficulty += 3 + difficulty;


    for(size_t i = 0; i < difficulty; i++)
    {
        addMst(monster_list, player->pos_x, player->pos_y);
        printf("%d.\n", i);
    }

    while(monster_list->nbMst > 0)
    {
        system("cls");
        showing(field, monster_list, player);
        for(size_t index = 0; index < monster_list->nbMst; index++)
        {
            while(player->pos_x == monster_list->listM[index]->pos_x && player->pos_y == monster_list->listM[index]->pos_y)
            {
                if(attack(player, monster_list->listM[index]))
                {
                    printf("Monster killed!\n");
                    rmvMst(monster_list->listM[index], monster_list);
                }
            }
        }
        replacement(player);
    }
}

int main()
{
    play();
    return EXIT_SUCCESS;
}

// gcc -c monster.c -o monster.o
// gcc -c player.c -o player.o
// gcc -c output.c -o output.o
// gcc -c const.c -o const.o
// gcc main.c monster.o player.o output.o const.o -o main        
// ./main