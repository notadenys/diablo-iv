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

/// @brief finds if there is monster with same coords
/// @param monster 
/// @param monster_list 
/// @return 1 if there is a monster with same coords, 0 sinon
bool isMstInCell(monster_t* monster, monsterList_t* monster_list);

/// @brief adds a new monster to the list
/// @param listM 
/// @param p_pos_x 
/// @param p_pos_y 
/// @return 1 if creation succeeded, 0 sinon
bool addMst(monsterList_t* monster_list, int p_pos_x, int p_pos_y);

/// @brief deletes monster from the list
/// @param monster 
/// @param monster_list 
void deleteMst(monster_t* monster, monsterList_t* monster_list);

/// @brief їбу що це взагалі
/// @param M 
/// @return якби я нахуй знав
char* toStringMst(monster_t* M);

/// @brief якась хуйня
/// @param listM 
/// @return хуйню якусь
char* toStringLstMst(monsterList_t* listM);

#endif