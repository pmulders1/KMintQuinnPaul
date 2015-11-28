#pragma once
#include "EntityState.h"
#include "Entity.h"
class StaticObjectState : public EntityState
{
public:
	StaticObjectState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~StaticObjectState();
};

