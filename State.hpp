#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include "Type.hpp"
#include "StateEvent.hpp"

#include <SFML/Graphics.hpp>

namespace rpg
{

class Application;

class State
{
public:
    State(Application* app);
    State(const State&) = delete;
    State& operator=(const State&) = delete;
    virtual ~State();

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw() = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void cleanup() = 0;

protected:
    Application* mApp;

    StateEvent mEvent;
};

}



#endif // STATE_HPP_INCLUDED
