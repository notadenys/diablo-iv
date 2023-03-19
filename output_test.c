#include <stdlib.h>
#include <stdio.h>

#include "output.h"

int main(int argc, char * argv[]) {
    int x_test = 5;
    int y_test = 5;
    int field[TMAP][TMAP] = {0};
    monsterList_t* mst_list = creationListM();
    player_t* plyr_test = createPlayer (x_test, y_test);
    showing(field, mst_list, plyr_test);
    return EXIT_SUCCESS;
}

// gcc -c output.c -o output.o
// gcc output_test.c output.o -o main
// ./main