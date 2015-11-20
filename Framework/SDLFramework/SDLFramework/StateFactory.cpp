#include "StateFactory.h"

StateFactory* StateFactory::m_instance = nullptr;

StateFactory* StateFactory::Instance()
{
	if (m_instance == nullptr) m_instance = new StateFactory();
	return m_instance;
};

StateFactory::StateFactory()
{
	dict.insert(make_pair(State::CHASE, new ChaseState()));
	dict.insert(make_pair(State::WANDERING, new WanderingState()));
}

EntityState* StateFactory::ReturnState(State t){
	EntityState* temp = nullptr;

	temp = dict[t];

	return temp;
}

StateFactory::~StateFactory()
{
}
