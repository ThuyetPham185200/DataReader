#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include <QObject>
#include "CRLDataParser.h"
#include "KLVDataParser.h"
#include "CalcTimeStamp.h"
#include <TypeChecker.h>


class DataProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TypeChecker::enumTypeData typeOfData READ typeOfData
               WRITE setTypeOfData NOTIFY typeOfDataChanged)
public:
    DataProcessor(QObject* parent = nullptr);
    ~DataProcessor();

    static void initQML();

    TypeChecker::enumTypeData typeOfData() const ;
    void setTypeOfData(TypeChecker::enumTypeData typeOfData);
    std::vector<unsigned char> processData(std::vector<unsigned char> buffer, TypeChecker::enumLengthBuff checkRecord);
    uint64_t calcTimeCycle(TypeChecker::enumLengthBuff);
signals:
    void typeOfDataChanged();
public slots:
    void setIsFirstEntry();
private:
    TypeChecker::enumTypeData typeOfData_;
    std::shared_ptr<CalcTimeStamp> calcTimeStamp_ = nullptr;
    std::shared_ptr<CRLDataParser> CRLDataParser_ = nullptr;
    std::shared_ptr<KLVDataParser> KLVDataParser_ = nullptr;
};

#endif // DATAPROCESSOR_H
