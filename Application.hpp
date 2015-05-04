#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "Type.hpp"
#include "StateManager.hpp"
#include "EventManager.hpp"
#include "LogManager.hpp"
#include "RendererManager.hpp"

namespace rpg
{

class Application
{
public:

    Application();
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    ~Application();

    bool isRunning() const { return mRunning; }
    void quit(int exitStatus);
    int  run();

    LogManager&         getLogManager();
    RendererManager&    getRendererManager();

private:

    void init();
    void handleEvent(State& state);
    void gameLoop();
    void cleanup();

    StateManager    mStateManager;
    EventManager    mEventManager;
    LogManager      mLogManager;
    RendererManager mRendererManager;

    bool mRunning;
    int  mExitStatus;
};

}

#endif // APPLICATION_HPP_INCLUDED
