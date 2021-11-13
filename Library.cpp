#include "Library.h"


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

void Renderer::WriteOfPosition(int positionX, int positionY, std::string string)
{
	COORD position{ positionX, positionY };
	SetCursorPos(positionX, positionY);

	std::cout << string;
}
