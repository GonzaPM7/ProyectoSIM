#pragma once

#include "ParticleForceGenerator.h"

class ParticleGravity : public ParticleForceGenerator
{
	// Acceleration for gravity
	Vector3 g;
public:
	ParticleGravity(const Vector3& gravity) : g(gravity) {}
	virtual void updateForce(Particle* particle, float t);
};
