#pragma once
#include "Particulas.h"
#include "ParticleRod.h"
#include "ParticleContact.h"
class MoveObstacle
{
	Particle* particula1;
	Particle* particula2;
	int subir = -1;
	Vector3 velocity;
	ParticleRod* barra;
	ParticleContact* contact;
public:
	MoveObstacle(Vector3 pos1, Vector3 pos2, Vector3 vel, std::vector<Particle*>& particle);
	void update();
};

