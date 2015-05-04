#include "ibfstream.hpp"

utility::ibfstream::ibfstream(const std::string& file) : mIfstream( file , std::ios::in | std::ios::binary )
{

}

bool utility::ibfstream::isOpen() const
{
    return mIfstream.is_open();
}

void utility::ibfstream::read(uint8_t buffer[], size_t bufferSize)
{
    mIfstream.read(reinterpret_cast<char*>(buffer), bufferSize);
}

size_t utility::ibfstream::getFileLength()
{
    mIfstream.seekg (0, mIfstream.end);
    size_t length = mIfstream.tellg();
    mIfstream.seekg (0, mIfstream.beg);

    return length;
}

void utility::ibfstream::seekg(std::streampos position)
{
    mIfstream.seekg(position);
}

void utility::ibfstream::seekg(std::streamoff off, std::ios_base::seekdir way)
{
    mIfstream.seekg(off, way);
}

void utility::ibfstream::close()
{
    mIfstream.close();
}
