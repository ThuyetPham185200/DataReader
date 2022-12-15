
QT +=   quick \
        core \
        network \
        widgets\

#requires(qtConfig(udpsocket))
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    src \
    src/Common\
    src/Common/TypeChecker \
    src/Common/TTimer \
    src/Simulator\
    src/Simulator/Communicator \
    src/Simulator/DataDecoder \
    src/Simulator/DataProcessor\
    src/QmlControls\

SOURCES += \
    src/QmlControls/QDTQmlGlobal.cpp \
    src/RunGuard.cpp \
    src/Simulator/Communicator/Communicator.cpp \
    src/Simulator/Communicator/MulticastSenderSM3C.cpp \
    src/Simulator/Communicator/BroadcastSenderSM3C.cpp \
    src/Simulator/Communicator/TSocket.cpp \
    src/Simulator/DataDecoder/DataDecoder.cpp \
    src/Simulator/DataProcessor/CRLDataParser.cpp \
    src/Simulator/DataProcessor/KLVDataParser.cpp \
    src/Simulator/DataProcessor/DataProcessor.cpp\
    src/Simulator/DataProcessor/CalcTimeStamp.cpp \
    src/Simulator/DataProcessor/DataParser.cpp \
    src/Simulator/DataDecoder/DataLoader.cpp \
    src/Simulator/DataDecoder/CRLDataLoader.cpp \
    src/Simulator/DataDecoder/KLVDataLoader.cpp \
    src/Common/TTimer/TTimer.cpp \
    src/Common/TypeChecker/TypeChecker.cpp\
    src/Simulator/Simulator.cpp \
    src/TQApplication.cpp \
    src/TToolBox.cpp \
    src/main.cpp \



RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/Common/Common.h \
    src/QmlControls/QDTQmlGlobal.h \
    src/RunGuard.h \
    src/Simulator/Communicator/Communicator.h \
    src/Simulator/Communicator/MulticastSenderSM3C.h \
    src/Simulator/Communicator/BroadcastSenderSM3C.h \
    src/Simulator/Communicator/TSocket.h \
    src/Simulator/DataDecoder/DataDecoder.h \
    src/Simulator/DataProcessor/CRLDataParser.h \
    src/Simulator/DataProcessor/KLVDataParser.h \
    src/Simulator/DataProcessor/DataProcessor.h\
    src/Simulator/DataProcessor/CalcTimeStamp.h \
    src/Simulator/DataProcessor/DataParser.h \
    src/Simulator/DataDecoder/DataLoader.h \
    src/Simulator/DataDecoder/CRLDataLoader.h \
    src/Simulator/DataDecoder/KLVDataLoader.h \
    src/Common/TTimer/TTimer.h \
    src/Common/TypeChecker/TypeChecker.h\
    src/Simulator/Simulator.h \
    src/TQApplication.h \
    src/TToolBox.h \
    src/main.h \

DISTFILES +=





