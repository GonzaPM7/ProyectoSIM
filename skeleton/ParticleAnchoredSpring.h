#pragma once
#include "ParticleForceGenerator.h"

class ParticleAnchoredSpring : public ParticleForceGenerator
{
	// Position of the other end of the spring
	Vector3 anchor;
	// Elasticity constant
	float k;
	float restLength;
public:
	ParticleAnchoredSpring(Vector3 _anchor, float _k, float _restLength);
	virtual void updateForce(Particle* particle, float t);
};

