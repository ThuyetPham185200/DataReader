#ifndef TTOOLBOX_H
#define TTOOLBOX_H

#include <QObject>
#include <TQApplication.h>


class TQApplication;
class Simulator;
class TToolBox : public QObject {
    Q_OBJECT
public:
    TToolBox(TQApplication *app);
    ~TToolBox();

     Simulator       *simulator          () { return  simulator_;       }
private:
    void setChildToolboxes(void);
    Simulator       *simulator_         = nullptr;
    friend class TQApplication;
};

class TTool : public QObject {
    Q_OBJECT

public:
    // All tools must be parented to the QDTToolbox and go through a two phase creation. In the constructor the toolbox
    // should only be passed to QDTTool constructor for correct parenting. It should not be referenced or set in the
    // protected member. Then in the second phase of setToolbox calls is where you can reference the toolbox.
    TTool(TQApplication *app, TToolBox *toolbox);

    // If you override this method, you must call the base class.
    virtual void setToolbox(TToolBox *toolbox);

protected:
    TQApplication *app_;
    TToolBox     *toolbox_;
};
#endif // TTOOLBOX_H
