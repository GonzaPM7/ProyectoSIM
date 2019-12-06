#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3 _anchor, float _k, float _restLength)
{
	anchor = _anchor;
	k = _k;
	restLength = _restLength;
}

void ParticleAnchoredSpring::updateForce(Particle* particle, float t)
{
	Vector3 f = particle->getPosition();
	f -= anchor;
	// Length
	float length = f.normalize();
	// Resulting force
	f *= -((length - restLength) * k);
	particle->addForce(f);
}
