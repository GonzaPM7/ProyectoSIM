#include "ExplosionRG.h"

ExplosionRB::ExplosionRB(const float& wind) : f(wind)
{
}

void ExplosionRB::updateForce(RigidBody* particle, float t)
{
	if (hit != nullptr) {
		if (PxGeometryQuery::overlap(particle->getGeo(), PxTransform(particle->getPosition()), PxSphereGeometry(hit->getRadius()), PxTransform(hit->getPosition()))) {
			Vector3 v(particle->getPosition().x - hit->getPosition().x, particle->getPosition().y - hit->getPosition().y,
				particle->getPosition().z - hit->getPosition().z);
			Vector3 distacia = v.abs();
			Vector3 direccion = v.getNormalized();
			Vector3 fuerza = Vector3(direccion.x / distacia.x, direccion.y / distacia.y, direccion.z / distacia.z) * particle->getMass();
			particle->addForce(f * fuerza);
		}
	}
}

void ExplosionRB::createHit(Particle* particle)
{
	hit = particle;
}