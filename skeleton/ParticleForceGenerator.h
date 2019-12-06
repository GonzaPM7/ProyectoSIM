#pragma once

#include "Particulas.h"
#include "RigidBody.h"

class ParticleForceGenerator
{
	public:
		// Overload to provide functionality
		virtual void updateForce(Particle* particle, float t) = 0;
};

class ParticleForceGeneratorRB
{
public:
	// Overload to provide functionality
	virtual void updateForce(RigidBody* particle, float t) = 0;
};

