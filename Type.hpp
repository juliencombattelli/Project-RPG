#ifndef TYPE_HPP_INCLUDED
#define TYPE_HPP_INCLUDED

#include "LogMacro.hpp"

#include <boost/signals2.hpp>
#include <string>
#include <iostream>
#include <fstream>

#define public_slot public
#define protected_slot protected
#define private_slot private

#define INFO_LEVEL   0  ///< Defines the value for GQE::SeverityInfo
#define WARN_LEVEL   1  ///< Defines the value for GQE::SeverityWarning
#define ERROR_LEVEL  2  ///< Defines the value for GQE::SeverityError
#define FATAL_LEVEL  3  ///< Defines the value for GQE::Severity
#define NO_LOG_LEVEL 4  ///< Defines the value for no logging

namespace rpg
{

enum StateID
{
    MENU = 0,
    EXPLORATION = 10,
    COMBAT = 25
};

enum StatusType
{
    StatusAppMissingAsset   = -4,  ///< Application failed due to missing asset file
    StatusAppStackEmpty     = -3,  ///< Application States stack is empty
    StatusAppInitFailed     = -2,  ///< Application initialization failed
    StatusError             = -1,  ///< General error status response
    StatusNoError           =  0,  ///< General no error status response
    StatusAppOK             =  0,  ///< Application quit without error
    StatusOK                =  1   ///< OK status response
};

enum SeverityType
{
    // Logger severity types range from 0 to 5
    SeverityInfo          = INFO_LEVEL,   ///< Informational severity type
    SeverityWarning       = WARN_LEVEL,   ///< Warning severity type
    SeverityError         = ERROR_LEVEL,  ///< Error severity type
    SeverityFatal         = FATAL_LEVEL   ///< Fatal severity type
};

typedef boost::signals2::signal< void (int, std::string) > signal_t;
typedef boost::signals2::connection                        connection_t;


}

#endif // TYPE_HPP_INCLUDED
