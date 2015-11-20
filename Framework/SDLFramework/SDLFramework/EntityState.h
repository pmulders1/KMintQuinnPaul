#pragma once

class Entity;

class EntityState
{
public:
	EntityState();

	virtual void Enter() = 0;
	virtual void Execute(Entity* ent) = 0;
	virtual void Exit() = 0;

	virtual ~EntityState();
};
