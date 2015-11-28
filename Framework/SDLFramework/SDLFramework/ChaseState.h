#pragma once
#include "EntityState.h"
#include "Entity.h"
class ChaseState : public EntityState
{
public:
	ChaseState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~ChaseState();
};

