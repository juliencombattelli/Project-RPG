#ifndef STATEEVENT_HPP_INCLUDED
#define STATEEVENT_HPP_INCLUDED

#include "Event.hpp"

namespace rpg
{

class StateEvent : public Event
{
public:
    StateEvent();
    virtual ~StateEvent();

    void destroyState(StateID id);
    void createState(StateID id);
};

}

#endif // STATEEVENT_HPP_INCLUDED
