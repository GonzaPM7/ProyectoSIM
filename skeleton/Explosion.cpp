#include "Explosion.h"

Bomba::Bomba(const float& wind) : f(wind)
{
}

void Bomba::updateForce(Particle* particle, float t)
{	
	if (hit != nullptr) {
		if (particle->getPosition().y >= hit->getPosition().y - hit->getRadius() && particle->getPosition().y <= hit->getPosition().y + hit->getRadius() &&
			particle->getPosition().x >= hit->getPosition().x - hit->getRadius() && particle->getPosition().x <= hit->getPosition().x + hit->getRadius() &&
			particle->getPosition().z >= hit->getPosition().z - hit->getRadius() && particle->getPosition().z <= hit->getPosition().z + hit->getRadius()) {
			Vector3 v(particle->getPosition().x - hit->getPosition().x, particle->getPosition().y - hit->getPosition().y,
				particle->getPosition().z - hit->getPosition().z);
			Vector3 distacia = v.abs();
			Vector3 direccion = v.getNormalized();
			Vector3 fuerza = Vector3(direccion.x / distacia.x, direccion.y / distacia.y, direccion.z / distacia.z) * particle->getMass();
			particle->addForce(f * fuerza);
		}
	}
}

void Bomba::createHit(Particle* particle)
{
	hit = particle;
}
