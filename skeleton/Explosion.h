#pragma once
#include "ParticleForceGenerator.h"
#include "RigidBody.h"

class Bomba : public ParticleForceGenerator
{
	float f;
	Particle* hit = nullptr;
public:
	Bomba(const float& wind);
	virtual void updateForce(Particle* particle, float t);
	void createHit(Particle* particle);
};
