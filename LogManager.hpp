#ifndef LOGMANAGER_HPP_INCLUDED
#define LOGMANAGER_HPP_INCLUDED

#include "Type.hpp"
#include "FileLogger.hpp"

namespace rpg
{

class Application;

class LogManager
{
public:

    LogManager() = delete;
    LogManager(Application* app);
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;
    ~LogManager();

    FileLogger& getAppLogger();
    FileLogger& getEventLogger();
    FileLogger& getStatLogger();

private:

    Application* mApp;

    FileLogger mAppLogger;
    FileLogger mEventLogger;
    FileLogger mStatLogger;
};

}

#endif // LOGMANAGER_HPP_INCLUDED
