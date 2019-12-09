#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "RigidBody.h"
#include "Player.h"
class SimpleObstacle
{
private:
	RigidBody* Obstacle;
public:
	SimpleObstacle(Vector3 pos, Vector3 lados, PxScene* scene_, PxPhysics* physics_);
	bool colission(RigidBody* player);
};
