#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(ParticleForceRegistry* registro, float gravedad, Vector3 pos, Vector3 vel, Vector4 color, vector<Particle*>& part, Bomba* bomb_): registro_(registro), gravedad_(gravedad), pos_(pos),
vel_(vel),color_(color), part_(part), bomb(bomb_) {
	//viento = new WindForce(Vector3(0, 0, 10));
}

void ParticleGenerator::update()
{
	spawnTime--;
	if (spawn>=spawnTime) {
		spawnTime = 30;
		Particle* p = new Particle(color_,6, PxSphereGeometry(10), pos_, Vector3(0,0,0), Vector3(0, 0, 0), 0.2);
		p->addForce(vel_);
		registro_->add(p, new ParticleGravity(Vector3(0, gravedad_, 0)));
		//registro_->add(p, viento);
		registro_->add(p, bomb);
		part_.push_back(p);
	}
}
