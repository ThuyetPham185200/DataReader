#include "DataLoader.h"

DataLoader::DataLoader()
{

}

DataLoader::~DataLoader()
{

}

bool DataLoader::getIsEndFile()
{
    return this->isEndFile_;
}

bool DataLoader::isEndFileToQML() const
{
    return this->isEndFile_;
}

void DataLoader::setIsEndFileToQML(bool pData)
{
    this->isEndFile_ = pData;
    emit isEndFileToQMLChanged();
}

