#include "Player.h"

Player::Player(Vector3 pos, PxScene* scene_, PxPhysics* physics_)
{
	scene_->setGravity(Vector3(0.0f, -50.0f, 0.0f));
	personaje = new RigidBody(true, pos, 10, scene_, physics_, 0);
}

void Player::Jump(float forceJump)
{
	personaje->addForce(Vector3(0, forceJump, 0));
}

Vector3 Player::getPosition()
{
	return personaje->getPosition();
}

void Player::update(float velocityY)
{	
	personaje->addForce(Vector3(velocityY, 0, 0));
}