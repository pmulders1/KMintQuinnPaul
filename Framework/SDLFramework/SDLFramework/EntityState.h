#pragma once

class Entity;

class EntityState
{
public:
	EntityState();

	virtual void Enter(Entity* ent) = 0;
	virtual void Execute(Entity* ent) = 0;
	virtual void Exit(Entity* ent) = 0;

	int turns;

	virtual ~EntityState();
};
