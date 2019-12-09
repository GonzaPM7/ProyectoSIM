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
ParticleForceRegistry* registro;
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
SimpleObstacle* obstacle;
MoveObstacle* obstacleMove;
GeneratorRB* generador;
Enemy* enemy;
std::vector<Bullet*> bullets;

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
	
	
	//GetCamera()->setDir(0, 0, -100);
	//Suelo
	RigidBody* suelo = new RigidBody(false, Vector3(910, -115, 0), Vector4(0.5,1,0.5,1), Vector3(1000, 100, 20), gScene,gPhysics,0);
	RigidBody* techo = new RigidBody(false, Vector3(910, 255, 0), Vector4(0.5,1,0.5,1), Vector3(1000, 100, 20), gScene,gPhysics,0);
	//Player
	player = new Player(Vector3(0, 50, 0), gScene, gPhysics, particle);
	generador= new GeneratorRB(player->personaje->getPosition(), Vector3(-350, 0, 0), rigidBody, 0, gScene, gPhysics, 15);
	GetCamera()->setTransform(player->getPosition().x + 100, 100, player->getPosition().z + 200);

	obstacle = new SimpleObstacle(Vector3(300, 0, 0), Vector3(20, 50, 20), gScene, gPhysics);
	obstacleMove = new MoveObstacle(Vector3(100, 100, 10), Vector3(100, 0, 10), Vector3(0, 30, 0), particle);
	enemy = new Enemy(Vector3(200, 50, 0), Vector3(0, 5, 0), particle);
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	for (int i = 0; i < particle.size(); i++ ) {
		if (particle[i] != nullptr) {
			if (particle[i]->update(t)) {
				delete particle[i];
				particle[i] = nullptr;
			}
		}
	}

	for (int i = 0; i < rigidBody.size(); i++) {
		if (rigidBody[i] != nullptr) {
			rigidBody[i]->time += 0.1;
			if (rigidBody[i]->time > rigidBody[i]->desaparecer) {
				delete rigidBody[i];
				rigidBody[i] = nullptr;
			}
		}
	} 

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->bullet != nullptr) {
			bullets[i]->update(enemy);
		}
	}

	if (player->personaje->getVelocity().x<=0)
		cout << "colision";

	player->update(1);
	generador->update(Vector3(player->personaje->getPosition().x - 15, player->personaje->getPosition().y, player->personaje->getPosition().z));
	obstacleMove->update();
	GetCamera()->setTransform(player->getPosition().x + 100, 75, player->getPosition().z + 200);
	if(enemy->personaje!=nullptr)
		enemy->update();

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
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		player->Jump(3000);
		break;
	}
	case 'V':
	{
		activeV = true;
		break;
	}
	case 'B':
	{
		//p->setVelocity(Vector3(0, 0, 0));
		activeV = false;
		break;
	}
	case 'C':
	{
		player->shoot(bullets);
		break;
	}
	case 'F':
	{		
		Vector3 pos = GetCamera()->getEye() + GetCamera()->getDir().getNormalized() * 200;
		Particle* p = new Particle(70, Vector4(1, 1, 1, 0), 1, pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5);
		particle.push_back(p);
		explosion->createHit(p);
		break;
	}
	case 'Q':
	{
		Camera* camera = GetCamera();

		Payload payload = Payload(3, 5);

		float FuerzaLanzamiento = 100;
		float FuerzaDeGravedad = -6;
		float age = 5;

		Firework* f = new Firework(PxSphereGeometry(10),
			{ 0, 0, 0 }, { 0, FuerzaLanzamiento, 0 }, { 0, 0, 0 },
			0.7, age, payload,Vector4(1,0,0,1), &particle);
		particle.push_back(f);
		break;
	}
	case '+':
	{
		buoyancy->increVolum();
		break;
	}
	case '-':
	{
		buoyancy->dicreVolum();
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