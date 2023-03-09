/// @file       monster.h
/// @author     Denys SHCHERBA, Ivan OSADTSIV.
/// @brief      Module that defines monster and monsterList class, its metods and parameters

#ifndef MONSTER_H
#define MONSTER_H

#include "const.h"
#include <stdbool.h>


/// @brief monster class
typedef struct monster
{
    int pos_x;
    int pos_y;
    int HP;
} monster_t;

/// @brief class of list of pointers to monster
typedef struct monsterList
{
    monster_t* listM[TMAP*TMAP];
    int nbMst;
} monsterList_t;

/// @brief creates the vide list of monsters
/// @return pointer to the list of monsters
monsterList_t* creationListM();

/// @brief finds the index of particular monster in monster_list
/// @param monster 
/// @param monster_list 
/// @return index of monster
int index(monster_t* monster, monsterList_t* monster_list);

/// @brief finds if there is monster with same coords
/// @param monster 
/// @param monster_list 
/// @return 1 if there is a monster with same coords, 0 sinon
bool isMstInCell(monster_t* monster, monsterList_t* monster_list);

/// @brief adds a new monster to the list
/// @param monster_list 
/// @param p_pos_x 
/// @param p_pos_y 
/// @return 1 if creation succeeded, 0 sinon
bool addMst(monsterList_t* monster_list, int p_pos_x, int p_pos_y);

/// @brief removes monster from the list
/// @param monster 
/// @param monster_list 
void rmvMst(monster_t* monster, monsterList_t* monster_list);

/// @brief output info about selected monster for the needs of tests
/// @param M monster pointer
/// @return string with data
char* toStringMst(monster_t* M);

/// @brief output info about all the monsters
/// @param monster_list 
/// @return string with all required data
char* toStringLstMst(monsterList_t* monster_list);

#endif
