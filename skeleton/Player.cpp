#include "Player.h"
#include <iostream>
Player::Player(Vector3 pos, PxScene* scene_, PxPhysics* physics_, std::vector<Particle*>& particle_):particle(particle_)
{
	scene_->setGravity(Vector3(0.0f, -100.0f, 0.0f));
	personaje = new RigidBody(true, pos, Vector4(0, 0, 1, 1), 10, scene_, physics_, 0);
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
	if (personaje->getVelocity().x < 50) {
		personaje->addForce(Vector3(velocityY, 0, 0));
	}
	GetCamera()->setTransform(getPosition().x + 100, 75, getPosition().z + 200); //Segundo Nivel -335
}

void Player::shoot(std::vector<Bullet*>& bullet)
{
	bullet.push_back(new Bullet(personaje->getPosition(), Vector3(100, 0, 0), particle));
}

void Player::dead()
{
	if (level == 1){
		personaje->setPosition(Vector3(0, 50, 0));
		GetCamera()->setTransform(0, 75, 0);
	}
	else if (level == 2) {
		personaje->setPosition(Vector3(2000, 50, 0));
		GetCamera()->setTransform(2000, 75, 0);
	}
	personaje->setVelocity(Vector3(0, 0, 0));
	clearPoints();
	showPoints();
}

void Player::increPoints()
{
	points++;
	showPoints();
}

void Player::showPoints()
{
	std::cout << "POINTS: " << points << "\n";
}

void Player::clearPoints()
{
	points = pointlevel;
}

void Player::nextLevel()
{
	level = 2;
	pointlevel = points;
}
