#include "WanderingState.h"

WanderingState::WanderingState()
{
}

void WanderingState::Enter(Entity* ent){
	turns = 0;
}

void WanderingState::Execute(Entity* ent){
	int r = rand() % ent->current->partners.size();
	ent->current = ent->current->partners[r];
	turns++;
}

void WanderingState::Exit(Entity* ent){

	//Dit gebeurt na de kans berekening
	
}

WanderingState::~WanderingState()
{
}
