/// @file       player_test.h
/// @author     Ivan OSADTSIV, Denys SHCHERBA.
/// @brief      Test of "monster" module

#include <stdlib.h>
#include <stdio.h>

#include "monster.h"

int main(int argc, char * argv[]) 
{
    int p_pos_x = 5;
    int p_pos_y = 5;
    monsterList_t* mst_list = creationListM();
    addMst(mst_list, p_pos_x, p_pos_y);
    // printf(index_mst(mst_list->listM[0], mst_list));
    //printf(toStringMst(mst_list->listM[0]));
    //printf("\n");

    addMst(mst_list, p_pos_x, p_pos_y);
    // // printf(index_mst(mst_list->listM[1], mst_list));
    // printf(toStringMst(mst_list->listM[1]));
    // printf("\n");

    addMst(mst_list, p_pos_x, p_pos_y);
    // // printf(index_mst(mst_list->listM[2], mst_list));
    // printf(toStringMst(mst_list->listM[2]));
    // printf("\n");

    addMst(mst_list, p_pos_x, p_pos_y);
    // // printf(index_mst(mst_list->listM[3], mst_list));
    // printf(toStringMst(mst_list->listM[3]));
    // printf("\n");
    // printf("\n");
    // printf("\n");
    toStringLstMst(mst_list);
    return EXIT_SUCCESS;
}

// gcc -c monster.c -o monster.o
// gcc monster_test.c monster.o -o main
// ./main