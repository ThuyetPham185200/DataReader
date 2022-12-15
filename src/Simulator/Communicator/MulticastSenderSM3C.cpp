#include <MulticastSenderSM3C.h>

MulticastSenderSM3C::MulticastSenderSM3C()
{
    this->udpSocket_ = new QUdpSocket(this);
}
MulticastSenderSM3C::~MulticastSenderSM3C()
{
    printf("Destroy MulticastSenderSM3C\n");
    if(this->udpSocket_ != nullptr)
    {
        delete this->udpSocket_;
        this->udpSocket_ = nullptr;
    }
}

void MulticastSenderSM3C::getInforMulticastSenderSM3C(QString ip, int port)
{
    this->ip_ = ip;
    this->port_ = port;
    std::cout << this->ip_.toStdString() << std::endl;
    std::cout << this->port_ << std::endl;
    this->groupAddress_ = QHostAddress(this->ip_);
}
void MulticastSenderSM3C::writeDataGram(std::vector<unsigned char> dataFrame)
{
    QByteArray* dataGram_ = new QByteArray(reinterpret_cast<const char*>(dataFrame.data()), dataFrame.size());
    this->udpSocket_->writeDatagram(dataGram_->data(), dataGram_->size(),
                             this->groupAddress_, this->port_);
}
