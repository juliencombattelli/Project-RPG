#include "FileLogger.hpp"
#include <ctime>

namespace rpg
{

std::onullstream FileLogger::nullStream;

FileLogger::FileLogger(const std::string& fileName) : mFileName(fileName), mFileStream(fileName)
{
    if(mFileStream.is_open())
        logMessage(SeverityInfo, __FILE__, __LINE__, "FileLogger::ctor()");
}

FileLogger::~FileLogger()
{
    if(mFileStream.is_open())
    {
        logMessage(SeverityInfo, __FILE__, __LINE__, "FileLogger::dtor()");
        mFileStream.close();
    }
}

std::ostream& FileLogger::getStream()
{
    std::ostream* result = &nullStream;
    if(mFileStream.is_open())
        result = &mFileStream;
    return *result;
}

std::ostream& FileLogger::getStream(SeverityType severity, const char* sourceFile, int sourceLine)
{
    std::ostream* result = &nullStream;
    if(mFileStream.is_open())
    {
        writeTag(mFileStream, severity, sourceFile, sourceLine);
        result = &mFileStream;
    }
    return *result;
}

std::ostream& FileLogger::getStream(SeverityType severity, const char* sourceFile, int sourceLine, const char* message)
{
    std::ostream* result = &nullStream;
    if(mFileStream.is_open())
    {
        writeTag(mFileStream, severity, sourceFile, sourceLine);
        logMessage(severity, sourceFile, sourceLine, message);
        result = &mFileStream;
    }
    return *result;
}

void FileLogger::logMessage(SeverityType severity, const char* message)
{
    if(mFileStream.is_open())
    {
        writeTag(mFileStream, severity, __FILE__ , __LINE__);
        mFileStream << message << std::endl << std::endl;
    }
}

void FileLogger::logMessage(SeverityType severity, const char* sourceFile, int sourceLine, const char* message)
{
    if(mFileStream.is_open())
    {
        writeTag(mFileStream, severity, sourceFile, sourceLine);
        mFileStream << message << std::endl << std::endl;
    }
}

void FileLogger::writeTag(std::ostream& outStream, SeverityType severity, const char* sourceFile, int sourceLine)
{
    const struct std::tm* timeStruct;
    std::time_t now;

    now = std::time(nullptr);

    timeStruct = std::localtime(&now);

    outStream << timeStruct->tm_year + 1900 << "-";
    outStream.fill('0');
    outStream.width(2);
    outStream << timeStruct->tm_mon + 1 << "-";
    outStream.fill('0');
    outStream.width(2);
    outStream << timeStruct->tm_mday << " ";
    outStream.fill('0');
    outStream.width(2);
    outStream << timeStruct->tm_hour + 1 << ":";
    outStream.fill('0');
    outStream.width(2);
    outStream << timeStruct->tm_min << ":";
    outStream.fill('0');
    outStream.width(2);
    outStream << timeStruct->tm_sec << " ";

    switch(severity)
    {
    case SeverityInfo:
        outStream << "Information :";
        break;
    case SeverityWarning:
        outStream << "Warning     :";
        break;
    case SeverityError:
        outStream << "Error       :";
        break;
    case SeverityFatal:
        outStream << "Fatal error :";
        break;
    default:
        outStream << "Unknown     :";
        break;
    }
    outStream << " " << sourceFile << " : line " << sourceLine << " ";
}

}
