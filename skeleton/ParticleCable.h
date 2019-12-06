#pragma once
#include "ParticleLink.h"
class ParticleCable :
	public ParticleLink
{
public:
	float maxLength;
public:
	ParticleCable();
	virtual unsigned addContact(ParticleContact* contact, unsigned limit);
	void update(bool parado);
};


