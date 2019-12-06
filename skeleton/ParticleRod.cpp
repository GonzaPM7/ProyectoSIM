#include "ParticleRod.h"


ParticleRod::ParticleRod() : ParticleLink()
{
}

unsigned ParticleRod::addContact(ParticleContact* contact, unsigned limit)
{
	particle[0] = contact->particle[0];
	particle[1] = contact->particle[1];
	// Find the length of the rod.
	float l = currentLength();
	maxlength = limit;
	// Check if we’re overextended or overcompressed
	if (l == maxlength) {
		return 0;
	}

	return 1;
}


void ParticleRod::update(bool parado)
{
	if (currentLength() > maxlength) {
		if (parado) {
			PxVec3 direction = particle[0]->getPosition() - particle[1]->getPosition();
			direction = direction.getNormalized();
			particle[1]->setVelocity(particle[0]->getVelocity().magnitude() * direction);
		}
		else {
			PxVec3 direction = particle[0]->getPosition() - particle[1]->getPosition();
			direction = direction.getNormalized();
			particle[0]->setVelocity(particle[1]->getVelocity().magnitude() * direction);
		}
	}
	else if (currentLength() < maxlength) {
		if (parado) {
			PxVec3 direction = particle[1]->getPosition() - particle[0]->getPosition();
			direction = direction.getNormalized();
			particle[1]->setVelocity(particle[0]->getVelocity().magnitude() * direction);
		}
		else {
			PxVec3 direction = particle[1]->getPosition() - particle[0]->getPosition();
			direction = direction.getNormalized();
			particle[0]->setVelocity(particle[1]->getVelocity().magnitude() * direction);
		}
	}
}