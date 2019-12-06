#pragma once
#include "ParticleLink.h"
class ParticleRod : public ParticleLink
{
public:
	float maxlength;
public:
	ParticleRod();
	virtual unsigned addContact(ParticleContact* contact, unsigned limit);
	void update(bool parado);
};

