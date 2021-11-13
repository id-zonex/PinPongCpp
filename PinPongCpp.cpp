#include <iostream>
#include <cmath>
#include "windows.h"
#include "Library.h"
#include "Platform.h"
#include "Ball.h"
#include <vector>

void WriteMap();
void Clear();

int Hight = 15;
int Weigth = 80;

int main()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

    Platform* player = new Platform(Vector2(Weigth, 2), Hight);

    std::vector<Ball> balls;
    balls.push_back(Ball(Weigth, Hight, player));

    Clear();
    WriteMap();
    player->WritePlatform();

    while (true) 
    {
        for (int i = 0; i < balls.size(); i++) 
        {
            balls[i].MoveBall();
            balls[i].WriteBall();
        }

        player->ControlePlatform();
        
        Sleep(25);

        if (GetAsyncKeyState(VK_ESCAPE))
            break;
    }

    Clear();
}

void WriteMap()
{
    SHORT x, y;

    for (x = 0; x <= Weigth + 1; x++)
    {
        for (y = 0; y <= Hight + 1; y++)
        {
            if ((x == 0 || x > Weigth) || (y == 0 || y > Hight)) 
                Renderer::WriteOfPosition(x, y, '*');
        }
    }
}

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    system("clear");
#endif
}
