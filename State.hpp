#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include "Type.hpp"
#include "StateEvent.hpp"

#include <SFML/Graphics.hpp>

namespace rpg
{

class Application;
class RendererManager;

class State
{
public:

    State(Application* app);
    State(const State&) = delete;
    State& operator=(const State&) = delete;
    virtual ~State();

    virtual void init() = 0;
    virtual void cleanup() = 0;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw() = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;

protected:
    Application* mApp;
    RendererManager& mRenderManager;

    StateEvent mEvent;
};

typedef std::unique_ptr<State> uptr_state;

}



#endif // STATE_HPP_INCLUDED
