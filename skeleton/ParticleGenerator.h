#pragma once
#include "Particulas.h"
#include "ParticleForceRegistry.h"
#include "ParticleGravity.h"
#include "WindForce.h"
#include "Explosion.h"
#include <vector>

using namespace std;

class ParticleGenerator
{
public:
	ParticleGenerator(int spawnTime_, Vector3 pos, Vector3 vel, vector<Particle*>& part);
	void update(Vector3 position);
private:
	int spawnTimeAct;
	int spawnTime;
	vector<Particle*>& part;
	Vector3 pos;
	Vector3 vel;
};

