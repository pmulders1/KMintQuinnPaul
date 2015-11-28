#include "StaticObjectState.h"


StaticObjectState::StaticObjectState()
{
}

void StaticObjectState::Enter(Entity* ent){
	ent->currtext = ent->normaltext;
}

void StaticObjectState::Execute(Entity* ent){

}

void StaticObjectState::Exit(Entity* ent){
	ent->currtext = ent->normaltext;
}

StaticObjectState::~StaticObjectState()
{
}
