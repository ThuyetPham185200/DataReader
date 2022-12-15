#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <vector>
#include <iostream>
#include <QObject>
#include <QtNetwork>

class TSocket : public QObject
{
    Q_OBJECT
public:
    TSocket(QObject* parent = nullptr);
    ~TSocket();
    virtual void writeDataGram(std::vector<unsigned char> dataGram) {}
protected:
    int port_;
    QUdpSocket* udpSocket_;
};

#endif // UDPSENDER_H
