#include "WanderingState.h"

WanderingState::WanderingState()
{
}

void WanderingState::Enter(){

}

void WanderingState::Execute(Entity* ent){
	int r = rand() % ent->current->partners.size();
	ent->current = ent->current->partners[r];
}

void WanderingState::Exit(){

}

WanderingState::~WanderingState()
{
}
