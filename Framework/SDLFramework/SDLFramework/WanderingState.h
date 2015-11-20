#pragma once
#include "EntityState.h"
#include "Entity.h"
#include "Graph.h"
class WanderingState : public EntityState
{
public:
	WanderingState();

	virtual void Enter();
	virtual void Execute(Entity* ent);
	virtual void Exit();

	~WanderingState();
};

