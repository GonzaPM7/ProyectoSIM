#include "ParticleLink.h"

float ParticleLink::currentLength() const
{
	Vector3 relativePos = particle[0]->getPosition() - particle[1]->getPosition();
	return relativePos.magnitude();
}

ParticleLink::ParticleLink()
{
}

Vector3 ParticleLink::getLinkVelocity()
{
	Vector3 v1 = particle[0]->getVelocity();
	Vector3 v2 = particle[1]->getVelocity();

	Vector3 v = Vector3(max(abs(v1.x), abs(v2.x)), max(abs(v1.y), abs(v2.y)), max(abs(v1.z), abs(v2.z)));

	if (v.x == abs(v1.x))
		v.x = v1.x;
	else
		v.x = v2.x;
	if (v.y == abs(v1.y))
		v.y = v1.y;
	else
		v.y = v2.y;
	if (v.z == abs(v1.z))
		v.z = v1.z;
	else
		v.z = v2.z;

	return v;
}
