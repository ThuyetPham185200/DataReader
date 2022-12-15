#include "QDTQmlGlobal.h"

QDTQmlGlobal::QDTQmlGlobal(TQApplication *app, TToolBox *toolbox)
    : TTool               (app, toolbox) {
    // We clear the parent on this object since we run into shutdown problems caused by hybrid qml app. Instead we let it leak on shutdown.
    setParent(nullptr);
}

QDTQmlGlobal::~QDTQmlGlobal() {
}

void QDTQmlGlobal::setToolbox(TToolBox *toolbox) {
    TTool::setToolbox(toolbox);
    simulator_    = toolbox->simulator();
}
