#include <time.h>
#include <stdlib.h>
#include "game.h"


int main(int argc, char *argv[])
{
    srand(time(NULL)); rand();
    Game game(argc, argv);
    return game.exec();
}
