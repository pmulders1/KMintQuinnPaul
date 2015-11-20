#include "Entity.h"

Entity::Entity(SDL_Texture* normaltext, int xSize, int ySize, Entity* partner, Graph* graph, SDL_Texture* madtext) : madtext(madtext), normaltext(normaltext), xSize(xSize), ySize(ySize), partner(partner), graph(graph)
{
	this->currtext = normaltext;
	this->stateType = State::WANDERING;
	this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
}

void Entity::Update(){
	if (state != nullptr){
		state->Execute(this);
	}
}

void Entity::Collision(){
	if (this->current == this->partner->partner->current && this->stateType == State::CHASE){
		if (this->partner->partner->stateType == State::CHASE){
			this->current = this->graph->graph[rand() % this->graph->graph.size()];
		}
		this->stateType = State::WANDERING;
		this->currtext = normaltext;
		this->ChangeState(StateFactory::Instance()->ReturnState(this->stateType));

		this->partner->partner->current = this->graph->graph[rand() % this->graph->graph.size()];
		this->partner->partner->stateType = State::WANDERING;
		this->partner->partner->currtext = this->partner->partner->normaltext;
		this->partner->partner->ChangeState(StateFactory::Instance()->ReturnState(this->partner->partner->stateType));

		this->graph->ClearLists();
	}

	if (this->current == this->partner->current && this->stateType == State::WANDERING){
		this->stateType = State::CHASE;
		this->currtext = madtext;
		this->ChangeState(StateFactory::Instance()->ReturnState(this->stateType));
		int index = rand() % this->graph->graph.size();
		this->partner->current = this->graph->graph[index];
		vector<Vertex*> path = this->graph->Astar(this, this->partner->partner);
	}
}

void Entity::ChangeState(EntityState* newState){
	if (state != nullptr){
		state->Exit();
	}
	state = newState;
	state->Enter();
}

Entity::~Entity()
{
}
