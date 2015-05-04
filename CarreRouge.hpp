#ifndef CARREROUGE_HPP_INCLUDED
#define CARREROUGE_HPP_INCLUDED

#include "State.hpp"

namespace rpg
{

class CarreRouge : public State
{
public:
    CarreRouge(Application* app);
    virtual ~CarreRouge();

    virtual void handleEvent(sf::Event& event);
    virtual void update(float elapsedTime);
    virtual void draw();

    virtual void pause();
    virtual void resume();
    virtual void cleanup();

private:

    sf::RectangleShape mRectangle;
    uint16_t mSpeed;
};

}

#endif // CARREROUGE_HPP_INCLUDED
