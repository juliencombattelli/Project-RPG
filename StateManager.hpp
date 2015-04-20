#ifndef STATEMANAGER_HPP_INCLUDED
#define STATEMANAGER_HPP_INCLUDED

#include "Type.hpp"

namespace rpg
{

class Application;
class State;

class StateManager
{
public:
    StateManager() = delete;
    StateManager(Application* app);
    StateManager(const StateManager&) = delete;
    StateManager& operator=(const StateManager&) = delete;
    ~StateManager();

    void init();

    void cleanup();

    void pushState(State* state);
    void popState();

    bool isEmpty() const { return mStates.empty(); }

    State& getActiveState() { return *mStates.front(); }

private:

    Application* mApp;

    std::vector<State*> mStates;
};

}

#endif // STATEMANAGER_HPP_INCLUDED
