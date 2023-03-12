#include <stdlib.h>
#include <stdio.h>

#include "player.h"


int main (int argc, char * argv[]) 
{
    int x_test = 5;
    int y_test = 5;

    player_t* plyr_test = createPlayer (x_test, y_test);
    printf (toStringPl (plyr_test));
    // output_testing(plyr_test);
    replacement (plyr_test);
    printf (toStringPl (plyr_test));

    return EXIT_SUCCESS;
}
// gcc -c player.c -o player.o
// gcc player_test.c player.o -o main
// ./main
