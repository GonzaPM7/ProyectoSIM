#include "MoveObstacle.h"

MoveObstacle::MoveObstacle(Vector3 pos1, Vector3 pos2, Vector3 vel_, std::vector<Particle*>& particle): velocity(vel_)
{
	particula1 = new Particle(Vector4(1, 0.5, 0.5, 1), 1000, PxBoxGeometry(10, 10, 20), pos1, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);
	particle.push_back(particula1);
	particula2 = new Particle(Vector4(1, 0.5, 0.5, 1), 1000, PxBoxGeometry(10, 10, 20), pos2, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);
	particle.push_back(particula2);
	contact = new ParticleContact(particula1, particula2);
	barra = new ParticleRod();
	barra->addContact(contact, 100);
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
