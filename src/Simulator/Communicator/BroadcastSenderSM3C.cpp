#include <BroadcastSenderSM3C.h>

BroadcastSenderSM3C::BroadcastSenderSM3C()
{
    this->udpSocket_ = new QUdpSocket(this);
}

BroadcastSenderSM3C::~BroadcastSenderSM3C()
{
    printf("Destroy BroadcastSenderSM3C\n");
    if(this->udpSocket_ != nullptr)
    {
        delete this->udpSocket_;
        this->udpSocket_ = nullptr;
    }
}

void BroadcastSenderSM3C::getInforBroadCastSenderSM3C(int port)
{
    this->port_ = port;
}
void BroadcastSenderSM3C::writeDataGram(std::vector<unsigned char> dataFrame)
{
    //dataFrame = {0x01, 0x02, 0x03};
    //printf("broadcast sender: %d\n", dataFrame.size());
    QByteArray* dataGram_ = new QByteArray(reinterpret_cast<const char*>(dataFrame.data()), dataFrame.size());
    this->udpSocket_->writeDatagram(dataGram_->data(), QHostAddress::Broadcast, this->port_);
    //printf("send finish\n");
}
