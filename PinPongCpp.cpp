#include <Windows.h>
#include <thread>
#include "Game.h"

int Tick = 25;

Game* game;

int main()
{
    game = new Game();

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
