#include <SFML/Graphics.hpp>
#include <Game.h>

int main()
{
    //Create the Game object.
    Game game1;
    //Main game loop.
    while(game1.window.isOpen())
    {
        game1.processEvents();
        game1.runLogic();
        game1.drawObjects();
    }

    return 0;
}


