#pragma once
#include "RigidBody.h"
class ObstacleSystem
{
public:
	// Overload to provide functionality
	virtual void update() = 0;
	virtual bool colission(RigidBody* player) = 0;
};