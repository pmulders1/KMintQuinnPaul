#pragma once
#include "EntityState.h"
#include "Entity.h"
class SleepingState : public EntityState
{
public:
	SleepingState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	int turns;

	~SleepingState();
};

