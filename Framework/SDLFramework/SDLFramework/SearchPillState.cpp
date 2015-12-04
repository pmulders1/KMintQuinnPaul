#include "SearchPillState.h"


SearchPillState::SearchPillState()
{
}

void SearchPillState::Enter(Entity* ent){
	turns = 0;
}

void SearchPillState::Execute(Entity* ent){
	if (ent->powerup1 != nullptr){
		vector<Vertex*> path = ent->graph->Astar(ent, ent->powerup1);
		if (path.size() > 0){
			ent->current = path[path.size() - 1];
		}
	}
	turns++;
}

void SearchPillState::Exit(Entity* ent){

}

SearchPillState::~SearchPillState()
{
}
