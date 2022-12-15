#include "CalcTimeStamp.h"

static const uint64_t INIT_TIMESTAMP = 1;
static const int MIN_TIMECYCLE = 0;
static const int MAX_TIMECYCLE = 2000;
static const bool ISFIRST_ENTRY = true;
CalcTimeStamp::CalcTimeStamp()
{
    this->firstEntryFirst_ = true;
    this->firstEntrySecond_ = true;
    this->firstEntryThird_ = true;
}


CalcTimeStamp::~CalcTimeStamp()
{
    printf("Destroy timer\n");
    //if(timer_ != nullptr) delete timer_;
}

int CalcTimeStamp::calcTimeStamp(std::vector<unsigned char> vecTimeStampFirst,
                              std::vector<unsigned char> vecTimeStampSecond,
                              std::vector<unsigned char> vecTimeStampThird, TypeChecker::enumLengthBuff checkRecord)
{
    if(checkRecord == TypeChecker::enumLengthBuff::LengthFirst)
    {
        //printf("calc time stamp 1\n");
        if(this->firstEntryFirst_)
        {
            this->timeStampCurrentFirst_ = hexToUint64(vecTimeStampFirst);
            this->timeStampPreviousFirst_ = hexToUint64(vecTimeStampFirst);
            printf("first time stamp: %d\n",INIT_TIMESTAMP);
            this->firstEntryFirst_ = false;
            return INIT_TIMESTAMP;
        }
        else
        {
            this->timeStampPreviousFirst_ = this->timeStampCurrentFirst_;
            this->timeStampCurrentFirst_ = hexToUint64(vecTimeStampFirst);
            printf("time stamp: %d\n",(int)(this->timeStampCurrentFirst_ - this->timeStampPreviousFirst_));
            if((int)(this->timeStampCurrentFirst_ - this->timeStampPreviousFirst_) < MIN_TIMECYCLE
            && (int)(this->timeStampCurrentFirst_ - this->timeStampPreviousFirst_)  > MAX_TIMECYCLE) return INIT_TIMESTAMP;
            else return (int)(this->timeStampCurrentFirst_ - this->timeStampPreviousFirst_);
        }
    }
    else if(checkRecord == TypeChecker::enumLengthBuff::LengthSecond)
    {
        //printf("calc time stamp 2\n");
        if(this->firstEntrySecond_)
        {
            this->timeStampCurrentSecond_ = hexToUint64(vecTimeStampSecond);
            this->timeStampPreviousSecond_ = hexToUint64(vecTimeStampSecond);
            printf("time stamp: %d\n",INIT_TIMESTAMP);
            this->firstEntrySecond_ = false;
            return INIT_TIMESTAMP;
        }
        else
        {
            this->timeStampPreviousSecond_ = this->timeStampCurrentSecond_;
            this->timeStampCurrentSecond_ = hexToUint64(vecTimeStampSecond);
            printf("time stamp: %d\n",(int)(this->timeStampCurrentSecond_ - this->timeStampPreviousSecond_));
            if((int)(this->timeStampCurrentSecond_ - this->timeStampPreviousSecond_) < MIN_TIMECYCLE
            && (int)(this->timeStampCurrentSecond_ - this->timeStampPreviousSecond_) > MAX_TIMECYCLE) return INIT_TIMESTAMP;
            else return (int)(this->timeStampCurrentSecond_ - this->timeStampPreviousSecond_);
        }
    }
    else if(checkRecord == TypeChecker::enumLengthBuff::LengthThird)
    {
        printf("calc time stamp 3\n");
        if(this->firstEntryThird_)
        {
            this->timeStampCurrentThird_ = hexToUint64(vecTimeStampThird);
            this->timeStampPreviousThird_ = hexToUint64(vecTimeStampThird);
            printf("time stamp: %d\n",INIT_TIMESTAMP);
            this->firstEntryThird_ = false;
            return INIT_TIMESTAMP;
        }
        else
        {
            this->timeStampPreviousThird_ = this->timeStampCurrentThird_;
            this->timeStampCurrentThird_ = hexToUint64(vecTimeStampThird);
            printf("time stamp: %d\n",(int)(this->timeStampCurrentThird_ - this->timeStampPreviousThird_));
            if((int)(this->timeStampCurrentThird_ - this->timeStampPreviousThird_) < MIN_TIMECYCLE
            && (int)(this->timeStampCurrentThird_ - this->timeStampPreviousThird_) > MAX_TIMECYCLE) return INIT_TIMESTAMP;
            else return (int)(this->timeStampCurrentThird_ - this->timeStampPreviousThird_);
        }
    }
}

uint64_t CalcTimeStamp::hexToUint64(std::vector <unsigned char> data)
{
    uint64_t num = 0;
    for (int32_t i = 0; i < 8; i++) {
        num = (num << 8) + (data[i] & 0xFF);
    }
    return num;
}

void CalcTimeStamp::setIsFirstEntry()
{
    std::cout << "is first entry" << std::endl;
    this->firstEntryFirst_ = ISFIRST_ENTRY;
    this->firstEntrySecond_ = ISFIRST_ENTRY;
    this->firstEntryThird_ = ISFIRST_ENTRY;
}



