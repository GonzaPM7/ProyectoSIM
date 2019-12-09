#include "Bullet.h"

Bullet::Bullet(Vector3 pos, Vector3 vel, std::vector<Particle*>& particle)
{
	bullet = new Particle(Vector4(1, 1, 1, 1), 5, PxBoxGeometry(3, 1, 1), pos, vel, Vector3(0,0,0), 1);
	particle.push_back(bullet);
}

void Bullet::update(Enemy* enemy)
{
	if (enemy->personaje != nullptr) {
		if (PxGeometryQuery::overlap(PxBoxGeometry(3, 1, 1), PxTransform(bullet->getPosition()), PxSphereGeometry(enemy->personaje->getRadius()), PxTransform(enemy->personaje->getPosition()))) {
			enemy->dead();
		}
	}
}
