#ifndef PARSEDATA_H
#define PARSEDATA_H


#include <QObject>
#include <iostream>
#include <memory>
#include <vector>
#include "DataParser.h"
#include <CRLDataLoader.h>
static const int LENGTH_VEC_TIMESTAMP = 8;
static const int NUM_DATATYPE  = 2;

class CRLDataParser : public DataParser
{
public:
    CRLDataParser();
    ~CRLDataParser();
    std::vector<unsigned char> parseData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord) override;
    std::vector<unsigned char> getVecTimeStampFirst() const;
    std::vector<unsigned char> getVecTimeStampSecond() const;
    std::vector<unsigned char> getVecTimeStampThird() const;
private:
    std::vector <unsigned char> vecTimeStampFirst_;
    std::vector <unsigned char> vecTimeStampSecond_;
    std::vector <unsigned char> vecTimeStampThird_;
};

#endif // PARSEDATA_H
