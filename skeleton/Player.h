#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "RigidBody.h"
#include "GeneratorRB.h"

class Player
{
private:
	GeneratorRB* generator;
public: 
	Player(Vector3 pos, PxScene* scene_, PxPhysics* physics_, std::vector<RigidBody*> trail);
	void Jump(float forceJump);
	Vector3 getPosition();
	void update(float velocityY);
	RigidBody* personaje;
};

