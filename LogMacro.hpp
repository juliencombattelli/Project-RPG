#ifndef LOGMACRO_HPP_INCLUDED
#define LOGMACRO_HPP_INCLUDED

/*************************************************************************
 * \brief Macro use by Application class to log messages in app.log
 *************************************************************************/
/*#define APPLOG(severity, message)\
    mLogManager.getAppLogger().logMessage(severity, __FILE__, __LINE__, message);*/

#define APPLOGA(severity)\
    mLogManager.getAppLogger().getStream(severity, __FILE__, __LINE__)

#define APPLOGE(severity)\
    mLogManager.getEventLogger().getStream(severity, __FILE__, __LINE__)

#define APPLOGS(severity)\
    mLogManager.getStatLogger().getStream(severity, __FILE__, __LINE__)

/*************************************************************************
 * \brief Macro use by all classes (except Application) to log messages
 *        in app.log
 *************************************************************************/
#define LOGA(severity, message)\
    mApp->getLogManager().getAppLogger().logMessage(severity, __FILE__, __LINE__, message);

/*************************************************************************
 * \brief Macro use by all classes (except Application) to log messages
 *        in event.log
 *************************************************************************/
#define LOGE(severity, message)\
    mApp->getLogManager().getEventLogger().logMessage(severity, __FILE__, __LINE__, message);

/*************************************************************************
 * \brief Macro use by all classes (except Application) to log event
 *        messages in stat.log
 *************************************************************************/
#define LOGS(severity, message)\
    mApp->getLogManager().getStatLogger().logMessage(severity, __FILE__, __LINE__, message);

#endif // LOGMACRO_HPP_INCLUDED
