#pragma once
#include "ParticleForceGenerator.h"
#include "RigidBody.h"


class WindForce : public ParticleForceGenerator
{
	Vector3 f;
	Particle* hit;
	int frame = 30;
	int signo = 1;
public:
	WindForce(const Vector3& wind);
	virtual void updateForce(Particle* particle, float t);
};

class WindForceRB : public ParticleForceGeneratorRB
{
	Vector3 f;
	Particle* hit;
	int frame = 30;
	int signo = 1;
public:
	WindForceRB(const Vector3& wind);
	virtual void updateForce(RigidBody* particle, float t);
};

