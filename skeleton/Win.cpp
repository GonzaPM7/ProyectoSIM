#include "Win.h"
#include <iostream>
#include "Firework.h"

Win::Win(Vector3 pos, Vector3 lados_, bool win_):lados(lados_), win(win_)
{
	hit = new Particle(Vector4(1, 1, 1, 0), false, 1, PxBoxGeometry(lados), pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9);
}

void Win::colission(Player*& player)
{
	if (PxGeometryQuery::overlap(player->personaje->getGeo(), PxTransform(player->personaje->getPosition()), PxBoxGeometry(lados.x + 5, lados.y + 10 + 5, lados.z), PxTransform(hit->getPosition()))) {
		if (win) {
			std::cout << "    VICTORY ROYALE   :D  ";
			player->victory = true;
		}
		else {
			player->nextLevel();
		}
	}
}
