#include "Application.hpp"
#include "State.hpp"

namespace rpg
{

Application::Application() :
    mStateManager(this), mEventManager(this), mLogManager(this), mRendererManager(this),
    mRunning(false), mExitStatus(StatusNoError)
{
    APPLOGA(SeverityInfo) << "Application created" << std::endl << std::endl;
}

Application::~Application()
{
    APPLOGA(SeverityInfo) << "Application destroyed" << std::endl << std::endl;
}

void Application::quit(int exitStatus)
{
    mExitStatus = exitStatus;
    mRunning = false;
}

int Application::run()
{
    mRunning = true;

    init();

    gameLoop();

    cleanup();

    mRunning = false;

    if(mExitStatus == StatusAppMissingAsset)
        APPLOGA(SeverityFatal) << "exitCode = " << mExitStatus << std::endl << std::endl;
    else if(mExitStatus <= StatusError)
        APPLOGA(SeverityError) << "exitCode = " << mExitStatus << std::endl << std::endl;
    else if(mExitStatus >= StatusNoError)
        APPLOGA(SeverityInfo)  << "exitCode = " << mExitStatus << std::endl << std::endl;

    return mExitStatus;
}

LogManager& Application::getLogManager()
{
    LogManager* result = nullptr;
    result = &mLogManager;
    return *result;
}

RendererManager& Application::getRendererManager()
{
    RendererManager* result = nullptr;
    result = &mRendererManager;
    return *result;
}

void Application::init()
{
    mStateManager.init();
    mRendererManager.init();
}

void Application::handleEvent(State& state)
{
    sf::Event event;
    while(mRendererManager.getWindow().pollEvent(event))
    {
        if(event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)
                                          and  sf::Keyboard::isKeyPressed(sf::Keyboard::F4)))
        {
            APPLOGE(SeverityInfo) << "<Alt> + <F4> pressed" << std::endl << std::endl;
            quit(StatusAppOK);
        }

        else if(event.type == sf::Event::GainedFocus)
        {
            APPLOGE(SeverityInfo) << "Focus gained" << std::endl << std::endl;
            state.resume();
        }

        else if(event.type == sf::Event::LostFocus)
        {
            APPLOGE(SeverityInfo) << "Focus lost" << std::endl << std::endl;
            state.pause();
        }

        else if(event.type == sf::Event::Resized)
        {
            APPLOGE(SeverityInfo) << "Window resized" << std::endl << std::endl;
            //glViewport(0, 0, event.size.width, event.size.height);
        }
    }

    state.handleEvent(event);
}

void Application::gameLoop()
{
    sf::Clock frameClock;

    if(mStateManager.isEmpty())
        quit(StatusAppInitFailed);

    while(isRunning() and not(mStateManager.isEmpty()) and mRendererManager.getWindow().isOpen())
    {
        State& state = mStateManager.getActiveState();

        handleEvent(state);

        state.update(frameClock.restart().asSeconds());

        mRendererManager.clear();

        state.draw();

        mRendererManager.display();
    }
}

void Application::cleanup()
{
    /*mRendererManager.cleanup()
    {
        if(mWindow.isOpen())
        {
            mWindow.setMouseCursorVisible(true);
            mWindow.close();
        }
    }*/
    mStateManager.cleanup();
}

}
