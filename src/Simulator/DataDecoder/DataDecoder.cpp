#include "DataDecoder.h"
#include <QtQml>
#include <QMetaType>
DataDecoder::DataDecoder(QObject *parent)
    : QObject(parent)
{
    std::cout << "DataDecoder" << std::endl;
    this->CRLDataLoader_ = std::make_shared<CRLDataLoader>();
    this->KLVDataLoader_ = std::make_shared<KLVDataLoader>();
}

DataDecoder::~DataDecoder()
{
    std::cout << "~DataDecoder" << std::endl;
}

void DataDecoder::initQML()
{
    qmlRegisterUncreatableType<DataDecoder>("TApplication", 1, 0, "DataDecoder" ,"Don't care about it");
    qRegisterMetaType<DataDecoder*>("const DataDecoder*");
}

void DataDecoder::getInforDecoder(TypeChecker::enumTypeData checkData)
{
    if(checkData == TypeChecker::enumTypeData::CRL)
    {
        this->CRLDataLoader_->getCRLPathFile(this->pathOfFile_);
    }
    else if(checkData == TypeChecker::enumTypeData::KLV)
    {
        this->KLVDataLoader_->getKLVPathFile(this->pathOfFile_);
    }
}

std::vector<unsigned char> DataDecoder::DecodeData(TypeChecker::enumTypeData checkData)
{
    if(checkData == TypeChecker::enumTypeData::CRL)
    {
        return this->CRLDataLoader_->loadFile();
    }
    else if(checkData == TypeChecker::enumTypeData::KLV)
    {
        return this->KLVDataLoader_->loadFile();
    }
}

bool DataDecoder::checkEndFile(TypeChecker::enumTypeData checkData)
{
    if(checkData == TypeChecker::enumTypeData::CRL)
    {
        return this->CRLDataLoader_->getIsEndFile();
    }
    else if(checkData == TypeChecker::enumTypeData::KLV)
    {
        return this->KLVDataLoader_->getIsEndFile();
    }
}

void DataDecoder::setPathOfFileToQML(QString pData) {
    this->pathOfFile_ = pData;
    emit pathOfFileToQMLChanged();
}

QString DataDecoder::pathOfFileToQML() const {
    return this->pathOfFile_;
}
