/// @file       monster.c
/// @author     Denys SHCHERBA, Ivan OSADTSIV
/// @brief      Module that defines monster and monsterList class, its metods and parameters

#include "const.h"
#include "monster.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

/// @brief creates the vide list of monsters
/// @return pointer to the list of monsters
monsterList_t* createListM()
{
    monsterList_t* m = malloc(sizeof(monsterList_t));
    m->nbMst = 0;
    return m;
}

/// @brief finds the index of particular monster in monster_list
/// @param monster 
/// @param monster_list 
/// @return index of monster, else -1
int index_mst(monster_t* monster, monsterList_t* monster_list)
{
    for(size_t i = 0; i < monster_list->nbMst; i++)
    {
        if(monster_list->listM[i] == monster)
        {
            return i;
        }
    }
    return -1;
}

/// @brief finds if there is monster with same coords
/// @param monster 
/// @param monster_list 
/// @return 1 if there is a monster with same coords, 0 sinon
bool isMstInCell(monster_t* monster, monsterList_t* monster_list)
{
    for(size_t index = 0; index < monster_list->nbMst; index++)
    {
        if ((monster_list->listM[index]->pos_x == monster->pos_x) && (monster_list->listM[index]->pos_y == monster->pos_y))
        {
            return 1;
        }
    }
    return 0;
}

/// @brief adds a new monster to the list
/// @param monster_list 
/// @param p_pos_x
/// @param p_pos_y 
/// @return 1 if creation succeeded, 0 sinon
bool addMst(monsterList_t* monster_list, int p_pos_x, int p_pos_y)
{
    if (monster_list->nbMst < TMAP*TMAP)
    {
        monster_list->listM[monster_list->nbMst] = malloc(sizeof(monster_t));
        monster_list->listM[monster_list->nbMst]->HP = rand() % (HPMAX - 9) + 10;

        monster_t* monster = malloc(sizeof(monster_t));
        monster->pos_x = rand() % TMAP;
        monster->pos_y = rand() % TMAP;
        while(isMstInCell(monster, monster_list) || ((monster->pos_x == p_pos_x) && (monster->pos_y == p_pos_y)))
        {
            monster->pos_x = rand() % TMAP;
            monster->pos_y = rand() % TMAP;
        }
        monster_list->listM[monster_list->nbMst]->pos_x = monster->pos_x;
        monster_list->listM[monster_list->nbMst]->pos_y = monster->pos_y;
        ++(monster_list->nbMst);
    }
}

/// @brief removes monster from the list
/// @param monster 
/// @param monster_list 
void rmvMst(monster_t* monster, monsterList_t* monster_list)
{
    int indexToRemove = index_mst(monster, monster_list);
    if(indexToRemove == -1)
    {
        printf("NoMonsterError: there is no such monster.");
    }
    else 
    {
        for(size_t i = indexToRemove; i < monster_list->nbMst; i++)
        {
            monster_list->listM[i] = monster_list->listM[i+1];
        }
        --(monster_list->nbMst);
    }
}

/// @brief output info about selected monster for the needs of tests
/// @param m monster pointer
/// @return string with data
char* toStringMst(monster_t* m)
{
    char* message = (char*) malloc(100 * sizeof(char));

    sprintf(message, "X : %d, Y : %d, HP: %d", m->pos_x, m->pos_y, m->HP);

    return message;
}

/// @brief output info about all the monsters
/// @param monster_list 
/// @return string with all required data
char* toStringLstMst(monsterList_t* monster_list)
{
    char* full_message = (char*) malloc(100 * sizeof(char));
    for(size_t i = 0; i < monster_list->nbMst; i++)
    {   
        sprintf(full_message, "%s\n", toStringMst(monster_list->listM[i]));
        puts(full_message);
    }
    return full_message;
}
// gcc -c monster.c -o monster.o
// gcc monster_test.c monster.o -o main
// ./main