#pragma once
#include "ParticleForceGenerator.h"
#include "RigidBody.h"

class ExplosionRB : public ParticleForceGeneratorRB
{
	float f;
	Particle* hit = nullptr;
public:
	ExplosionRB(const float& wind);
	virtual void updateForce(RigidBody* RB, float t);
	void createHit(Particle* particle);
};

