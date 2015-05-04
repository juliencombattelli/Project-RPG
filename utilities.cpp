#include "utilities.hpp"
#include <cstring>
#include <Winsock2.h> // htonl()

std::string utility::readString(const uint8_t buffer[], size_t position, size_t maxStringLength)
{
    // '\0' detection in buffer
    for(size_t i=position ; i < position+maxStringLength ; ++i)
        if(buffer[i]==0x00)
            return std::string(reinterpret_cast<const char*>(&buffer[position]), i-position);

    // missing '\0' in buffer
    return std::string("");
}

uint8_t utility::read1Byte(const uint8_t buffer[], size_t position)
{
    return buffer[position];
}

uint16_t utility::read2Byte(const uint8_t buffer[], size_t position)
{
    if ( htonl(0xA5) == 0xA5 ) // Big endian
    {
        return buffer[position+1]<<8 | buffer[position];
    }
    else // Little endian.
    {
        return buffer[position]<<8 | buffer[position+1];
    }
}

uint32_t utility::read4Byte(const uint8_t buffer[], size_t position)
{
    if ( htonl(0xA5) == 0xA5 ) // Big endian
    {
        return buffer[position+3]<<24 | buffer[position+2]<<16 | buffer[position+1]<<8 | buffer[position];
    }
    else // Little endian.
    {
        return buffer[position]<<24 | buffer[position+1]<<16 | buffer[position+2]<<8 | buffer[position+3];
    }
}

uint64_t utility::read8Byte(const uint8_t buffer[], size_t position)
{
    if ( htonl(0xA5) == 0xA5 ) // Big endian
    {
        return buffer[position+7]<<56 | buffer[position+6]<<48 | buffer[position+5]<<40 | buffer[position+4]<<32 |
               buffer[position+3]<<24 | buffer[position+2]<<16 | buffer[position+1]<<8  | buffer[position  ];
    }
    else // Little endian.
    {
        return buffer[position  ]<<56 | buffer[position+1]<<48 | buffer[position+2]<<40 | buffer[position+3]<<32 |
               buffer[position+4]<<24 | buffer[position+5]<<16 | buffer[position+6]<<8  | buffer[position+7];
    }
}
