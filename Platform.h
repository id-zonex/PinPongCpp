#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#pragma once

#include "Vector2.h"

class Platform
{
	Vector2 _position;

	int _border;

	int _size;
	int _yDirection = 1;

public:

	Platform(Vector2 position, int border, int size = 6);

	void ControlePlatform();
	void WritePlatform();

	void Clear();

	Vector2 GetLocation();
	int GetSize();
};

#endif
