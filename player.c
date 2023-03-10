/// @file       player.c
/// @author     Denys SHCHERBA, Ivan OSADTSIV.
/// @brief      Module that defines player class, its metods and parameters.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "player.h"
#include "const.h"


/// @brief      moves player in selected direction (WASD).
/// @param j    player pointer.
/// @return     1 if replacement was successful, else 0.
int replacement (player_t* j)
{
    char choise;
    
    printf ("\nChoose direction of next move : ");
    scanf ("%1c", &choise);
    if (choise == 'w') 
    {
        if (j->pos_y + 1 <= TMAP) 
        {
            ++(j->pos_y);
            return 1;
        } 
        else 
        {
            return 0;
        }
    } 
    else if (choise == 's') 
    {
        if (j->pos_y - 1 >= 0) 
        {
            --(j->pos_y);

            return 1;
        } 
        else 
        {
            return 0;
        }
    } 
    else if (choise == 'd') 
    {
        if (j->pos_x + 1 <= TMAP) 
        {
            ++(j->pos_x);

            return 1;
        } 
        else 
        {
            return 0;
        }
    } 
    else if (choise == 'a') 
    {
        if (j->pos_x - 1 >= 0) 
        {
            --(j->pos_x);

            return 1;
        }
         else 
        {
            return 0;
        }
    } 
    else 
    {
        return 0;
    }
}

/// @brief          creates a new player.
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

/// @brief      output information for testing.
/// @param j    player pointer.
/// @return     string with required data.
char* toStringPl(player_t* j)
{
    char *message;
    char pos_x_ch[2];
    char pos_y_ch[2];

    sprintf(pos_x_ch, "%d", j->pos_x);
    sprintf(pos_y_ch, "%d", j->pos_y);

    message = (char *) malloc (10);
    free (message);

    strcpy (message, "X:");
    strcat (message, pos_x_ch);
    strcat (message, " ");
    strcat (message, "Y:");
    strcat (message, pos_y_ch);

    return message;
}
