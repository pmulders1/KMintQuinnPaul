#include "Entity.h"

Entity::Entity(SDL_Texture* normaltext, int xSize, int ySize, Graph* graph, SDL_Texture* madtext, SDL_Texture* idleText, State stateType) : madtext(madtext), idleText(idleText), normaltext(normaltext), xSize(xSize), ySize(ySize), graph(graph), stateType(stateType)
{
	this->currtext = normaltext;
	this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
}

void Entity::Update(){
	if (state != nullptr){
		state->Execute(this);
	}
}

void Entity::Collision(){
	//Stap 1: Checken of een enity chased en of ze op dezelfde plek staan
	if (this->stateType == State::CHASE && this->current == this->toChase->current){
		int r = rand() % this->graph->graph.size();
		while (this->toChase->current == this->graph->graph[r]){
			r = rand() % this->graph->graph.size();
		}
		if (this->toChase->stateType == State::CHASE){
			int r = rand() % this->graph->graph.size();
			while (this->current == this->graph->graph[r]){
				r = rand() % this->graph->graph.size();
			}
			this->current = this->graph->graph[r];
			this->toChase->stateType = State::WANDERING;
			this->toChase->ChangeState(StateFactory::Instance()->ReturnState(this->toChase->stateType));
		}
		this->toChase->current = this->graph->graph[r];

		if (this->toChase->hasPill){
			this->stateType = State::SLEEPING;
			this->ChangeState(StateFactory::Instance()->ReturnState(stateType));

			this->toChase->hasPill = false;
			this->toChase->stateType = State::WANDERING;
			this->toChase->ChangeState(StateFactory::Instance()->ReturnState(this->toChase->stateType));
		}
	}
	makeChoice();
	if (this->stateType == State::SEARCHWEAPON && this->current == this->powerup2->current){
		this->stateType = State::CHASE;
		this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
		int r = rand() % this->graph->graph.size();
		while (this->powerup2->current == this->graph->graph[r]){
			r = rand() % this->graph->graph.size();
		}
		this->powerup2->current = this->graph->graph[r];
	}
	if (this->stateType == State::SEARCHPILL && this->current == this->powerup1->current){
		this->stateType = State::IDLE;
		this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
		this->hasPill = true;
		int r = rand() % this->graph->graph.size();
		while (this->powerup1->current == this->graph->graph[r]){
			r = rand() % this->graph->graph.size();
		}
		this->powerup1->current = this->graph->graph[r];
	}
}

void Entity::makeChoice(){
	//Stap 2: Checken of de haas de koe in de gaten heeft
	if (this->stateType == State::WANDERING && this->checkClosely()){
		// bepalen of het wapen of pil dichterbij licht
		vector<Vertex*> weaponpath = graph->Astar(this, this->powerup2);
		vector<Vertex*> pillpath = graph->Astar(this, this->powerup1);

		// Eventueel als bijde paden langer zijn dan 5 of 6 ofzo de kans voor wandering omhoog gooien.
		if (weaponpath.size() > 6 && pillpath.size() > 6){
			this->CalculateChance(10, -5, -5);
		}
		// Als bijde paden onder de ondergrens zijn bepalen welke stats verhoogd moeten worden.
		else {
			// Als het wapen pad korter is stats voor het wapen pakken verhogen.
			if (weaponpath.size() < pillpath.size()){
				this->CalculateChance(-5, 10, -5);
			}
			// Ander de stats voor het pakken van de pil verhogen.
			else {
				this->CalculateChance(-5, -5, 10);
			}
		}
		cout << "Kansen van de " << this->name << " - Vluchten: " << fleeChance << "%; Zoeken pill: " << pillChance << "%; Zoeken wapen: " << weaponChance << "%;" << endl;
		int result = rand() % 100;
		if (result <= fleeChance){
			this->stateType = State::WANDERING;
			this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
			cout << "De state van de " << this->name << " is nu: Wandering" << endl;
		}
		else if (result > fleeChance && result < weaponChance + fleeChance){
			this->stateType = State::SEARCHWEAPON;
			this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
			cout << "De state van de " << this->name << " is nu: Zoek Wapen" << endl;
		}
		else if (result > fleeChance + weaponChance && result < weaponChance + fleeChance + pillChance){
			this->stateType = State::SEARCHPILL;
			this->ChangeState(StateFactory::Instance()->ReturnState(stateType));
			cout << "De state van de " << this->name << " is nu: Zoek Pill" << endl;
		}
	}
}

void Entity::CalculateChance(int flee, int weapon, int pill){
	if (fleeChance + flee <= 90 && fleeChance + flee >= 5 
			&& weaponChance + weapon <= 90 && weaponChance + weapon >= 5 
			&& pillChance + pill <= 90 && pillChance + pill >= 5){
		fleeChance += flee;
		weaponChance += weapon;
		pillChance += pill;
	}
}

void Entity::ChangeState(EntityState* newState){
	if (state != nullptr){
		state->Exit(this);
	}
	state = newState;
	state->Enter(this);
}

bool Entity::checkClosely(){
	//Twee plekken van de haas af
	return this->graph->Astar(this->graph->cow, this->graph->rabbit).size() <= 2;
}

Entity::~Entity()
{
}
