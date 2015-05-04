#ifndef IBFSTREAM_HPP_INCLUDED
#define IBFSTREAM_HPP_INCLUDED

#include <string>
#include <fstream>

namespace utility
{

class ibfstream
{
public:

    explicit ibfstream(const std::string& file);

    bool   isOpen() const;
    void   read(uint8_t buffer[], size_t bufferSize);
    size_t getFileLength();
    void   seekg(std::streampos position);
    void   seekg(std::streamoff off, std::ios_base::seekdir way);
    void   close();

private:

    std::ifstream mIfstream;
} ;

}



#endif // IBFSTREAM_HPP_INCLUDED
