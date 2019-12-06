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
	ParticleGenerator(ParticleForceRegistry* registro, float gravedad, Vector3 pos, Vector3 vel, Vector4 color, vector<Particle*>& part, Bomba* bomb_);
	void update();
	ParticleForceRegistry* registro_;
private:
	int spawnTime = 30;
	int spawn = 0;
	vector<Particle*>& part_;
	float gravedad_;
	Vector3 pos_;
	Vector4 color_;
	Vector3 vel_;
	WindForce* viento;
	Bomba* bomb;
};

