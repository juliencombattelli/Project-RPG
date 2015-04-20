#include "EventManager.hpp"

namespace rpg
{

EventManager::EventManager(Application* app) : mApp(app)
{

}

EventManager::~EventManager()
{
    mApp = nullptr;
}

}
