#pragma once
#include <map>
#include "State.h"
#include "EntityState.h"
#include "WanderingState.h"
#include "FleeState.h"
#include "ChaseState.h"
using namespace std;
class StateFactory
{
public:
	static StateFactory* Instance();
	static void ResetInstance()
	{
		delete m_instance; // REM : it works even if the pointer is NULL (does nothing then)
		m_instance = NULL; // so GetInstance will still work.
	}
	
	EntityState* ReturnState(State t);

	~StateFactory();

private:
	static StateFactory* m_instance;
	map<State, EntityState*> dict;
	StateFactory();
};

