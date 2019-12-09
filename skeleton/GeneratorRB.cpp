#include "GeneratorRB.h"

GeneratorRB::GeneratorRB(Vector3 pos_, Vector3 force, std::vector<RigidBody*>& rigb_, int maxRB_, PxScene* scene_, PxPhysics* physics_, int spawnTime_) : maxRB(maxRB_),scene(scene_),
physics(physics_), spawnTime(spawnTime_), f(force), pos(pos_), rigb(rigb_)
{
	spawnTimeAct = spawnTime;
}

void GeneratorRB::update(Vector3 pos_)
{	
	if (spawnTimeAct <= 0) {
		generado++;

		float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
		float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;

		RigidBody* p = new RigidBody(true, pos_,Vector4(colorx, colory, colorz,1), 2, scene, physics, 7);

		p->addForce(f);
		rigb.push_back(p);
		spawnTimeAct = spawnTime + 1;
	}	
	spawnTimeAct--;
}
