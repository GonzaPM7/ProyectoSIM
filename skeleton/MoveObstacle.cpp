#include "MoveObstacle.h"

MoveObstacle::MoveObstacle(Vector3 pos1, Vector3 pos2, Vector3 vel_, std::vector<Particle*>& particle, int distan): velocity(vel_)
{
	particula1 = new Particle(Vector4(1, 0.5, 0.5, 1), false, 1, PxBoxGeometry(10, 10, 20), pos1, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);
	particle.push_back(particula1);
	particula2 = new Particle(Vector4(1, 0.5, 0.5, 1), false, 1, PxBoxGeometry(10, 10, 20), pos2, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);
	particle.push_back(particula2);
	contact = new ParticleContact(particula1, particula2);
	barra = new ParticleRod();
	barra->addContact(contact, distan);
}

void MoveObstacle::update()
{
	if (particula2->getPosition().y <= 0)
		subir = +1;
	if (particula1->getPosition().y >= 145)
		subir = -1;
	particula1->setVelocity(Vector3(0, velocity.y * subir, 0));
	barra->update(true);
}

bool MoveObstacle::colission(RigidBody* player)
{
	if (PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxBoxGeometry(10+5, 10+5, 20), PxTransform(particula1->getPosition())))
		return true;
	/*if (PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxBoxGeometry(10+5, 10+5, 20), PxTransform(particula2->getPosition())))
		return true;*/

	return false;
}
