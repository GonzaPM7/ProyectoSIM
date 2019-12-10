#include "Particulas.h"

Particle::Particle(int radius, Vector4 color, float a, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping_) :age_(a), p(position), v(velocity), a(acceleration), damping(damping_),radius_(radius) {
	//PxBoxGeometry geo = PxBoxGeometry(1, 1, 1);
	PxShape* shape = CreateShape(PxSphereGeometry(radius));
	transform = new PxTransform(position);
	renderItem = new RenderItem(shape, transform, color); // El Vector4 es básicamente color rojo.
	shape->release();
	clearForce();
	maxFrame = 1000;
	frame = 0;
}

Particle::Particle(float a,PxSphereGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping_):age_(a),p(position), v(velocity),a(acceleration),damping(damping_){
	//PxBoxGeometry geo = PxBoxGeometry(1, 1, 1);
	PxShape* shape = CreateShape(geo);
	transform = new PxTransform(position);
	renderItem = new RenderItem(shape, transform, Vector4(1, 0, 0, 1)); // El Vector4 es básicamente color rojo.
	shape->release();
	clearForce();
	maxFrame = 1000;
	frame = 0;
}

Particle::Particle(Vector4 color, float a, PxSphereGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping_) :
	age_(a), p(position), v(velocity), a(acceleration), damping(damping_)
{
	PxShape* shape = CreateShape(geo);
	transform = new PxTransform(position);
	renderItem = new RenderItem(shape, transform, color); // El Vector4 es básicamente color rojo.
	shape->release();
	clearForce();
	maxFrame = 1000;
	frame = 0;
}

Particle::Particle(Vector4 color, bool dead_, float a, PxBoxGeometry geo, Vector3 position, Vector3 velocity, Vector3 acceleration, float damping):
	age_(a), p(position), v(velocity), a(acceleration), damping(damping), dead(dead_)
{
	PxShape* shape = CreateShape(geo);
	transform = new PxTransform(position);
	renderItem = new RenderItem(shape, transform, color); // El Vector4 es básicamente color rojo.
	shape->release();
	clearForce();
	maxFrame = 1000;
	frame = 0;
}

Particle::~Particle()
{
	renderItem->release();	
}

void Particle::integrate(float t)
{
	frame++;
	// Trivial case, infinite mass --> do nothing
	if (inverse_mass <= 0.0f) return;
	// Update position
	p += v * t;
	Vector3 totalAcceleration = Vector3(0);
	totalAcceleration += force * inverse_mass;
	// Update linear velocity
	v += a * t;
	v += totalAcceleration * t;
	// Impose drag (damping)
	v *= powf(damping, t);

	*transform = PxTransform(p);
	clearForce();

}

void Particle::clearForce()
{
	force.x = 0;
	force.y = 0;
	force.z = 0;
}
void Particle::addForce(const Vector3& f)
{
	force += f;
}

bool Particle::hasFiniteMass()
{
	return (inverse_mass >= 0.0f);
}

PxReal Particle::getMass()
{
	return (1 / inverse_mass);
}

void Particle::getVelocity(Vector3* f)
{
	f = &v;
}

Vector3 Particle::getVelocity()
{
	return v;
}

void Particle::setPosition(Vector3 p_)
{
	transform = new PxTransform(p_);
}

Vector3 Particle::getPosition() const
{
	return p;
}

void Particle::setVelocity(Vector3 v_)
{
	v = v_;
}

void Particle::setMass(float m)
{
	inverse_mass = 1.0 / m;
}

void Particle::setAcceleration(Vector3 a_)
{
	a = a_;
}

void Particle::setDamping(float d)
{
	damping = d;
}

void Particle::dele()
{
	renderItem->release();
}


bool Particle::update(float time)
{
	integrate(time);
	if (dead) {
		age_ -= time;
		return age_ < 0.0;
	}
	return false;
}

int Particle::getRadius()
{
	return radius_;
}

