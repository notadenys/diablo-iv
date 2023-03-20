/// @file       main.c
/// @author     Ivan OSADTSIV, Denys SHCHERBA.
/// @brief      main file of the game

#include <stdlib.h>
#include <stdio.h>

#include "const.h"
#include "monster.h"
#include "player.h"
#include "output.h"


/// @brief    creates a field with size TMAP*TMAP
/// @return   pointer to list of pointers with size TMAP*TMAP
int** creationField()
{
    int** field = (int**)malloc(TMAP*sizeof(int*));
    for(size_t i = 0; i < TMAP; i++)
    {
        field[i] = malloc(TMAP*sizeof(int));
    }
    return field;
}

int main()
{

    return EXIT_SUCCESS;
}

// gcc -c monster.c -o monster.o
// gcc -c player.c -o player.o
// gcc -c output.c -o output.o
// gcc -c const.c -o const.o
// gcc main.c monster.o player.o output.o const.o -o main        
// ./main