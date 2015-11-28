#include "SleepingState.h"


SleepingState::SleepingState()
{
}

void SleepingState::Enter(Entity* ent){
	ent->currtext = ent->sleepingText;
	turns = 4;
}

void SleepingState::Execute(Entity* ent){
	if (turns == 0){
		ent->stateType = State::CHASE;
		ent->ChangeState(StateFactory::Instance()->ReturnState(ent->stateType));
	}else{
		turns--;
	}
}

void SleepingState::Exit(Entity* ent){
	ent->currtext = ent->sleepingText;
}


SleepingState::~SleepingState()
{
}
