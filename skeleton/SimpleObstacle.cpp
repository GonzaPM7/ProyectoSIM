#include "SimpleObstacle.h"

SimpleObstacle::SimpleObstacle(Vector3 pos, Vector3 lados, PxScene* scene_, PxPhysics* physics_)
{
	Obstacle = new RigidBody(false, pos, Vector4(1, 0, 0, 1), lados, scene_, physics_, 0);
}

bool SimpleObstacle::colission(RigidBody* player)
{
	return PxGeometryQuery::overlap(player->getGeo(), PxTransform(player->getPosition()), Obstacle->getGeo(), PxTransform(Obstacle->getPositionStatic()));
}
