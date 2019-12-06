#pragma once
#include "Particulas.h"

class ParticleContact
{
public:
	// Particles involved in the collision
	Particle* particle[2];
	
	ParticleContact(Particle* p1, Particle* p2);
};

