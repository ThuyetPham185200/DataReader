#include "Communicator.h"
#include <QtQml>
#include <QMetaType>

static const int INIT_LENGTH_DATAFRAME = 0;

Communicator::Communicator(QObject *parent)
    : QObject(parent)
{
    std::cout << "Communicator" << std::endl;
    this->multicastSenderSM3C_ = std::make_shared<MulticastSenderSM3C>();
    this->broadcastSenderSM3C_ = std::make_shared<BroadcastSenderSM3C>();
}

Communicator::~Communicator()
{
    std::cout << "~Communicator" << std::endl;
}

void Communicator::initQML()
{
    qmlRegisterUncreatableType<Communicator>("TApplication", 1, 0, "Communicator" ,"Don't care about it");
    qRegisterMetaType<Communicator*>("const Communicator*");
}

void Communicator::sendData(std::vector<unsigned char> dataFrame)
{
    if(dataFrame.size() == INIT_LENGTH_DATAFRAME);
    else
    {
        if (this->typeOfCommu_ == TypeChecker::enumTypeCommu::Multicast)
        {
            printf("multicast\n");
            this->multicastSenderSM3C_->writeDataGram(dataFrame);
        }
        else if (this->typeOfCommu_ == TypeChecker::enumTypeCommu::Broadcast)
        {
            printf("broadcast\n");
            this->broadcastSenderSM3C_->writeDataGram(dataFrame);
        }
    }
}

void Communicator::getInforCommu()
{
    if (this->typeOfCommu_ == TypeChecker::enumTypeCommu::Multicast)
    {
        std::cout << "multicast\n";
        this->multicastSenderSM3C_->getInforMulticastSenderSM3C(this->ip_, this->port_);
    }
    else if (this->typeOfCommu_ == TypeChecker::enumTypeCommu::Broadcast)
    {
        std::cout << "broadcast\n";
        this->broadcastSenderSM3C_->getInforBroadCastSenderSM3C(this->port_);
    }
}

void Communicator::setIpToQML(QString pData) {
    this->ip_ = pData;
    emit ipToQMLChanged();
}

QString Communicator::ipToQML() const {
    return this->ip_;
}

void Communicator::setPortToQML(int pData) {
    this->port_ = pData;
    emit portToQMLChanged();
}
int Communicator::portToQML() const {
    return this->port_;
}

TypeChecker::enumTypeCommu Communicator::typeOfCommu() const {
    std::cout << "commu type: " << int(typeOfCommu_) << std::endl;
    return typeOfCommu_;
}
void Communicator::setTypeOfCommu(TypeChecker::enumTypeCommu typeOfCommu) {
    if (typeOfCommu_ != typeOfCommu) {
        typeOfCommu_ = typeOfCommu;
        emit typeOfCommuChanged();
    }
}
