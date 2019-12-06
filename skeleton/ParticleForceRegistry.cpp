#include "ParticleForceRegistry.h"



void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* fg)
{
	registrations.push_back({ particle,fg });
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* fg)
{
	for (auto it = registrations.begin(); it->particle != particle && it->fg != fg; ++it) {
		registrations.erase(it);
	}
}

void ParticleForceRegistry::clear()
{
	registrations.clear();
}

void ParticleForceRegistry::updateForces(float t)
{
	for (auto it = registrations.begin(); it != registrations.end(); ++it)
	{
		it->fg->updateForce(it->particle, t);
	}
}

//RIGIDBODY

void ParticleForceRegistryRB::add(RigidBody* particle, ParticleForceGeneratorRB* fg)
{
	registrations.push_back({ particle,fg });
}

void ParticleForceRegistryRB::remove(RigidBody* particle, ParticleForceGeneratorRB* fg)
{
	for (auto it = registrations.begin(); it->particle != particle && it->fg != fg; ++it) {
		registrations.erase(it);
	}
}

void ParticleForceRegistryRB::clear()
{
	registrations.clear();
}

void ParticleForceRegistryRB::updateForces(float t)
{
	for (auto it = registrations.begin(); it != registrations.end(); ++it)
	{
		if(!it->particle->borrado)
			it->fg->updateForce(it->particle, t);
	}
}
