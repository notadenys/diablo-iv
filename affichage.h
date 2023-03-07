/**
 * \file affichage.h
 * \author Denys SHCHERBA
 * \brief Module that defines the function that prints game field
*/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "player.h"
#include "monster.h"


/// @brief prints the game field with player as P and monster as M
/// @param player
/// @param monsters
void afficher(player_t* player, monsterList_t* monsters);

#endif