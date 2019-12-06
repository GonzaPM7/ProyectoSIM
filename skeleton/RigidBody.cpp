#include "RigidBody.h"

RigidBody::RigidBody(bool Dynamic ,Vector3 pos_, float radius, PxScene* scene_, PxPhysics* physics_, float time) : pos(pos_), desaparecer(time)
{
	Geosphere = true;
	transform = PxTransform(pos_);
	sphere = PxSphereGeometry(radius);
	PxShape* shape = CreateShape(sphere);

	if (Dynamic) {
		particleDynamic = physics_->createRigidDynamic(transform);
		particleDynamic->attachShape(*shape);
		scene_->addActor(*particleDynamic);
		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		render = new RenderItem(shape, particleDynamic, Vector4(colorx, colory, colorz, 1));
	}

	else {
		particleStatic = physics_->createRigidStatic(transform);
		particleStatic->attachShape(*shape);
		scene_->addActor(*particleStatic);
		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		render = new RenderItem(shape, particleStatic, Vector4(colorx, colory, colorz, 1));
	}
}

RigidBody::RigidBody(bool Dynamic, Vector3 pos_, Vector3 lados, PxScene* scene_, PxPhysics* physics_, float time) :pos(pos_), desaparecer(time)
{
	Geosphere = false;
	transform = PxTransform(pos_);
	box = PxBoxGeometry(lados);
	PxShape* shape = CreateShape(box);

	if (Dynamic){
		particleDynamic = physics_->createRigidDynamic(transform);
		particleDynamic->attachShape(*shape);
		scene_->addActor(*particleDynamic);
		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		render = new RenderItem(shape, particleDynamic, Vector4(colorx, colory, colorz, 1));
	}

	else {
		particleStatic = physics_->createRigidStatic(transform);
		particleStatic->attachShape(*shape);
		scene_->addActor(*particleStatic);
		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		render = new RenderItem(shape, particleStatic, Vector4(colorx, colory, colorz, 1));
	}
}

RigidBody::~RigidBody()
{
	borrado = true;
	render->release();
}

void RigidBody::addForce(Vector3 f)
{
	particleDynamic->addForce(f);
}

PxGeometry RigidBody::getGeo()
{
	if (Geosphere)
		return sphere;
	else
		return box;
}

Vector3 RigidBody::getPosition()
{
	return particleDynamic->getGlobalPose().p;
}

PxReal RigidBody::getMass()
{
	return particleDynamic->getMass();
}
