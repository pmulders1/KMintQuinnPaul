#pragma once
#include "EntityState.h"
#include "Entity.h"
class SearchWeaponState : public EntityState
{
public:
	SearchWeaponState();

	virtual void Enter(Entity* ent);
	virtual void Execute(Entity* ent);
	virtual void Exit(Entity* ent);

	~SearchWeaponState();
};

