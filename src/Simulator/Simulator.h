#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <memory>
#include <TTimer.h>
#include <QtQml>
#include <QMetaType>
#include "Communicator.h"
#include "DataDecoder.h"
#include "DataProcessor.h"
#include <TypeChecker.h>
#include <TToolBox.h>

class TQApplication;
class TToolBox;

class Simulator : public TTool
{
    Q_OBJECT

    Q_PROPERTY(Communicator*    communicator    READ communicator   CONSTANT)
    Q_PROPERTY(DataDecoder*      dataDecoder      READ dataDecoder     CONSTANT)
    Q_PROPERTY(DataProcessor*      dataProcessor      READ dataProcessor     CONSTANT)

    Q_PROPERTY(bool isEndFileToQML READ isEndFileToQML WRITE setIsEndFileToQML NOTIFY isEndFileToQMLChanged)
    Q_PROPERTY(bool isStopToQML READ isStopToQML WRITE setIsStopToQML NOTIFY isStopToQMLChanged)
public:
    Simulator(TQApplication *app, TToolBox *toolbox);
    ~Simulator();

    static void initQML();

    Q_INVOKABLE void connectFunc();
    TypeChecker::enumLengthBuff checkRecord(std::vector <unsigned char> buffer);

    Communicator*   communicator(void) { return communicator_; }
    DataDecoder*     dataDecoder(void) {return dataDecoder_;}
    DataProcessor*     dataProcessor(void) {return dataProcessor_;}

    bool isEndFileToQML() const;
    void setIsEndFileToQML(bool);

    bool isStopToQML() const;
    void setIsStopToQML(bool);

    void    setToolbox  (TToolBox *toolbox);
signals:
    void isFirstEntryChange();
     void isEndFileToQMLChanged();
     void isStopToQMLChanged();
public slots:
     void simulate();

private:
    int count_;
    bool isStop_;
    bool isEndFile_;
    TTimer* timer_;
    Communicator* communicator_;
    DataDecoder* dataDecoder_;
    DataProcessor* dataProcessor_;
};

#endif // SIMULATOR_H
