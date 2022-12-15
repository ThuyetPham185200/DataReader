#include "DataProcessor.h"
#include <QtQml>
#include <QMetaType>

DataProcessor::DataProcessor(QObject* parent)
    : QObject(parent)
{
    std::cout << "DataProcessor" << std::endl;
    this->CRLDataParser_ = std::make_shared<CRLDataParser>();
    this->KLVDataParser_ = std::make_shared<KLVDataParser>();
    this->calcTimeStamp_ = std::make_shared<CalcTimeStamp>();
}

DataProcessor::~DataProcessor()
{
    std::cout << "~DataProcessor" << std::endl;
}

void DataProcessor::initQML()
{
    qmlRegisterUncreatableType<DataProcessor>("TApplication", 1, 0, "DataProcessor" ,"Don't care about it");
    qRegisterMetaType<DataProcessor*>("const DataProcessor*");
}

std::vector<unsigned char> DataProcessor::processData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord)
{
    std::vector<unsigned char> dataFrame_;

    if (typeOfData_ == TypeChecker::enumTypeData::CRL)
    {
        //printf("pasing crl\n");
        dataFrame_ = std::move(this->CRLDataParser_->parseData(buffer, checkRecord));
    }
    else if (typeOfData_ == TypeChecker::enumTypeData::KLV)
    {
        //printf("pasing klv\n");
        dataFrame_ = std::move(this->CRLDataParser_->parseData(buffer, checkRecord));
    }
    return dataFrame_;
}

uint64_t DataProcessor::calcTimeCycle(TypeChecker::enumLengthBuff checkRecord)
{
    if (this->typeOfData_ == TypeChecker::enumTypeData::CRL)
    {
        return this->calcTimeStamp_->calcTimeStamp(this->CRLDataParser_->getVecTimeStampFirst() ,
                                                  this->CRLDataParser_->getVecTimeStampSecond(),
                                                  this->CRLDataParser_->getVecTimeStampThird(), checkRecord);
    }
    else if (this->typeOfData_ == TypeChecker::enumTypeData::KLV)
    {
        return this->calcTimeStamp_->calcTimeStamp(this->KLVDataParser_->getVecTimeStampFirst() ,
                                                  this->KLVDataParser_->getVecTimeStampSecond(),
                                                  this->KLVDataParser_->getVecTimeStampThird(), checkRecord);
    }
}

void DataProcessor::setIsFirstEntry()
{
    this->calcTimeStamp_->setIsFirstEntry();
}

TypeChecker::enumTypeData DataProcessor::typeOfData() const {
    std::cout << "data type: " << int(typeOfData_) << std::endl;
    return typeOfData_;
}
void DataProcessor::setTypeOfData(TypeChecker::enumTypeData typeOfData) {
    if (typeOfData_ != typeOfData) {
        typeOfData_ = typeOfData;
        emit typeOfDataChanged();
    }
}
