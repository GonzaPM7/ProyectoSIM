#pragma once
#include "ParticleLink.h"
class ParticleRod :	public ParticleLink
{
public:
	float length;
public:
	ParticleRod();
	virtual unsigned addContact(ParticleContact* contact, unsigned limit);
	void setParticleDistance();
	virtual void update();
};

