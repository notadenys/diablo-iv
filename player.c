/// @file       player.c
/// @author     Ivan OSADTSIV, Denys SHCHERBA.
/// @brief      Module that defines player class, its metods and parameters.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "player.h"
#include "const.h"


/// @brief      moves player in selected direction (WASD).
/// @param j    player pointer.
/// @return     1 if replacement was successful, else 0.
int replacement (player_t* j)
{
    char choise;
    
    printf ("\nChoose direction of next move : \n");
    while ((choise  = getch()) != 'q')
    {
        switch (choise) 
        { 
            case 'd':
                if (j->pos_y + 1 <= TMAP) 
                {
                    j->pos_y++;

                    return 1;
                } 
                else 
                {
                    return 0;
                }
                break; 
            case 'w': 
                if (j->pos_x - 1 >= 0) 
                {
                    j->pos_x--;

                    return 1;
                } 
                else 
                {
                    return 0;
                }
                break;  
            case 'a': 
                if (j->pos_y - 1 >= 0) 
                {
                    j->pos_y--;

                    return 1;
                } 
                else 
                {
                    return 0;
                }
                break; 
            case 's': 
                if (j->pos_x + 1 <= TMAP) 
                {
                    j->pos_x++;

                    return 1;
                } 
                else 
                {
                    return 0;
                }
                break; 
            default: 
                break; 
        }
    }
}

/// @param pos_x    position of player in the X-axis.
/// @param pos_y    position of player in the Y-axis.
/// @return         pointer to the new player.
player_t* createPlayer (int pos_x, int pos_y) 
{
    player_t * j = malloc (sizeof (player_t));
    
    j->pos_x = pos_x;
    j->pos_y = pos_y;
    return j;
}

/// @brief      output of string with information
/// @param j    player pointer.
/// @return     string with required data.
char* toStringPl(player_t* j) 
{
    char* message = (char*) malloc(100 * sizeof(char));
    sprintf(message, "New positionX: %d Y: %d", j->pos_x, j->pos_y);

    return message;
}