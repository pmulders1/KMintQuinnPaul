#include "SearchWeaponState.h"


SearchWeaponState::SearchWeaponState()
{
}

void SearchWeaponState::Enter(Entity* ent){
	turns = 0;
}

void SearchWeaponState::Execute(Entity* ent){
	if (ent->powerup2 != nullptr){
		vector<Vertex*> path = ent->graph->Astar(ent, ent->powerup2);
		if (path.size() > 0){
			ent->current = path[path.size() - 1];
		}
	}
	turns++;
}

void SearchWeaponState::Exit(Entity* ent){

}

SearchWeaponState::~SearchWeaponState()
{
}
