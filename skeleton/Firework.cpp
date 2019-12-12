#include "Firework.h"
#include <random>
#include "ParticleForceRegistry.h"
#include "ParticleGravity.h"

Firework::Firework(PxSphereGeometry geo, Vector3 pos, Vector3 vel, Vector3 ac,
	float damping, float a, Payload payload, Vector4 color, vector<Particle*>* part)
	: Particle(color, a, geo, pos, vel, ac, damping),
	particulas(part), payload(payload) {
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

			float colorx = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
			float colory = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;
			float colorz = (float)(rand() % (int)((1 - 0) * 100) + (int)(0 * 100)) / 100.0;

			Firework* fireWork = new Firework(PxSphereGeometry(tipo.size),
				p, { vx, vy, vz }, Vector3(0,0,0), damping, tipo.age, payload, Vector4(colorx,colory,colorz, 1), particulas);
			particulas->push_back(fireWork);
		}
	}
}

enum Types { ULTIMO, SEGUNDO, PRIMERO };

FireworkRule::FireworkRule(int type)
{
	if (type == ULTIMO) {
		age = 1;
		vmax = 5;
		vmin = 0;
		size = 1;
	}
	else if (type == SEGUNDO) {
		age = 1;
		vmax = 5;
		vmin = 0;
		size = 2;
	}
	else if (type == PRIMERO) {
		age = 1;
		vmax = 5;
		vmin = 0;
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