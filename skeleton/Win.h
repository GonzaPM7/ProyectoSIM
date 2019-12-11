#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "ObstacleSystem.h"
#include "Player.h"

class Win
{
private: 
	Particle* hit;
	Vector3 lados;
	bool win;
public:
	Win(Vector3 pos, Vector3 lados, bool win_);
	void colission(Player*& player);
};

