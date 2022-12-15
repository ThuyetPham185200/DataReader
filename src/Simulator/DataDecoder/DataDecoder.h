#ifndef DATADECODER_H
#define DATADECODER_H
#include <QObject>
#include <TypeChecker.h>
#include <KLVDataLoader.h>
#include <CRLDataLoader.h>

class DataDecoder : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString pathOfFileToQML READ pathOfFileToQML WRITE setPathOfFileToQML NOTIFY pathOfFileToQMLChanged)
public:
    DataDecoder(QObject* parent = nullptr);
    ~DataDecoder();

    static void initQML();

    void getInforDecoder(TypeChecker::enumTypeData checkData);
    Q_INVOKABLE bool checkEndFile(TypeChecker::enumTypeData checkData);
    std::vector<unsigned char> DecodeData(TypeChecker::enumTypeData checkData);
    QString pathOfFileToQML() const;
    void setPathOfFileToQML(QString);
signals:
     void pathOfFileToQMLChanged();

private:
    QString pathOfFile_;
    std::shared_ptr<CRLDataLoader> CRLDataLoader_ = nullptr;
    std::shared_ptr<KLVDataLoader> KLVDataLoader_ = nullptr;
};

#endif // DATADECODER_H
