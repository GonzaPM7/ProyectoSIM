#pragma once


#include "core.hpp"
#include <complex>
#include "RenderUtils.hpp"
#include "PxPhysicsAPI.h"

using namespace physx;
typedef float PxReal;
class Particle
{
public:
	//Crear la clase renderItem para que sea atributo de esta clase y pasarle el transform, color, etc y luego en el main crearla
	//en los metodos initPhysics o stepPhysics o keyPress una de esos metodos
	Particle(float a,PxSphereGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping);
	Particle(int radius, Vector4 color, float a, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping);
	Particle(Vector4 color, float a,PxSphereGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping);
	Particle(Vector4 color, float a, PxBoxGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping);
	virtual ~Particle();
	// Position in world space
	Vector3 p;
	// Linear velocity in world space
	Vector3 v;
	// Linear acceleration in world space
	Vector3 a;

	float maxFrame;
	float frame;	

	float damping;
	PxReal inverse_mass = 1;
	
	void integrate(float t);

	RenderItem* renderItem;
	PxTransform*  transform;

	// Accumulated force
	Vector3 force;
	// Clears accumulated force
	void clearForce();
	// Add force to apply in next integration only
	void addForce(const Vector3& f);
	
	bool hasFiniteMass();
	PxReal getMass();

	void getVelocity(Vector3* f);
	Vector3 getVelocity();

	void setPosition(Vector3 p_); 
	Vector3 getPosition() const;

	Vector3 getVelo() const;
	void setVelocity(Vector3 v_);

	void setMass(float mass);

	void setAcceleration(Vector3 a);

	void setDamping(float d);

	void dele();

	virtual bool update(float time);

	float age_;

	int getRadius();

	int radius_;
};