#include "SimpleObstacle.h"

SimpleObstacle::SimpleObstacle(Vector3 pos, Vector3 lados, PxScene* scene_, PxPhysics* physics_): lado(lados)
{
	Obstacle = new Particle(Vector4(1, 0, 0, 1), false, 1, PxBoxGeometry(lado), pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);

}

bool SimpleObstacle::colission(RigidBody* player)
{
	return PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), PxBoxGeometry(Vector3(lado.x + 5, lado.y + 5, lado.z)), PxTransform(Obstacle->getPosition()));
}
