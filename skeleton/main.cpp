#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <iostream>
#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"
#include "Particulas.h"
#include "Render/Camera.h"

#include "Firework.h"
#include "ParticleGenerator.h"
#include "WindForce.h"
#include "Explosion.h"
#include "ParticleAnchoredSpring.h"
#include "ParticleSpring.h"
#include "ParticleBuoyancy.h"
#include "ParticleContact.h"
#include "ParticleRod.h"
#include "ParticleCable.h"
#include "GeneratorRB.h"
#include "RigidBody.h"
#include "ExplosionRG.h"
#include "Player.h"
#include "SimpleObstacle.h"
#include "MoveObstacle.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObstacleSystem.h"
#include "WaterObstacle.h"
#include "Win.h"

using namespace physx;
using namespace std;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation*			gFoundation = NULL;
PxPhysics*				gPhysics	= NULL;


PxMaterial*				gMaterial	= NULL;

PxPvd*                  gPvd        = NULL;

PxDefaultCpuDispatcher*	gDispatcher = NULL;
PxScene*				gScene      = NULL;
ContactReportCallback gContactReportCallback;
ParticleGenerator* pg;
ParticleGenerator* pg2;
std::vector<Particle*> particle;
std::vector<Firework*> fireworks;
float spawnTime = 0;
float spawn = 30;
int posX = 0;
WindForce* wind;
Bomba* bomb;
ParticleAnchoredSpring* anchored;
ParticleSpring* spring;
ParticleSpring* spring2;
ParticleBuoyancy* buoyancy;

ParticleContact* contact;
ParticleRod* barra;
ParticleCable* cable;
Particle* p;
Particle* p2;
bool activeV = false;
GeneratorRB* generador2;
ParticleForceRegistryRB* registroRB;
ExplosionRB* explosion;
WindForceRB* windRB;

//Proyecto
Player* player;
RigidBody* suelo;
std::vector<RigidBody*> rigidBody;
ParticleGenerator* generador;
std::vector<Bullet*> bullets;
std::vector<ObstacleSystem*> obstacles;
std::vector<Enemy*> enemys;
std::vector<Win*> win;
ParticleForceRegistry* registro;
Payload payload = Payload(3, 5);

//Metodos del Juego

