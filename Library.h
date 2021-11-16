#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#pragma once

#include "windows.h"
#include "Vector2.h"

class Renderer {

public:
	static void WriteOfPosition(Vector2 position, char submol);

	static void WriteOfPosition(COORD position, char submol);

	static void WriteOfPosition(int positionX, int positionY, char submol);
};

#endif 