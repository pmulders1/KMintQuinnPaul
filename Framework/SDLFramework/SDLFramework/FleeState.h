#pragma once
#include "EntityState.h"
class FleeState : public EntityState
{
public:
	FleeState();

	virtual void Enter();
	virtual void Execute(Entity* ent);
	virtual void Exit();

	~FleeState();
};

