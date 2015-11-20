#include "ChaseState.h"


ChaseState::ChaseState()
{
}

void ChaseState::Enter(){

}

void ChaseState::Execute(Entity* ent){
	vector<Vertex*> path = ent->graph->Astar(ent, ent->partner->partner);
	if (path.size() > 0){
		ent->current = path[path.size() - 1];
	}
}

void ChaseState::Exit(){

}

ChaseState::~ChaseState()
{
}
