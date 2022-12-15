#ifndef QDTQMLGLOBAL_H
#define QDTQMLGLOBAL_H

#include "TToolBox.h"
#include "TQApplication.h"

class QDTQmlGlobal : public TTool {
    Q_OBJECT

public:
    QDTQmlGlobal(TQApplication *app, TToolBox *toolbox);
    ~QDTQmlGlobal();

    Q_PROPERTY(Simulator            *simulator_              READ simulator              CONSTANT)

    // Property accesors
    Simulator           *simulator          ()  { return simulator_;            }

    // Overrides from QDTTool
    virtual void setToolbox(TToolBox *toolbox);

private:
    Simulator           *simulator_             = nullptr;
};

#endif // QDTQMLGLOBAL_H
