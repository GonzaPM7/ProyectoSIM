#include "WaterObstacle.h"
#include "ParticleGravity.h"

WaterObstacle::WaterObstacle(Vector3 pos, ParticleForceRegistry*& registro, std::vector<Particle*>& particle)
{
	object = new Particle(Vector4(1, 0, 0, 1), false, 300, PxBoxGeometry(10, 10, 10), pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.4);
	registro->add(object, new ParticleGravity(Vector3(0, -10, 0)));
	water = new Particle(Vector4(0.5, 0.5, 1, 1), false, 300, PxBoxGeometry(80, 1, 20), pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.8);
	buoyancy = new ParticleBuoyancy(5, 0.1, 0);
	particle.push_back(object);
	registro->add(object, buoyancy);
}

void WaterObstacle::update()
{
}

bool WaterObstacle::colission(RigidBody* player)
{
	if (PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxBoxGeometry(10 + 5, 10 + 5, 10), PxTransform(object->getPosition())))
		return true;
	return colision2(player);
}

bool WaterObstacle::colision2(RigidBody* player)
{
	if (PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxBoxGeometry(80 + 5, 1 + 5, 20), PxTransform(water->getPosition())))
		return true;

	return false;
}
