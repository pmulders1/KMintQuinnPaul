#pragma once
#include "FWApplication.h"
#include "EntityState.h"
#include "StateFactory.h"
#include "Vertex.h"

class Graph;

class Entity
{
public:
	Entity(SDL_Texture* normaltext, int xSize, int ySize, Entity* partner = 0, Graph* graph = 0, SDL_Texture* madtext = 0, SDL_Texture* idleText = 0);

	SDL_Texture* currtext;
	SDL_Texture* normaltext;
	SDL_Texture* madtext;
	SDL_Texture* idleText;
	EntityState* state;
	State stateType;

	Graph* graph;
	Entity* partner;
	Vertex* current;
	Vertex* goal;

	void ChangeState(EntityState* newState);
	void Update();
	void Collision();
	bool checkNeighbours();

	int xSize;
	int ySize;
	~Entity();
};

