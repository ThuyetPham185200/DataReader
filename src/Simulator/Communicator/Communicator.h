#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <QObject>
#include <TypeChecker.h>
#include <MulticastSenderSM3C.h>
#include <BroadcastSenderSM3C.h>


class Communicator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ipToQML READ ipToQML WRITE setIpToQML NOTIFY ipToQMLChanged)
    Q_PROPERTY(int portToQML READ portToQML WRITE setPortToQML NOTIFY portToQMLChanged)
    Q_PROPERTY(TypeChecker::enumTypeCommu typeOfCommu READ typeOfCommu
               WRITE setTypeOfCommu NOTIFY typeOfCommuChanged)
public:
    Communicator(QObject *parent = nullptr);
    ~Communicator();

    static void initQML();

    void sendData(std::vector<unsigned char> dataFrame);
    void getInforCommu();

    QString ipToQML() const;
    void setIpToQML(QString);

    int portToQML() const;
    void setPortToQML(int);

    TypeChecker::enumTypeCommu typeOfCommu() const ;
    void setTypeOfCommu(TypeChecker::enumTypeCommu typeOfCommu);
signals:
     void ipToQMLChanged();
     void portToQMLChanged();
     void typeOfCommuChanged();

private:
    QString ip_;
    int port_;
    TypeChecker::enumTypeCommu typeOfCommu_;
    std::shared_ptr<MulticastSenderSM3C> multicastSenderSM3C_ = nullptr;
    std::shared_ptr<BroadcastSenderSM3C> broadcastSenderSM3C_ = nullptr;
};

#endif // COMMUNICATOR_H
