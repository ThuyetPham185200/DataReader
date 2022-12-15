#include "TQApplication.h"
#include "Simulator.h"
#include "Common.h"
#include "QDTQmlGlobal.h"

TQApplication *TQApplication::app_ = nullptr;

TQApplication::TQApplication(int &argc, char *argv[])
    : QApplication(argc, argv) {
    app_ = this;
    toolbox_ = new TToolBox(this);
    toolbox_->setChildToolboxes();

}

TQApplication::~TQApplication() {
    // Place shutdown code in _shutdown
    app_ = nullptr;
}

// Qml Singleton factories
static QObject *qdtQmlGlobalSingletonFactory(QQmlEngine *, QJSEngine *) {
    // We create this object as a QDTTool even though it isn't in the toolbox
    QDTQmlGlobal *qmlGlobal = new QDTQmlGlobal(qdtApp(), qdtApp()->toolbox());
    qmlGlobal->setToolbox(qdtApp()->toolbox());
    return qmlGlobal;
}

void TQApplication::initCommon() {
    //-------------------------- Register type to "QDTControlSystem" ----------------------------
    // Register Qml Singletons
    qmlRegisterSingletonType<QDTQmlGlobal>("QDTControlSystem", 1, 0, "QDTControlSystem",
                                           qdtQmlGlobalSingletonFactory);
    qmlRegisterType<TypeChecker>("QDTControlSystem", 1, 0, "TypeChecker");
}

bool TQApplication::initForNormalApp() {
    qmlAppEngine_ = new QQmlApplicationEngine(this);
        qmlAppEngine_->addImportPath("qrc:/UI");
    qmlAppEngine_->load(QUrl(QStringLiteral("qrc:/UI/main.qml")));
    return true;
}

void TQApplication::startAutoProcess()
{

}

void TQApplication::shutdown() {
    delete qmlAppEngine_;
    delete toolbox_;
}

/////// @brief Returns the QDTApplication object singleton.
TQApplication *qdtApp(void) { return TQApplication::app_; }

