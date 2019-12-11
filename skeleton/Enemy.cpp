#include "Enemy.h"

Enemy::Enemy(Vector3 pos, Vector3 vel_, std::vector<Particle*>& particle_): posIni(pos), vel(vel_), particle(particle_)
{
	personaje = new Particle(5, Vector4(0, 0, 0, 0), 1000, posIni, vel, Vector3(0, 0, 0), 1);
	particle.push_back(personaje);
}

void Enemy::update()
{
	if (personaje->getPosition().y <= posIni.y - 50)
		subir = +1;
	if (personaje->getPosition().y >= posIni.y + 50)
		subir = -1;
	personaje->setVelocity(Vector3(0, vel.y * subir, 0));
}

void Enemy::dead()
{	
	Payload payload = Payload(3, 5);
	particle.push_back(new Firework(PxSphereGeometry(3), personaje->getPosition(), Vector3(0, 0, 0), Vector3(0, 0, 0), 1, 0.5, payload, Vector4(1,0,0,1), &particle));
	personaje->~Particle();
	personaje = nullptr;
}

bool Enemy::colission(RigidBody* player)
{
	return PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxSphereGeometry(10), PxTransform(personaje->getPosition()));
}
 