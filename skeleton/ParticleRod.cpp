#include "ParticleRod.h"


ParticleRod::ParticleRod(): ParticleLink()
{
}

unsigned ParticleRod::addContact(ParticleContact* contact, unsigned limit)
{
	particle[0] = contact->particle[0];
	particle[1] = contact->particle[1];
	// Find the length of the rod.
	float l = currentLength();
	length = limit;
	// Check if we’re overextended or overcompressed
	if (l == length) {
		return 0;
	}
	setParticleDistance();
	return 1;
}

void ParticleRod::setParticleDistance()
{
	float relativePosX = particle[0]->getPosition().x - particle[1]->getPosition().x;
	float relativePosY = particle[0]->getPosition().y - particle[1]->getPosition().y;
	float relativePosZ = particle[0]->getPosition().z - particle[1]->getPosition().z;
	float relativePos = max(relativePosX, relativePosY);
	relativePos = max(relativePos, relativePosZ);
	float additionalDistance = (length - relativePos) / 2;
	if (relativePos == relativePosX)
	{
		particle[0]->setPosition(Vector3(particle[0]->getPosition().x + additionalDistance, particle[0]->getPosition().y, particle[0]->getPosition().z));
		particle[1]->setPosition(Vector3(particle[1]->getPosition().x - additionalDistance, particle[1]->getPosition().y, particle[1]->getPosition().z));
	}
	else if (relativePos == relativePosY) {
		particle[0]->setPosition(Vector3(particle[0]->getPosition().x, particle[0]->getPosition().y + additionalDistance, particle[0]->getPosition().z));
		particle[1]->setPosition(Vector3(particle[1]->getPosition().x, particle[1]->getPosition().y - additionalDistance, particle[1]->getPosition().z));
	}
	else {
		particle[0]->setPosition(Vector3(particle[0]->getPosition().x, particle[0]->getPosition().y, particle[0]->getPosition().z + additionalDistance));
		particle[1]->setPosition(Vector3(particle[1]->getPosition().x, particle[1]->getPosition().y, particle[1]->getPosition().z - additionalDistance));
	}
}

void ParticleRod::update()
{
	Vector3 v = getLinkVelocity();
	particle[0]->setVelocity(v);
	particle[1]->setVelocity(v);
}