#include "IdleState.h"


IdleState::IdleState()
{
}

void IdleState::Enter(Entity* ent){
	ent->currtext = ent->idleText;
}

void IdleState::Execute(Entity* ent){
	
}

void IdleState::Exit(Entity* ent){
	ent->currtext = ent->normaltext;
}

IdleState::~IdleState()
{
}

