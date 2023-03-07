/// @file       player.h
/// @author     Denys SHCHERBA, Ivan OSADTSIV.
/// @brief      Module that defines player class, its metods and parameters.

#ifndef PLAYER_H
#define PLAYER_H

/// @struct     player.
/// @typedef    player_t.
/// @brief      the player class
typedef struct player {
    int pos_x;  // Position in the X-axis of player.
    int pos_y;  // Position in the Y-axis of player.
} player_t;

/// @brief      moves player in selected direction (WASD).
/// @param j    player pointer.
/// @return     1 if replacement was successful, else 0.
int replacement(player_t* j);

/// @brief          creates a new player.
/// @param pos_x    position of player in the X-axis.
/// @param pos_y    position of player in the Y-axis.
/// @return         pointer to the new player.
player_t* creationPlayer(int pos_x, int pos_y);

/// @brief      output information for testing.
/// @param j    string with required data.
/// @return     string \a j.
char* toStringPl(player_t* j);

#endif
