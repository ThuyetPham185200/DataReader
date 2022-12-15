#ifndef MULTICASTSENDERSM3C_H
#define MULTICASTSENDERSM3C_H
#include <TSocket.h>

class MulticastSenderSM3C : public TSocket
{
public:
    MulticastSenderSM3C();
    ~MulticastSenderSM3C();
    void getInforMulticastSenderSM3C(QString ip, int port);
    void writeDataGram(std::vector<unsigned char> dataGram) override;
private:
    QString ip_;
    QHostAddress groupAddress_;
};

#endif // MULTICASTSENDERSM3C_H
