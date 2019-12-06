#include "GeneratorRB.h"

GeneratorRB::GeneratorRB(Vector3 pos_, Vector3 force, std::vector<RigidBody*>& rigb_, ParticleForceRegistryRB* registro_, int maxRB_, PxScene* scene_, PxPhysics* physics_, int spawnTime_, ParticleForceGeneratorRB* wind_, ParticleForceGeneratorRB* bomb_) : maxRB(maxRB_),scene(scene_),
physics(physics_), spawnTime(spawnTime_), wind(wind_), registro(registro_), rigb(rigb_), bomb(bomb_), f(force), pos(pos_)
{
	spawnTimeAct = spawnTime;
}

void GeneratorRB::update()
{	
	if (maxRB > generado && spawnTimeAct <= 0) {
		generado++;
		
		RigidBody* p = new RigidBody(true, pos, 5, scene, physics, 50);

		p->addForce(f);
		registro->add(p, wind);
		registro->add(p, bomb);
		rigb.push_back(p);
		spawnTimeAct = spawnTime + 1;
	}
	else if (maxRB > generado && spawnTimeAct > 0)
		spawnTimeAct--;
}
