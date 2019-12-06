#pragma once
#include "Particulas.h"
#include "ParticleContact.h"
class ParticleLink
{
public:
	//Holds the pair of particles that are connected by this link.
	Particle* particle[2];
protected:
	float currentLength() const;
public:
	ParticleLink();
	virtual unsigned addContact(ParticleContact* contact, unsigned limit) = 0;
	Vector3 getLinkVelocity();
	virtual void update() = 0;
};

