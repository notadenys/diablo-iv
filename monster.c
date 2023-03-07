/// @file       affichage.h
/// @author     Denys SHCHERBA, Ivan OSADTSIV
/// @brief      Module that defines monster and monsterList class, its metods and parameters

#include "const.h"
#include "monster.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/// @brief creates the vide list of monsters
/// @return pointer to the list of monsters
monsterList_t* creationListM()
{
    monsterList_t* m = malloc(sizeof(monsterList_t));
    m->nbMst = 0;
    return m;
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
        monster_list->listM[monster_list->nbMst]->HP = HPMAX;
        
        srand(time(0));
        monster_list->listM[monster_list->nbMst]->pos_x = rand() % TMAP;
        monster_list->listM[monster_list->nbMst]->pos_y = rand() % TMAP;
        while(isMstInCell(monster_list->listM[monster_list->nbMst], monster_list))
        {
            monster_list->listM[monster_list->nbMst]->pos_x = rand() % TMAP;
            monster_list->listM[monster_list->nbMst]->pos_y = rand() % TMAP;
        }
        ++(monster_list->nbMst);
    }
}

/// @brief deletes monster from the list
/// @param monster 
/// @param monster_list 
void deleteMst(monster_t* monster, monsterList_t* monster_list)
{
    
}

/// @brief їбу що це взагалі
/// @param M 
/// @return якби я нахуй знав
char* toStringMst(monster_t* M);

/// @brief якась хуйня
/// @param listM 
/// @return хуйню якусь
char* toStringLstMst(monsterList_t* listM);
