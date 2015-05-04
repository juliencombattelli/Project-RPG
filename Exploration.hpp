#ifndef EXPLORATION_HPP_INCLUDED
#define EXPLORATION_HPP_INCLUDED

#include "State.hpp"

namespace rpg
{

class Exploration : public State
{
public:
    Exploration(Application* app);
    virtual ~Exploration();

    virtual void handleEvent(sf::Event& event) final;
    virtual void update(float elapsedTime) final;
    virtual void draw() final;

    virtual void pause() final;
    virtual void resume() final;
    virtual void cleanup() final;

private:

};

}


#endif // EXPLORATION_HPP_INCLUDED
