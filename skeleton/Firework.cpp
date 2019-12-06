#include "Firework.h"
#include <random>
#include "ParticleForceRegistry.h"
#include "ParticleGravity.h"

Firework::Firework(ParticleForceRegistry* registro, PxSphereGeometry geo, Vector3 pos, Vector3 vel, Vector3 ac,
	float damping, float a, Payload payload, vector<Particle*>* part)
	: Particle(a, geo, pos, vel, ac, damping),
	particulas(part), payload(payload), registro_(registro) {
}


Firework::~Firework() {
	if (payload.contador > 0) {
		payload.contador--;
		for (int x = 0; x < payload.FireParticles[payload.contador].cantidad; x++) {

			FireworkRule tipo = payload.FireParticles[payload.contador].tipo;

			float vx, vy, vz;

			vx = (float)(rand() % (int)((tipo.vmax - tipo.vmin) * 100) + (int)(tipo.vmin * 100)) / 100.0;
			vy = (float)(rand() % (int)((tipo.vmax - tipo.vmin) * 100) + (int)(tipo.vmin * 100)) / 100.0;
			vz = (float)(rand() % (int)((tipo.vmax - tipo.vmin) * 100) + (int)(tipo.vmin * 100)) / 100.0;

			Firework* fireWork = new Firework(registro_, PxSphereGeometry(tipo.size),
				p, { vx, vy, vz }, a, damping, tipo.age, payload, particulas);
			registro_->add(fireWork, new ParticleGravity(Vector3(0, -0.02, 0)));
			particulas->push_back(fireWork);
		}
	}
}

enum Types { ULTIMO, SEGUNDO, PRIMERO };

FireworkRule::FireworkRule(int type)
{
	if (type == ULTIMO) {
		age = 3;
		vmax = 5;
		vmin = 1;
		size = 1;
	}
	else if (type == SEGUNDO) {
		age = 4;
		vmax = 10;
		vmin = 5;
		size = 2;
	}
	else if (type == PRIMERO) {
		age = 5;
		vmax = 15;
		vmin = 10;
		size = 3;
	}
}

Payload::Payload(int c, int cantidad) {
	contador = c;
	int t = 0;
	for (int x = 0; x < c; x++) {
		FireParticles.push_back({ cantidad, t });
		t++;
	}
}