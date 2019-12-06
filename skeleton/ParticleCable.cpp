#include "ParticleCable.h"

ParticleCable::ParticleCable()
{
}

unsigned ParticleCable::addContact(ParticleContact* contact, unsigned limit)
{
	particle[0] = contact->particle[0];
	particle[1] = contact->particle[1];
	// Find the length of the cable.
	float length = currentLength();
	maxLength = limit;
	// Check if we’re overextended.
	if (length < maxLength) {
		return 0;
	}
	return 1;
}

void ParticleCable::update()
{
	float length = currentLength();
	if (length >= maxLength)
	{
		particle[0]->setVelocity(getLinkVelocity());
		particle[1]->setVelocity(getLinkVelocity());
	}
}


