#include "StateManager.hpp"
#include "State.hpp"
#include "Exploration.hpp"
#include <memory>

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
    this->pushState(new Exploration(mApp));
}

void StateManager::cleanup()
{
    while(not isEmpty())
        popState();
}

void StateManager::pushState(State* state)
{
    mStates.push_back(state);   // register pointer state
    mStates.back()->init();     // initialize state
}
void StateManager::popState()
{
    mStates.back()->cleanup();  // deinit state
    delete mStates.back();      // delete state
    mStates.pop_back();         // erase pointer
}

}
