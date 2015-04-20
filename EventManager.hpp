#ifndef EVENTMANAGER_HPP_INCLUDED
#define EVENTMANAGER_HPP_INCLUDED

#include "Type.hpp"

namespace rpg
{

class Application;

class EventManager
{
public:

    EventManager() = delete;
    EventManager(Application* app);
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    ~EventManager();

private:

    Application* mApp;
};

}

#endif // EVENTMANAGER_HPP_INCLUDED
