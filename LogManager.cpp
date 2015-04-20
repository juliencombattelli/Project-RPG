#include "LogManager.hpp"

namespace rpg
{

LogManager::LogManager(Application* app) : mApp(app), mAppLogger("log/app.log"), mEventLogger("log/event.log"), mStatLogger("log/stat.log")
{

}

LogManager::~LogManager()
{
    mApp = nullptr;
}

FileLogger& LogManager::getAppLogger()
{
    FileLogger* result = nullptr;
    result = &mAppLogger;
    return *result;
}

FileLogger& LogManager::getEventLogger()
{
    FileLogger* result = nullptr;
    result = &mEventLogger;
    return *result;
}

FileLogger& LogManager::getStatLogger()
{
    FileLogger* result = nullptr;
    result = &mStatLogger;
    return *result;
}

}
