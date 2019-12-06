#pragma once
#include "ParticleForceGenerator.h"

class ParticleSpring : public ParticleForceGenerator
{
	// The other particle the spring is attached to
	Particle* other;
	// Elasticity constant
	float k;
	float restLength;
public:
	ParticleSpring(Particle* _other, float _k, float _restLength);
	virtual void updateForce(Particle* particle, float t);
};

