#pragma once
#include "Particulas.h"
#include <vector>
using namespace std;

class ParticleForceRegistry;

struct FireworkRule {
	float size;
	float age;
	int vmax;
	int vmin;

	FireworkRule(int type);
};

struct Explosion
{
	int cantidad;
	FireworkRule tipo;
};

struct Payload {
	int contador;
	int size;

	vector<Explosion> FireParticles;

	Payload(int c, int cantidad);
};

class Firework : public Particle {
public:
	unsigned type;
	Payload payload;
	vector<Particle*>* particulas;
	Firework(PxSphereGeometry geo, Vector3 pos, Vector3 vel, Vector3 ac,
		float age, float damping, Payload payload,Vector4 color, vector<Particle*>* part);


	virtual ~Firework();
};