#include "ParticleCable.h"
#include <iostream>
using namespace std;
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

void ParticleCable::update(bool parado)
{
	if (currentLength() >= maxLength)
	{
		if (parado) {
			PxVec3 direccion = (particle[0]->getPosition() - particle[1]->getPosition()).getNormalized();
			particle[1]->setVelocity(particle[0]->getVelocity().magnitude() * direccion);

		}
		else {
			PxVec3 direccion = (particle[1]->getPosition() - particle[0]->getPosition()).getNormalized();
			particle[0]->setVelocity(particle[1]->getVelocity().magnitude() * direccion);
		}
	}
}


