/// @file player.h
/// @author Denys SHCHERBA, Ivan OSADTSIV
/// @brief Module that defines player class, its metods and parameters

#ifndef PLAYER_H
#define PLAYER_H

/// @brief defines the player class
typedef struct player
{
    int pos_x;
    int pos_y;
} player_t;

/// @brief moves player in selected direction (WASD)
/// @param j
/// @return 1 if success, 0 sinon
int replacement(player_t* j);

/// @brief creates a new player
/// @param pos_x
/// @param pos_y 
/// @return pointer to the new player
player_t* creationPlayer(int pos_x, int pos_y);

/// @brief я не зрозумів ніхуя
/// @param j 
/// @return хуй зна
char* toStringPl(player_t* j);

#endif