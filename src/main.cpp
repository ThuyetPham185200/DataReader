#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <TQApplication.h>
#include <RunGuard.h>
#include <QMessageBox>
#include <TypeChecker.h>
#include "Simulator.h"
#include "DataDecoder.h"
#include "DataProcessor.h"
#include "Communicator.h"

int main(int argc, char *argv[])
{
    RunGuard guard("IIRSeekerGM");
    if (!guard.tryToRun()) {
        //QApplication is necessary to use QMessageBox
        QApplication errorApp(argc, argv);
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("An other instance of %1 is already running. "
                        "Please close the other instance and try again.").arg("QDT_APPLICATION_NAME")
        );
        return -1;
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    TQApplication *app = new TQApplication(argc,argv);
    Q_CHECK_PTR(app);
    app->initCommon();


//    app->initForNormalApp();
    if (!app->initForNormalApp()) {
        return -1;
    }
    int exitCode = 0;
    exitCode = app->exec();
    app->shutdown();
    delete app;
    return exitCode;
}
