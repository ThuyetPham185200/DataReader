#ifndef TIMERCALLPARSE_H
#define TIMERCALLPARSE_H

#include <QObject>
#include <vector>
#include <iostream>
#include <memory>
#include <QTimer>
#include <TTimer.h>
#include <TypeChecker.h>

class CalcTimeStamp
{
public:
    CalcTimeStamp();
    ~CalcTimeStamp();
    int calcTimeStamp(std::vector<unsigned char> vecTimeStampFirst, std::vector<unsigned char> vecTimeStampSecond, std::vector<unsigned char> vecTimeStampThird, TypeChecker::enumLengthBuff checkRecord);
    uint64_t hexToUint64(std::vector <unsigned char> data);

    void setIsFirstEntry();
private:
    bool firstEntryFirst_;
    bool firstEntrySecond_;
    bool firstEntryThird_;
    uint64_t timeStampCurrentFirst_ ;
    uint64_t timeStampPreviousFirst_ ;
    uint64_t timeStampCurrentSecond_ ;
    uint64_t timeStampPreviousSecond_ ;
    uint64_t timeStampCurrentThird_ ;
    uint64_t timeStampPreviousThird_ ;
};

#endif // TIMERCALLPARSE_H
