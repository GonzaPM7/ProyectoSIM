#include "ParticleGravity.h"

void ParticleGravity::updateForce(Particle* particle, float t)
{
	if (!particle->hasFiniteMass()) return;
	particle->addForce(g * particle->getMass());
}