#pragma once

#include "ParticleForceGenerator.h"

class ParticleForceRegistry
{
protected:
	// Storage for generator-particle entry
	struct ParticleForceRegistration
	{
		Particle* particle;
		ParticleForceGenerator* fg;
	};
	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;
public:
	// Associate generator with a particle
	void add(Particle* particle, ParticleForceGenerator* fg);
	// Remove association
	void remove(Particle* particle, ParticleForceGenerator* fg);
	// Removes all associations. Particle and Generators won't be deleted
	void clear();
	// Update all the generators in the registry
	void updateForces(float t);
};

class ParticleForceRegistryRB
{
protected:
	// Storage for generator-particle entry
	struct ParticleForceRegistration
	{
		RigidBody* particle;
		ParticleForceGeneratorRB* fg;
	};
	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;
public:
	// Associate generator with a particle
	void add(RigidBody* particle, ParticleForceGeneratorRB* fg);
	// Remove association
	void remove(RigidBody* particle, ParticleForceGeneratorRB* fg);
	// Removes all associations. Particle and Generators won't be deleted
	void clear();
	// Update all the generators in the registry
	void updateForces(float t);
};

