#pragma once
#include "core.hpp"
#include "Particulas.h"
#include "RigidBody.h"
#include "GeneratorRB.h"
#include "Bullet.h"

class Player
{
private:
	std::vector<Particle*>& particle;
	GeneratorRB* generator;
	int points = 0;
	int pointlevel = 0;
	int level = 1;
public: 
	RigidBody* personaje;
	Player(Vector3 pos, PxScene* scene_, PxPhysics* physics_, std::vector<Particle*>& particle);
	void Jump(float forceJump);
	Vector3 getPosition();
	void update(float velocityY);
	void shoot(std::vector<Bullet*>& bullet);
	void dead();
	void increPoints();
	void showPoints();
	void clearPoints();
	void nextLevel();
};

