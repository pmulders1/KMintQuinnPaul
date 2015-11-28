#pragma once
#include "EntityState.h"
class FleeState : public EntityState
{
public:
	FleeState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~FleeState();
};

