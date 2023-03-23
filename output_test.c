#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "output.h"
#include "player.h"
#include "monster.h"

int main(int argc, char * argv[]) {
    int x_test = 5;
    int y_test = 5;
    srand(time(NULL));
    char field[TMAP][TMAP] = {0};
    monsterList_t* mst_list = creationListM();
    addMst(mst_list, x_test, y_test);
    addMst(mst_list, x_test, y_test);
    addMst(mst_list, x_test, y_test);
    player_t* plyr_test = createPlayer (x_test, y_test);
    showing(field, mst_list, plyr_test);
    return EXIT_SUCCESS;
}

// gcc -c output.c -o output.o
// gcc -c monster.c -o monster.o
// gcc -c player.c -o player.o
// gcc output_test.c monster.o player.o output.o -o main  
// ./main