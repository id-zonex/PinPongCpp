#include <Windows.h>
#include "Game.h"

int Tick = 25;

int main()
{
    Game* game = new Game();

    game->BeginPlay();

    while (true)
    {
        game->Update();
        game->Render();

        if (GetAsyncKeyState(VK_ESCAPE))
            break;

        Sleep(Tick);
    }
}