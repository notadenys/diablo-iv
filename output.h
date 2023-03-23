/// @file       output.h
/// @author     Ivan OSADTSIV, Denys SHCHERBA
/// @brief      Output of game deck

#ifndef OUTPUT_H
#define OUTPUT_H

#include "monster.h"
#include "player.h"

/// @brief      showing of game board 
/// @param      j player
/// @param      m monster
/// @return     game board with monsters and player
void showing(char field[TMAP][TMAP], monsterList_t* m, player_t* j);

#endif