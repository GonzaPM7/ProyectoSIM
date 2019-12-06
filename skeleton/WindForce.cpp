#include "WindForce.h"
#include <iostream>

WindForce::WindForce(const Vector3& wind) : f(wind)
{
	hit = new Particle(70, Vector4(1,1,1,0), 5, Vector3(0,200,0), Vector3(), Vector3(), 0.5);
	frame = 1000;
}

void WindForce::updateForce(Particle* particle, float t)
{
	frame--;

	if (particle->getPosition().y >= hit->getPosition().y - hit->getRadius() && particle->getPosition().y <= hit->getPosition().y + hit->getRadius() &&
		particle->getPosition().x >= hit->getPosition().x - hit->getRadius() && particle->getPosition().x <= hit->getPosition().x + hit->getRadius() &&
		particle->getPosition().z >= hit->getPosition().z - hit->getRadius() && particle->getPosition().z <= hit->getPosition().z + hit->getRadius()) {
		particle->addForce(f*signo * particle->getMass());
	}
	if (frame <= 0) {
		signo = -signo;
		frame = 1000;
	}	
}

WindForceRB::WindForceRB(const Vector3& wind) : f(wind)
{
	hit = new Particle(70, Vector4(1, 1, 1, 0), 5, Vector3(0, 200, 0), Vector3(), Vector3(), 0.5);
	frame = 1000;
}

void WindForceRB::updateForce(RigidBody* particle, float t)
{
	frame--;

	if (particle->getPosition().y >= hit->getPosition().y - hit->getRadius() && particle->getPosition().y <= hit->getPosition().y + hit->getRadius() &&
		particle->getPosition().x >= hit->getPosition().x - hit->getRadius() && particle->getPosition().x <= hit->getPosition().x + hit->getRadius() &&
		particle->getPosition().z >= hit->getPosition().z - hit->getRadius() && particle->getPosition().z <= hit->getPosition().z + hit->getRadius()) {
		particle->addForce(f * signo * particle->getMass());
	}
	if (frame <= 0) {
		signo = -signo;
		frame = 1000;
	}
}
