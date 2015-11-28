#pragma once
#include "EntityState.h"
#include "Entity.h"
class SearchPillState : public EntityState
{
public:
	SearchPillState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~SearchPillState();
};

