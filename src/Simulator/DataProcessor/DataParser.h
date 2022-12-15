#ifndef PARSEDATAPARENT_H
#define PARSEDATAPARENT_H

#include <iostream>
#include <vector>
#include <TypeChecker.h>
class DataParser
{
public:
    DataParser();
    ~DataParser();
    virtual std::vector<unsigned char> parseData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord) {}
};

#endif // PARSEDATAPARENT_H
