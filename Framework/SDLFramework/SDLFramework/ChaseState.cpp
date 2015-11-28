#include "ChaseState.h"


ChaseState::ChaseState()
{
}

void ChaseState::Enter(Entity* ent){
	ent->currtext = ent->madtext;
}

void ChaseState::Execute(Entity* ent){
	if (ent->toChase != nullptr){
		vector<Vertex*> path = ent->graph->Astar(ent, ent->toChase);
		if (path.size() > 0){
			ent->current = path[path.size() - 1];
		}
	}
}

void ChaseState::Exit(Entity* ent){
	ent->currtext = ent->normaltext;
}

ChaseState::~ChaseState()
{
}
