#ifndef LOADFILE_H
#define LOADFILE_H
#include <QObject>
#include <QtCore>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

static const int MAX_LENGHT_BUFFER = 1400;
static const unsigned char CRC_FRIST = 0x0a;
static const unsigned char CRC_SECOND = 0x0d;
static const int INIT_COUNT = -1;

class DataLoader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isEndFileToQML READ isEndFileToQML WRITE setIsEndFileToQML NOTIFY isEndFileToQMLChanged)
public:
    DataLoader();
    ~DataLoader();
    virtual std::vector <unsigned char> loadFile() {}
    bool getIsEndFile();
    bool isEndFileToQML() const;
    void setIsEndFileToQML(bool);

signals:
     void isEndFileToQMLChanged();
protected:
    bool isEndFile_;
    std::ifstream fileInput_;
    std::streambuf * pbuf_;
};
#endif // LOADFILE_H
