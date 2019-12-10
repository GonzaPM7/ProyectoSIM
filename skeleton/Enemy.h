#pragma once
#include "Particulas.h"
#include "Firework.h"
#include "RigidBody.h"
#include "ObstacleSystem.h"
class Enemy
{
private:
	Vector3 posIni;
	Vector3 vel;
	int subir = 1;
	std::vector<Particle*>& particle;
public:
	Particle* personaje;
	Enemy(Vector3 pos, Vector3 vel, std::vector<Particle*>& particle);
	void update();
	void dead();
	bool colission(RigidBody* player);
};

