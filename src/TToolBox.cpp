#include "TToolBox.h"
#include <Simulator.h>

TToolBox::TToolBox(TQApplication *app) {
    simulator_       = new Simulator(app, this);
}

TToolBox::~TToolBox()
{

}

void TToolBox::setChildToolboxes(void) {
    simulator_->setToolbox(this);
}

TTool::TTool(TQApplication *app, TToolBox *toolbox)
    : QObject   (toolbox)
    , app_      (app)
    , toolbox_  (nullptr) {
}

void TTool::setToolbox(TToolBox *toolbox) {
    toolbox_ = toolbox;
}
