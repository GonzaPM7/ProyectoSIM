#include "RigidBody.h"

RigidBody::RigidBody(bool Dynamic ,Vector3 pos_, Vector4 color, float radius, PxScene* scene_, PxPhysics* physics_, float time) : pos(pos_), desaparecer(time)
{
	Geosphere = true;
	transform = PxTransform(pos_);
	sphere = PxSphereGeometry(radius);
	PxShape* shape = CreateShape(sphere);

	if (Dynamic) {
		particleDynamic = physics_->createRigidDynamic(transform);
		particleDynamic->attachShape(*shape);
		scene_->addActor(*particleDynamic);
		render = new RenderItem(shape, particleDynamic, color);
	}

	else {
		particleStatic = physics_->createRigidStatic(transform);
		particleStatic->attachShape(*shape);
		scene_->addActor(*particleStatic);
		
		render = new RenderItem(shape, particleStatic, color);
	}
}

RigidBody::RigidBody(bool Dynamic, Vector3 pos_, Vector4 color, Vector3 lados, PxScene* scene_, PxPhysics* physics_, float time) :pos(pos_), desaparecer(time)
{
	Geosphere = false;
	transform = PxTransform(pos_);
	box = PxBoxGeometry(lados);
	PxShape* shape = CreateShape(box);

	if (Dynamic){
		particleDynamic = physics_->createRigidDynamic(transform);
		particleDynamic->attachShape(*shape);
		scene_->addActor(*particleDynamic);
		render = new RenderItem(shape, particleDynamic, color);
	}

	else {
		particleStatic = physics_->createRigidStatic(transform);
		particleStatic->attachShape(*shape);
		scene_->addActor(*particleStatic);
		render = new RenderItem(shape, particleStatic, color);
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

void RigidBody::setVelocity(Vector3 v)
{
	particleDynamic->setLinearVelocity(v, true);
}

void RigidBody::setPosition(Vector3 pos)
{
	particleDynamic->setGlobalPose(PxTransform(pos));
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

Vector3 RigidBody::getPositionStatic()
{
	return particleStatic->getGlobalPose().p;
}

Vector3 RigidBody::getVelocity()
{
	return particleDynamic->getLinearVelocity();
}

PxReal RigidBody::getMass()
{
	return particleDynamic->getMass();
}
