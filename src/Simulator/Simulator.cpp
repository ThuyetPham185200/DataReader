#include "Simulator.h"



static const int LENGHT_BUFFER_FIRST = 430;
static const int LENGHT_BUFFER_SECOND = 1310;
static const int LENGHT_BUFFER_THIRD = 1400;
static const int COUNT_INIT = 0;

Simulator::Simulator(TQApplication *app, TToolBox *toolbox)
    : TTool(app, toolbox)
    , dataDecoder_(nullptr)
    , dataProcessor_(nullptr)
    , communicator_(nullptr)
{
    this->count_ = 0;
    this->timer_ = new TTimer;
    this->isEndFile_ = false;
    this->isStop_ = false;
    dataDecoder_ = new DataDecoder;
    dataProcessor_ = new DataProcessor;
    communicator_ = new Communicator;
}

Simulator::~Simulator()
{
      std::cout << "~Simulator"<<std::endl;
      delete dataDecoder_;
      delete dataProcessor_;
      delete communicator_;
}


void Simulator::simulate()
{
    if(!isStop_)
    {
        count_ ++;
        std::vector<unsigned char> buffer_ = this->dataDecoder_->DecodeData(TypeChecker::enumTypeData::CRL);
        //std::cout << "\nloaded: " << count_  << " with length of buffer: " << buffer_.size()<<std::endl;
        TypeChecker::enumLengthBuff check_ = this->checkRecord(buffer_);
        buffer_ = this->dataProcessor_->processData(buffer_, check_);
        this->communicator_->sendData(buffer_);
        int timeStamp_ = this->dataProcessor_->calcTimeCycle(check_);
        this->timer_->start(timeStamp_);
        if(this->dataDecoder_->checkEndFile(TypeChecker::enumTypeData::CRL))
        {
            this->isEndFile_ = this->dataDecoder_->checkEndFile(TypeChecker::enumTypeData::CRL);
            emit this->isEndFileToQMLChanged();
            this->timer_->stop();
        }
    }
    else
    {
        this->timer_->stop();
        emit this->isFirstEntryChange();
    }
}

void Simulator::connectFunc()
{
    this->dataDecoder_->getInforDecoder(TypeChecker::enumTypeData::CRL);
    this->communicator_->getInforCommu();
    //std::cout << "start connecting" << std::endl;
    if (count_ == COUNT_INIT)
    {
        //std::cout << "init timer" << std::endl;
        connect(this, SIGNAL(isFirstEntryChange()), this->dataProcessor_, SLOT(setIsFirstEntry()));
        connect(this->timer_, SIGNAL(timeout()), this, SLOT(simulate()));
    }
    //std::cout << "connecting" << std::endl;
    this->timer_->start();
    //std::cout << "connected" << std::endl;
    count_ = 1;
}

TypeChecker::enumLengthBuff Simulator::checkRecord(std::vector <unsigned char> buffer)
{
    if(buffer.size() == LENGHT_BUFFER_FIRST) return TypeChecker::enumLengthBuff::LengthFirst;
    else if(buffer.size() == LENGHT_BUFFER_SECOND) return TypeChecker::enumLengthBuff::LengthSecond;
    else if(buffer.size() == LENGHT_BUFFER_THIRD) return TypeChecker::enumLengthBuff::LengthThird;
}

void Simulator::setIsEndFileToQML(bool pData)
{
    this->isEndFile_ = pData;
    emit isEndFileToQMLChanged();
}

bool Simulator::isEndFileToQML() const {
    return this->isEndFile_;
}

void Simulator::setIsStopToQML(bool pData)
{
    this->isStop_ = pData;
    emit isStopToQMLChanged();
}

void Simulator::setToolbox(TToolBox *toolbox)
{
    TTool::setToolbox(toolbox);
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    qmlRegisterUncreatableType<Simulator>("TApplication", 1, 0, "Simulator", "not load Simulator");

    qmlRegisterUncreatableType<DataProcessor>("TApplication", 1, 0, "DataProcessor" ,"not load DataProcessor");
    qmlRegisterUncreatableType<Communicator>("TApplication", 1, 0, "Communicator" ,"not load Communicator");
    qmlRegisterUncreatableType<DataDecoder>("TApplication", 1, 0, "DataDecoder" ,"not load DataDecoder");
}

bool Simulator::isStopToQML() const
{
    return this->isStop_;
}



