#include "ParticleGenerator.h"


ParticleGenerator::ParticleGenerator(int spawnTime_, Vector3 pos_, Vector3 vel_, vector<Particle*>& part_): spawnTimeAct(spawnTime_), pos(pos_), vel(vel_),
part(part_)
{
	spawnTime = spawnTimeAct;
}

void ParticleGenerator::update(Vector3 position)
{
	if (spawnTimeAct <= 0) {

		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;

		Particle* p = new Particle(Vector4(colorx,colory,colorz,1), 1, PxSphereGeometry(2), position, vel, Vector3(0,0,0), 1);

		part.push_back(p);
		spawnTimeAct = spawnTime + 1;
	}
	spawnTimeAct--;
}
