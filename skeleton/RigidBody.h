#pragma once
#include "core.hpp"


#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particulas.h"
using namespace physx;

class RigidBody
{
	PxRigidDynamic* particleDynamic = nullptr;
	PxRigidStatic* particleStatic = nullptr;
	PxSphereGeometry sphere;
	PxBoxGeometry box;
	Vector3 pos;
	PxTransform transform;
	bool Geosphere;
	RenderItem* render;
public:
	RigidBody(bool Dynamic, Vector3 pos_, float radius, PxScene* scene_, PxPhysics* physics_, float time);
	RigidBody(bool Dynamic, Vector3 pos_, Vector3 lados, PxScene* scene_, PxPhysics* physics_, float time);
	~RigidBody();
	void addForce(Vector3 f);
	PxGeometry getGeo();
	Vector3 getPosition();
	PxReal getMass();
	float desaparecer;
	float time = 0;
	bool borrado = false;
};