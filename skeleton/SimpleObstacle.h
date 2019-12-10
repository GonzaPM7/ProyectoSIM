#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "RigidBody.h"
#include "Player.h"
#include "ObstacleSystem.h"
class SimpleObstacle: public ObstacleSystem
{
private:
	Particle* Obstacle;
	Vector3 lado;
public:
	SimpleObstacle(Vector3 pos, Vector3 lados, PxScene* scene_, PxPhysics* physics_);
	virtual bool colission(RigidBody* player);
	virtual void update() {};
};
