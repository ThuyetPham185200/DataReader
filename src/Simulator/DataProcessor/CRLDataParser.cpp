#include <CRLDataParser.h>
#include <chrono>


CRLDataParser::CRLDataParser()
{
    this->vecTimeStampFirst_.resize(LENGTH_VEC_TIMESTAMP);
    this->vecTimeStampSecond_.resize(LENGTH_VEC_TIMESTAMP);
    this->vecTimeStampThird_.resize(LENGTH_VEC_TIMESTAMP);
}

CRLDataParser::~CRLDataParser()
{
    printf("Destroy CRLDataParser\n");
}

std::vector<unsigned char> CRLDataParser::parseData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord)
{
    if(buffer.size() == 0)
    {
        std::vector <unsigned char> dataFrame_(0);
        return dataFrame_;
    }
    else
    {
        std::vector <unsigned char> dataFrame_(buffer.size() - NUM_BYTES_CRC);
        //printf("lenght of dataFrame: %d\n", dataFrame_.size());
        if(checkRecord == TypeChecker::enumLengthBuff::LengthFirst)
        {
            //printf("parse 1\n");
            for (int i = 0; i < buffer.size() - NUM_BYTES_CRC; i++)
            {
                if (i < LENGTH_VEC_TIMESTAMP) vecTimeStampFirst_[i] = buffer[i];
                dataFrame_[i] = buffer[i];
            }
            return dataFrame_;
        }
        else if(checkRecord == TypeChecker::enumLengthBuff::LengthSecond)
        {
            //printf("parse 2\n");
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
        else
        {
            dataFrame_.resize(0);
            return dataFrame_;
        }
    }

}

std::vector<unsigned char> CRLDataParser::getVecTimeStampFirst() const
{
    return this->vecTimeStampFirst_;
}
std::vector<unsigned char> CRLDataParser::getVecTimeStampSecond() const
{
    return this->vecTimeStampSecond_;
}
std::vector<unsigned char> CRLDataParser::getVecTimeStampThird() const
{
    return this->vecTimeStampThird_;
}

