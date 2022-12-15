#include <KLVDataParser.h>


static const int SIZE_VECTIMESTAMP  = 8;

KLVDataParser::KLVDataParser()
{
    this->vecTimeStampFirst_.resize(SIZE_VECTIMESTAMP);
    this->vecTimeStampSecond_.resize(SIZE_VECTIMESTAMP);
    this->vecTimeStampThird_.resize(SIZE_VECTIMESTAMP);
}

KLVDataParser::~KLVDataParser()
{
    printf("Destroy KLVDataParser\n");
}

std::vector<unsigned char> KLVDataParser::parseData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord)
{
    printf("lenght of buffer in parse KLV: %d\n", buffer.size());
    std::vector <unsigned char> dataFrame_(buffer.size() - NUM_BYTES_CRC);
    printf("lenght of dataFrame: %d\n", dataFrame_.size());
    if(checkRecord == TypeChecker::enumLengthBuff::LengthFirst)
    {
        printf("parse 1\n");
        for (int i = 0; i < buffer.size() - NUM_BYTES_CRC; i++)
        {
            if (i < LENGTH_VEC_TIMESTAMP) vecTimeStampFirst_[i] = buffer[i];
            dataFrame_[i] = buffer[i];
        }
        return dataFrame_;
    }
    else if(checkRecord == TypeChecker::enumLengthBuff::LengthSecond)
    {
        printf("parse 2\n");
        for (int i = 0; i < buffer.size() - NUM_BYTES_CRC; i++)
        {
            if (i < LENGTH_VEC_TIMESTAMP) vecTimeStampSecond_[i] = buffer[i];
            dataFrame_[i] = buffer[i];
        }
        return dataFrame_;
    }
    else if(checkRecord == TypeChecker::enumLengthBuff::LengthThird)
    {
        for (int i = 0; i < buffer.size() - NUM_BYTES_CRC; i++)
        {
            if (i < LENGTH_VEC_TIMESTAMP) vecTimeStampThird_[i] = buffer[i];
            dataFrame_[i] = buffer[i];
        }
        return dataFrame_;
    }
}

std::vector<unsigned char> KLVDataParser::getVecTimeStampFirst() const
{
    return this->vecTimeStampFirst_;
}
std::vector<unsigned char> KLVDataParser::getVecTimeStampSecond() const
{
    return this->vecTimeStampSecond_;
}
std::vector<unsigned char> KLVDataParser::getVecTimeStampThird() const
{
    return this->vecTimeStampThird_;
}

