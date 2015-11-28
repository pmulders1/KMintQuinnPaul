#pragma once
#include "FWApplication.h"
#include "EntityState.h"
#include "StateFactory.h"
#include "Vertex.h"
#include <iostream>
#include <string> 
class Graph;

class Entity
{
public:
	Entity(SDL_Texture* normaltext, int xSize, int ySize, Graph* graph = 0, SDL_Texture* madtext = 0, SDL_Texture* idleText = 0, State stateType = State::STATICOBJECT);

	SDL_Texture* currtext;
	SDL_Texture* normaltext;
	SDL_Texture* madtext;
	SDL_Texture* idleText;
	SDL_Texture* sleepingText;
	EntityState* state;
	State stateType;

	Graph* graph;
	Entity* powerup1;
	Entity* powerup2;
	Entity* toChase;
	Vertex* current;
	Vertex* goal;
	
	string name;

	void ChangeState(EntityState* newState);
	void Update();
	void Collision();
	bool checkClosely();
	void CalculateChance(int flee, int weapon, int pill);
	void makeChoice();

	bool hasPill;

	int weaponChance;
	int pillChance;
	int fleeChance;

	int xSize;
	int ySize;
	~Entity();
};

