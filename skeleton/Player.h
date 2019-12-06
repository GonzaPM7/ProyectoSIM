#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "RigidBody.h"

class Player
{
private:
	RigidBody* personaje;
public: 
	Player(Vector3 pos, PxScene* scene_, PxPhysics* physics_);
	void Jump(float forceJump);
	Vector3 getPosition();
	void update(float velocityY);
};

