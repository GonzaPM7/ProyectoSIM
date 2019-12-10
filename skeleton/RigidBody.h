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
	RigidBody(bool Dynamic, Vector3 pos_, Vector4 color, float radius, PxScene* scene_, PxPhysics* physics_, float time);
	RigidBody(bool Dynamic, Vector3 pos_, Vector4 color, Vector3 lados, PxScene* scene_, PxPhysics* physics_, float time);
	~RigidBody();
	void addForce(Vector3 f);
	void setVelocity(Vector3 v);
	void setPosition(Vector3 pos);
	PxGeometry getGeo();
	Vector3 getPosition();
	Vector3 getPositionStatic();
	Vector3 getVelocity();
	PxReal getMass();
	float desaparecer;
	float time = 0;
	bool borrado = false;
};