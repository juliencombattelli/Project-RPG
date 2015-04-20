#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include "Type.hpp"

namespace rpg
{

class Event
{
public:

    Event();
    virtual ~Event();

protected:

    signal_t mSignal;
    connection_t mConnection;
};

}

#endif // EVENT_HPP_INCLUDED
