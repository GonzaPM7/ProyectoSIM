#pragma once
#include "Particulas.h"
#include "ParticleRod.h"
#include "ParticleContact.h"
#include "RigidBody.h"
#include "ObstacleSystem.h"
#include "ParticleForceRegistry.h"
#include "ParticleBuoyancy.h"

class WaterObstacle: public ObstacleSystem
{
private:
	Particle* water;
	Particle* object;
	ParticleBuoyancy* buoyancy;
public:
	WaterObstacle(Vector3 pos, ParticleForceRegistry*& registro, std::vector<Particle*>& particle);
	virtual void update();
	virtual bool colission(RigidBody* player);
	bool colision2(RigidBody* player);
};

