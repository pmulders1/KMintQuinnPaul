#pragma once
#include "EntityState.h"
#include "Entity.h"
class IdleState : public EntityState
{
public:
	IdleState();

	virtual void Enter();
	virtual void Execute(Entity* ent);
	virtual void Exit();

	~IdleState();
};