void Level1() {
	obstacles.push_back(new SimpleObstacle(Vector3(100, -25, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(100, 175, 0), Vector3(20, 50, 20), gScene, gPhysics));
	enemys.push_back(new Enemy(Vector3(200, 50, 0), Vector3(0, 5, 0), particle));
	obstacles.push_back(new WaterObstacle(Vector3(200, -10, 10), registro, particle));
	obstacles.push_back(new MoveObstacle(Vector3(300, 100, 10), Vector3(300, 0, 10), Vector3(0, 30, 0), particle, 100));
	obstacles.push_back(new SimpleObstacle(Vector3(400, 0, 0), Vector3(20, 70, 20), gScene, gPhysics));
	obstacles.push_back(new MoveObstacle(Vector3(500, 100, 10), Vector3(500, 50, 10), Vector3(0, 30, 0), particle, 50));
	obstacles.push_back(new WaterObstacle(Vector3(500, 150, 10), registro, particle));
	enemys.push_back(new Enemy(Vector3(600, 25, 0), Vector3(0, 10, 0), particle));
	obstacles.push_back(new WaterObstacle(Vector3(600, -10, 10), registro, particle));
	obstacles.push_back(new SimpleObstacle(Vector3(700, 0, 0), Vector3(20, 70, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(700, 150, 0), Vector3(20, 20, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(800, -25, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(800, 150, 0), Vector3(20, 70, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(900, -10, 10), registro, particle));
	enemys.push_back(new Enemy(Vector3(900, 50, 0), Vector3(0, 5, 0), particle));
	enemys.push_back(new Enemy(Vector3(950, 75, 0), Vector3(0, 5, 0), particle));
	obstacles.push_back(new MoveObstacle(Vector3(1000, 100, 10), Vector3(1000, 0, 10), Vector3(0, 10, 0), particle, 100));
	obstacles.push_back(new SimpleObstacle(Vector3(1100, 155, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(1100, 0, 0), Vector3(20, 70, 20), gScene, gPhysics));
	obstacles.push_back(new MoveObstacle(Vector3(1200, 100, 10), Vector3(1200, 0, 10), Vector3(0, 30, 0), particle, 100));
	obstacles.push_back(new SimpleObstacle(Vector3(1300, 0, 0), Vector3(20, 100, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(1400, -10, 10), registro, particle));
	obstacles.push_back(new SimpleObstacle(Vector3(1400, 105, 0), Vector3(20, 50, 20), gScene, gPhysics));
	enemys.push_back(new Enemy(Vector3(1500, 50, 0), Vector3(0, 15, 0), particle));
	enemys.push_back(new Enemy(Vector3(1500, 50, 0), Vector3(0, 5, 0), particle));
	obstacles.push_back(new MoveObstacle(Vector3(1600, 100, 10), Vector3(1500, 50, 10), Vector3(0, 50, 0), particle, 50));
	obstacles.push_back(new WaterObstacle(Vector3(1600, 150, 10), registro, particle));
	obstacles.push_back(new SimpleObstacle(Vector3(1700, 115, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(1700, 0, 0), Vector3(20, 30, 20), gScene, gPhysics));
	enemys.push_back(new Enemy(Vector3(1800, 50, 0), Vector3(0, 15, 0), particle));
	enemys.push_back(new Enemy(Vector3(1800, 50, 0), Vector3(0, 5, 0), particle));
	enemys.push_back(new Enemy(Vector3(1800, 50, 0), Vector3(0, 25, 0), particle));
	obstacles.push_back(new SimpleObstacle(Vector3(1900, 155, 0), Vector3(20, 40, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(1900, 30, 0), Vector3(20, 40, 20), gScene, gPhysics));
	win.push_back(new Win(Vector3(1950, 75, 0), Vector3(10, 155, 20), false));
}
void Level2() {
	obstacles.push_back(new SimpleObstacle(Vector3(2100, 0, 0), Vector3(20, 20, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(2100, 120, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(2200, 100, 0), Vector3(20, 70, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(2200, -10, 10), registro, particle));
	obstacles.push_back(new MoveObstacle(Vector3(2300, 100, 10), Vector3(2300, 50, 10), Vector3(0, 30, 0), particle, 50));
	enemys.push_back(new Enemy(Vector3(2400, 50, 0), Vector3(0, 15, 0), particle));
	enemys.push_back(new Enemy(Vector3(2400, 50, 0), Vector3(0, 5, 0), particle));
	enemys.push_back(new Enemy(Vector3(2400, 50, 0), Vector3(0, 25, 0), particle));
	obstacles.push_back(new WaterObstacle(Vector3(2400, -10, 10), registro, particle));
	obstacles.push_back(new MoveObstacle(Vector3(2500, 100, 10), Vector3(2550, 50, 10), Vector3(0, 30, 0), particle, 100));
	obstacles.push_back(new SimpleObstacle(Vector3(2650, 0, 0), Vector3(20, 100, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(2650, 150, 10), registro, particle));
	obstacles.push_back(new SimpleObstacle(Vector3(2800, 0, 0), Vector3(20, 20, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(2800, 120, 0), Vector3(20, 50, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(2900, 150, 10), registro, particle));
	obstacles.push_back(new WaterObstacle(Vector3(2900, -10, 10), registro, particle));
	obstacles.push_back(new MoveObstacle(Vector3(2900, 100, 10), Vector3(2900, 50, 10), Vector3(0, 10, 0), particle, 50));
	obstacles.push_back(new SimpleObstacle(Vector3(3000, 75, 0), Vector3(80, 20, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(3000, 150, 10), registro, particle));
	obstacles.push_back(new WaterObstacle(Vector3(3000, -10, 10), registro, particle));
	enemys.push_back(new Enemy(Vector3(3100, 50, 0), Vector3(0, 15, 0), particle));
	enemys.push_back(new Enemy(Vector3(3100, 50, 0), Vector3(0, 35, 0), particle));
	obstacles.push_back(new SimpleObstacle(Vector3(3200, 0, 0), Vector3(20, 60, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(3200, 155, 0), Vector3(20, 60, 20), gScene, gPhysics));
	obstacles.push_back(new MoveObstacle(Vector3(3300, 100, 10), Vector3(3350, 50, 10), Vector3(0, 10, 0), particle, 50));
	enemys.push_back(new Enemy(Vector3(3400, 50, 0), Vector3(0, 50, 0), particle));
	obstacles.push_back(new SimpleObstacle(Vector3(3400, 0, 0), Vector3(80, 40, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(3400, 155, 0), Vector3(80, 40, 20), gScene, gPhysics));
	obstacles.push_back(new SimpleObstacle(Vector3(3550, 40, 0), Vector3(20, 80, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(3650, 150, 10), registro, particle));
	obstacles.push_back(new WaterObstacle(Vector3(3650, -10, 10), registro, particle));
	enemys.push_back(new Enemy(Vector3(3650, 50, 0), Vector3(0, 70, 0), particle));
	enemys.push_back(new Enemy(Vector3(3650, 50, 0), Vector3(0, 50, 0), particle));
	obstacles.push_back(new MoveObstacle(Vector3(3700, 100, 10), Vector3(3700, 50, 10), Vector3(0, 30, 0), particle, 50));
	obstacles.push_back(new SimpleObstacle(Vector3(3800, 130, 0), Vector3(20, 80, 20), gScene, gPhysics));
	obstacles.push_back(new MoveObstacle(Vector3(3850, 100, 10), Vector3(3900, 50, 10), Vector3(0, 10, 0), particle, 50));
	obstacles.push_back(new SimpleObstacle(Vector3(4000, 75, 0), Vector3(80, 40, 20), gScene, gPhysics));
	obstacles.push_back(new WaterObstacle(Vector3(4000, 150, 10), registro, particle));
	obstacles.push_back(new WaterObstacle(Vector3(4000, -10, 10), registro, particle));
	win.push_back(new Win(Vector3(4100, 75, 0), Vector3(10, 155, 20), true));
}

void updateParticle(double t) {
	for (int i = 0; i < particle.size(); i++) {
		if (particle[i] != nullptr) {
			if (particle[i]->update(t)) {
				delete particle[i];
				particle[i] = nullptr;
			}
		}
	}
}
void updateRigidbody() {
	for (int i = 0; i < rigidBody.size(); i++) {
		if (rigidBody[i] != nullptr) {
			rigidBody[i]->time += 0.1;
			if (rigidBody[i]->time > rigidBody[i]->desaparecer) {
				delete rigidBody[i];
				rigidBody[i] = nullptr;
			}
		}
	}
}
void collision() {
	for (int i = 0; i < obstacles.size(); i++) {
		if (obstacles[i] != nullptr) {
			obstacles[i]->update();
			if (obstacles[i]->colission(player->personaje)) {
				player->dead();
			}
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->bullet != nullptr) {
			for (int x = 0; x < enemys.size(); x++) {
				if (enemys[x]->personaje != nullptr)
					if (bullets[i]->update(enemys[x]))
						player->increPoints();
			}
		}
	}

	for (int i = 0; i < enemys.size(); i++) {
		if (enemys[i]->personaje != nullptr) {
			enemys[i]->update();
			if (enemys[i]->colission(player->personaje)) {
				player->dead();
			}
		}
	}

	for (int i = 0; i < win.size(); i++) {
		win[i]->colission(player);
	}
}
void Victory() {
	if (player->respawnFirework > 100 && player->numFirework < 6) {
		player->respawnFirework = 0;
		player->numFirework++;
		particle.push_back(new Firework(PxSphereGeometry(3), Vector3(player->getPosition().x + 200, player->getPosition().y, player->getPosition().z), Vector3(0, 0, 0), Vector3(0, 100, 0), 5, 0.5, payload, Vector4(1, 0, 0, 1), &particle));

	}
	else if (player->respawnFirework > 500 && player->numFirework == 6) {
		player->restart();
	}
	if (player->numFirework <= 6)
		player->respawnFirework++;
}

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);
	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);
	
	
	//Suelo
	RigidBody* suelo = new RigidBody(false, Vector3(1910, -115, 0), Vector4(0.5,1,0.5,1), Vector3(2200, 100, 25), gScene,gPhysics,0);
	RigidBody* techo = new RigidBody(false, Vector3(1910, 255, 0), Vector4(0.5,1,0.5,1), Vector3(2200, 100, 25), gScene,gPhysics,0);
	//Player
	player = new Player(Vector3(-10, 50, 0), gScene, gPhysics, particle); //Segundo Nivel -335
	player->showPoints();
	generador= new ParticleGenerator(15, player->getPosition(), Vector3(-50, 0, 0), particle);
	registro = new ParticleForceRegistry();
	GetCamera()->setTransform(player->getPosition().x + 100, 75, player->getPosition().z + 200);

	Level1();
	Level2();

}

// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	registro->updateForces(1);
	player->update(5);
	generador->update(Vector3(player->personaje->getPosition().x - 15, player->personaje->getPosition().y, player->personaje->getPosition().z));

	updateParticle(t);
	updateRigidbody();
	collision();

	if (player->victory)
		Victory();	
	
	gScene->simulate(t);
	gScene->fetchResults(true);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	gFoundation->release();
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch(toupper(key))
	{
	case ' ':
	{
		player->Jump(5000);
		break;
	}
	case 'C':
	{
		player->shoot(bullets);
		break;
	}
	case 'R': 
	{
		player->restart();
		break;
	}
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}