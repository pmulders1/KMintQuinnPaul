#pragma once
#include "EntityState.h"
#include "Entity.h"
class IdleState : public EntityState
{
public:
	IdleState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~IdleState();
};

