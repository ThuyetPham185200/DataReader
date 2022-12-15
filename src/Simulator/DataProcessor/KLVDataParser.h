#ifndef PARSEDATAKLV_H
#define PARSEDATAKLV_H

#include "DataParser.h"
#include <CRLDataParser.h>
class KLVDataParser : public DataParser
{
public:
    KLVDataParser();
    ~KLVDataParser();
    std::vector<unsigned char> parseData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord) override;
    std::vector<unsigned char> getVecTimeStampFirst() const;
    std::vector<unsigned char> getVecTimeStampSecond()const;
    std::vector<unsigned char> getVecTimeStampThird()const;
    int hexToInt(std::vector <unsigned char> data);
private:
    std::vector <unsigned char> vecTimeStampFirst_;
    std::vector <unsigned char> vecTimeStampSecond_;
    std::vector <unsigned char> vecTimeStampThird_;
};

#endif // PARSEDATAKLV_H
