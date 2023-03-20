/// @file       player_test.h
/// @author     Ivan OSADTSIV, Denys SHCHERBA.
/// @brief      Test of "monster" module

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "monster.h"

int main(int argc, char * argv[]) 
{
    int p_pos_x = 5;
    int p_pos_y = 5;
    srand(time(NULL));
    monsterList_t* mst_list = creationListM();
    addMst(mst_list, p_pos_x, p_pos_y);
    addMst(mst_list, p_pos_x, p_pos_y);
    addMst(mst_list, p_pos_x, p_pos_y);
    addMst(mst_list, p_pos_x, p_pos_y);

    toStringLstMst(mst_list);

    rmvMst(mst_list->listM[2], mst_list);

    printf("-------------------\n");
    toStringLstMst(mst_list);
    return EXIT_SUCCESS;
}

// gcc -c monster.c -o monster.o
// gcc monster_test.c monster.o -o main
// ./main