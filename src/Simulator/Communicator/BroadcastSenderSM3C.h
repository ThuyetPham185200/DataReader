#ifndef BROADCASTSENDER_H
#define BROADCASTSENDER_H

#include <TSocket.h>

class BroadcastSenderSM3C : public TSocket
{
public:
    BroadcastSenderSM3C();
    ~BroadcastSenderSM3C();
    void getInforBroadCastSenderSM3C(int port);
    void writeDataGram(std::vector<unsigned char> dataGram) override;
};

#endif // BROADCASTSENDER_H
