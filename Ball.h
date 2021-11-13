#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#pragma once

#include "Platform.h"

class Ball
{
	int _mapSizeX;
	int _mapSizeY;

	Platform* _playerPlatform;

	Vector2 _position;

	Vector2 _oldPosition;

public:
	Ball(int mapSizeX, int mapSizeY, Platform* playerPlatform, char submol = 'o');
	Ball(int mapSizeX, int mapSizeY, Platform* playerPlatform, Vector2 startPos, char submol = 'o');

	char Submol;

	Vector2 MoveDirection{ 1, 1 };

	int Score;

public:
	void MoveBall();
	void WriteBall();

	void Clear();

	Vector2 CheckCollision();

	void SetPosition(const Vector2& newPosition);

	Vector2 GetPosition();
};

#endif