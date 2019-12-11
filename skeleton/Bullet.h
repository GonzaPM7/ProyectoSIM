#pragma once
#include "Particulas.h"
#include "Enemy.h"
class Bullet
{
public:
	Particle* bullet;
	Bullet(Vector3 pos, Vector3 vel, std::vector<Particle*>& particle);
	bool update(Enemy* enemy);
};

