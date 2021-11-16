#include "Game.h"
#include "Library.h"
#include "Platform.h"
#include "Ball.h"
#include "Vector2.h"
#include "windows.h"
#include <vector>

void Game::BeginPlay()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

    _player = new Platform(Vector2(_weigth, 2), _hight);

    _actors.push_back(Ball(_weigth, _hight, _player));

    Clear();

    Render();
    WriteMap();
}

void Game::Update()
{
    for (int i = 0; i < _actors.size(); i++)
    {
        _actors[i].MoveBall();
    }

    _player->ControlePlatform();
}

void Game::Render()
{
    for (int i = 0; i < _actors.size(); i++)
    {
        _actors[i].WriteBall();
    }

    _player->WritePlatform();
}

void Game::WriteMap()
{
    int x, y;

    for (x = 0; x <= _weigth + 1; x++)
    {
        for (y = 0; y <= _hight + 1; y++)
        {
            if ((x == 0 || x > _weigth) || (y == 0 || y > _hight))
                Renderer::WriteOfPosition(x, y, '*');
        }
    }
}

void Game::Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    system("clear");
#endif
}