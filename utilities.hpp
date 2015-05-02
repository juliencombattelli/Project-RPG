#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

std::string cstr2string(uint8_t* cstr, size_t beginIterator, size_t stringLenght)
{
    std::string returnedString("");
    size_t iterator;

    for(iterator = beginIterator; iterator < (stringLenght+beginIterator); ++iterator) // end of string detection
        if(cstr[iterator]==0x00)
            break;

    size_t stringSize = iterator-beginIterator;

    returnedString.assign( &(cstr[beginIterator]), stringSize);

    return returnedString;
}

#endif // UTILITIES_HPP_INCLUDED
