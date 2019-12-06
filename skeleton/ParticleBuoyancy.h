#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy : public ParticleForceGenerator
{
	float maxDepth;
	float volume;
	// Considering a water plane parallel to XZ
	float waterHeight;
	// Density of the liquid the object is submerged in
	float liquidDensity;
public:
	ParticleBuoyancy(float _maxDepth, float _volume, float
		_waterHeight,
		float _liquidDensity = 1000.0f);
	virtual void updateForce(Particle* particle, float t);
	void increVolum();
	void dicreVolum();
};

