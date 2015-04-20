#include "StateManager.hpp"
#include "State.hpp"
#include "CarreRouge.hpp"

namespace rpg
{

StateManager::StateManager(Application* app) : mApp(app), mStates()
{

}

StateManager::~StateManager()
{
    mApp = nullptr;
}

void StateManager::init()
{
    mStates.push_back(new CarreRouge(mApp));
}

void StateManager::cleanup()
{
    while(not isEmpty())
    {
        mStates.back()->cleanup();
        mStates.pop_back();
    }
}

void StateManager::pushState(State* state)
{
    mStates.push_back(state);
}
void StateManager::popState()
{
    mStates.pop_back();
}

}
