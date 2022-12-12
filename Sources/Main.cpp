#include "Game.h"
#include <time.h>

using namespace std;
using namespace sf;

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Game game;

    game.run();

    //End of application
    return 0;
}