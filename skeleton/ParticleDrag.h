#pragma once
#include "ParticleForceGenerator.h"

class ParticleDrag : public ParticleForceGenerator
{
	// Coefficient for velocity
	float k1;
	// Coefficient for squared velocity
	float k2;
public:
	ParticleDrag(float _k1, float _k2) : k1(_k1), k2(_k2) {}
	virtual void updateForce(Particle* particle, float t);
};

