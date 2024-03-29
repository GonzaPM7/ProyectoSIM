#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particulas.h"
#include "RigidBody.h"
#include "ParticleForceRegistry.h"
#include "ExplosionRG.h"
#include "WindForce.h"

class GeneratorRB
{
private:
	int maxRB;
	int generado = 0;
	PxScene* scene;
	PxPhysics* physics;
	int spawnTime;
	int spawnTimeAct = 0;
	std::vector<RigidBody*>& rigb;
	Vector3 f;
	Vector3 pos;
public:
	GeneratorRB(Vector3 pos, Vector3 force, std::vector<RigidBody*>& rigb_,int maxRB_, PxScene* scene, PxPhysics* physics, int spawnTime_);
	void update(Vector3 pos);
};

