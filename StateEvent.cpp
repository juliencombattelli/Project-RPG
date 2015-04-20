#include "StateEvent.hpp"
#include "Type.hpp"

namespace rpg
{

StateEvent::StateEvent()
{

}

StateEvent::~StateEvent()
{

}

void StateEvent::destroyState(StateID id)
{
    mSignal(id,"State destroy");
}

void StateEvent::createState(StateID id)
{
    mSignal(id,"State created");
}

}
