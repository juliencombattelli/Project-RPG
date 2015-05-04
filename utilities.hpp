#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

#include <string>
#include "ibfstream.hpp"

namespace utility
{

std::string readString(const uint8_t buffer[], size_t position, size_t maxStringLength);
uint8_t     read1Byte(const uint8_t buffer[], size_t position);
uint16_t    read2Byte(const uint8_t buffer[], size_t position);
uint32_t    read4Byte(const uint8_t buffer[], size_t position);
uint64_t    read8Byte(const uint8_t buffer[], size_t position);

}




#endif // UTILITIES_HPP_INCLUDED
