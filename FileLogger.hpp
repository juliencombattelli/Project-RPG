#ifndef FILELOGGER_HPP_INCLUDED
#define FILELOGGER_HPP_INCLUDED

#include "onullstream.inl"
#include "Type.hpp"

namespace rpg
{

class FileLogger
{
public:

    FileLogger() = delete;
    FileLogger(const std::string& fileName);
    FileLogger(const FileLogger&) = delete;
    FileLogger& operator=(const FileLogger&) = delete;
    ~FileLogger();

    std::ostream& getStream();
    std::ostream& getStream(SeverityType severity, const char* sourceFile, int sourceLine);
    std::ostream& getStream(SeverityType severity, const char* sourceFile, int sourceLine, const char* message);

    void logMessage(SeverityType severity, const char* message);
    void logMessage(SeverityType severity, const char* sourceFile, int sourceLine, const char* message);

    void writeTag(std::ostream& outStream, SeverityType severity, const char* sourceFile, int sourceLine);

private:

    std::string   mFileName;
    std::ofstream mFileStream;

    static std::onullstream nullStream;
};

}

#endif // FILELOGGER_HPP_INCLUDED
