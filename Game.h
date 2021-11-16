#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Ball.h"
#include "Platform.h"

#pragma once
class Game
{
	void WriteMap();
	void Clear();

	int _hight = 15;
	int _weigth = 80;

	std::vector<Ball> _actors;

	Platform* _player;

public:
	void BeginPlay();

	void Update();

	void Render();
};

#endif

