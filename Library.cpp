#include <iostream>
#include "Library.h"
#include "Vector2.h"


void Renderer::WriteOfPosition(Vector2 position, char submol)
{
	WriteOfPosition(position.X, position.Y, submol);
}

void Renderer::WriteOfPosition(COORD position, char submol)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hout, position);
	std::cout << submol;
}

void Renderer::WriteOfPosition(int positionX, int positionY, char submol)
{
	COORD position{ positionX, positionY };
	WriteOfPosition(position, submol);
}

